add_test(
    NAME "test_transform/number_1.0.json"
    COMMAND test_coatl_json "test_transform/number_1.0.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_transform/number_1.000000000000000005.json"
    COMMAND test_coatl_json "test_transform/number_1.000000000000000005.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_transform/number_1000000000000000.json"
    COMMAND test_coatl_json "test_transform/number_1000000000000000.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_transform/number_10000000000000000999.json"
    COMMAND test_coatl_json "test_transform/number_10000000000000000999.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_transform/number_1e6.json"
    COMMAND test_coatl_json "test_transform/number_1e6.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_transform/number_1e-999.json"
    COMMAND test_coatl_json "test_transform/number_1e-999.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_transform/number_9223372036854775807.json"
    COMMAND test_coatl_json "test_transform/number_9223372036854775807.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_transform/number_9223372036854775808.json"
    COMMAND test_coatl_json "test_transform/number_9223372036854775808.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_transform/number_-9223372036854775808.json"
    COMMAND test_coatl_json "test_transform/number_-9223372036854775808.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_transform/number_-9223372036854775809.json"
    COMMAND test_coatl_json "test_transform/number_-9223372036854775809.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_transform/object_key_nfc_nfd.json"
    COMMAND test_coatl_json "test_transform/object_key_nfc_nfd.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_transform/object_key_nfd_nfc.json"
    COMMAND test_coatl_json "test_transform/object_key_nfd_nfc.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_transform/object_same_key_different_values.json"
    COMMAND test_coatl_json "test_transform/object_same_key_different_values.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_transform/object_same_key_same_value.json"
    COMMAND test_coatl_json "test_transform/object_same_key_same_value.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_transform/object_same_key_unclear_values.json"
    COMMAND test_coatl_json "test_transform/object_same_key_unclear_values.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_transform/string_1_escaped_invalid_codepoint.json"
    COMMAND test_coatl_json "test_transform/string_1_escaped_invalid_codepoint.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_transform/string_1_invalid_codepoint.json"
    COMMAND test_coatl_json "test_transform/string_1_invalid_codepoint.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_transform/string_2_escaped_invalid_codepoints.json"
    COMMAND test_coatl_json "test_transform/string_2_escaped_invalid_codepoints.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_transform/string_2_invalid_codepoints.json"
    COMMAND test_coatl_json "test_transform/string_2_invalid_codepoints.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_transform/string_3_escaped_invalid_codepoints.json"
    COMMAND test_coatl_json "test_transform/string_3_escaped_invalid_codepoints.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_transform/string_3_invalid_codepoints.json"
    COMMAND test_coatl_json "test_transform/string_3_invalid_codepoints.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_transform/string_with_escaped_NULL.json"
    COMMAND test_coatl_json "test_transform/string_with_escaped_NULL.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
