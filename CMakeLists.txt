cmake_minimum_required(VERSION 3.11)

project(coatl LANGUAGES C)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_INSTALL_PREFIX}/cmake ${CMAKE_CURRENT_LIST_DIR}/../lib)

find_package(colibri REQUIRED)
find_package(mpir 2.6.0 REQUIRED)
find_package(PicoTest REQUIRED)

# CoATL library
add_library(coatl SHARED)
target_compile_definitions(coatl
	PRIVATE BUILD_coatl
)
target_include_directories(coatl
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include/coatl>
)
target_sources(coatl
	PRIVATE
		coatl.c
		coatlUcd.c
		coatlUnicode.c
		coatlRegexp.c
		re/regcomp.c
		re/regexec.c
		re/regfree.c
		re/regerror.c
		coatlNumber.c
		coatlJson.c
		coatlParse.c
		coatlParseTcl.c
)
target_link_libraries(coatl
	PUBLIC
		colibri
	PRIVATE
		mpir
)
install(TARGETS coatl EXPORT coatl-config
	RUNTIME DESTINATION bin/${CMAKE_BUILD_TYPE}
	ARCHIVE DESTINATION lib/${CMAKE_BUILD_TYPE}
	LIBRARY DESTINATION lib/${CMAKE_BUILD_TYPE}/static
)
install(DIRECTORY include/ DESTINATION include/coatl)
install(EXPORT coatl-config DESTINATION cmake)
install(FILES $<TARGET_FILE:mpir> DESTINATION bin/${CMAKE_BUILD_TYPE})


# CoATL unit tests
add_executable(test_coatl)
target_sources(test_coatl
	PRIVATE
		tests/testCoatl.c
		tests/testUnicode.c
		tests/testRegexp.c
		tests/testNumber.c
		tests/testJson.c
)
target_link_libraries(test_coatl
	PRIVATE
		colibri
		coatl
		PicoTest
)
install(TARGETS test_coatl EXPORT test_coatl
	RUNTIME DESTINATION bin/${CMAKE_BUILD_TYPE}
)

# Copy test_coatl dependencies to target dir before running 
# picotest_discover_tests
add_custom_command(TARGET test_coatl POST_BUILD
	COMMAND 
		${CMAKE_COMMAND} -E copy_if_different
		$<TARGET_FILE:colibri>
		$<TARGET_FILE_DIR:test_coatl>
	COMMAND 
		${CMAKE_COMMAND} -E copy_if_different
		$<TARGET_FILE:mpir>
		$<TARGET_FILE_DIR:test_coatl>
)

enable_testing()
picotest_discover_tests(test_coatl
	TEST_LIST_OPTION "-l"
)
