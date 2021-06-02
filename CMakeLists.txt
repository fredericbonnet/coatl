cmake_minimum_required(VERSION 3.11)

project(coatl LANGUAGES C)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_INSTALL_PREFIX}/cmake ${CMAKE_CURRENT_LIST_DIR}/../lib)

find_package(colibri REQUIRED)
find_package(mpir 3.0.0 REQUIRED)
find_package(PicoTest)

# CoATL library
add_library(coatl)
target_compile_definitions(coatl
	PRIVATE BUILD_coatl
)
if (NOT BUILD_SHARED_LIBS)
	target_compile_definitions(coatl
		PUBLIC COATL_STATIC_BUILD
	)
endif()
target_include_directories(coatl
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include/coatl>
)
target_sources(coatl
	PRIVATE
		src/coatl.c
		src/coatlUcd.c
		src/coatlUnicode.c
		src/coatlRegexp.c
		src/re/regcomp.c
		src/re/regexec.c
		src/re/regfree.c
		src/re/regerror.c
		src/coatlNumber.c
		src/coatlJson.c
		src/coatlParse.c
		src/coatlParseTcl.c
)
target_link_libraries(coatl
	PUBLIC
		colibri
	PRIVATE
		mpir::mpir
)

install(TARGETS coatl EXPORT coatl-config)
install(DIRECTORY include/ DESTINATION include/coatl)
install(EXPORT coatl-config DESTINATION cmake)
if (WIN32)
	# Copy binary dependencies as well
	install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin/mpir/ DESTINATION bin)
endif()


enable_testing()
if (WIN32)
	# Copy test dependencies to target dir before building/running tests
	add_custom_command(TARGET coatl POST_BUILD
		COMMAND 
			${CMAKE_COMMAND} -E copy_if_different
			$<TARGET_FILE:colibri>
			$<TARGET_FILE_DIR:coatl>
		COMMAND 
			${CMAKE_COMMAND} -E copy_directory
			${CMAKE_CURRENT_BINARY_DIR}/bin/mpir
			$<TARGET_FILE_DIR:coatl>
	)
endif()

# CoATL unit tests
if (PicoTest_FOUND)
	# TDD tests
	add_executable(tdd_coatl)
	target_sources(tdd_coatl
		PRIVATE
			tests/tdd/main.c
			tests/tdd/json.c
			tests/tdd/traverse.c
			tests/tdd/hooks.c
			tests/tdd/errors.c
			tests/tdd/testNumbers.c
			tests/tdd/testUnicode.c
	)
	target_link_libraries(tdd_coatl
		PRIVATE
			colibri
			coatl
			PicoTest
	)
	install(TARGETS tdd_coatl EXPORT tdd_coatl
		RUNTIME DESTINATION bin/${CMAKE_BUILD_TYPE}
	)

	# Historic tests
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

	picotest_discover_tests(test_coatl
		TEST_LIST_OPTION "-l"
	)
endif()

# JSON Parsing Test Suite
add_executable(test_coatl_json)
target_sources(test_coatl_json
	PRIVATE
		tests/json/main.c
)
target_link_libraries(test_coatl_json
	PRIVATE
		colibri
		coatl
)
install(TARGETS test_coatl_json EXPORT test_coatl_json
	RUNTIME DESTINATION bin/${CMAKE_BUILD_TYPE}
)
include(tests/json/testJson.cmake)