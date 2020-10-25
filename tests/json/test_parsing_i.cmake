add_test(
    NAME "test_parsing/i_number_double_huge_neg_exp"
    COMMAND test_coatl_json "test_parsing/i_number_double_huge_neg_exp.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_number_huge_exp"
    COMMAND test_coatl_json "test_parsing/i_number_huge_exp.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_number_neg_int_huge_exp"
    COMMAND test_coatl_json "test_parsing/i_number_neg_int_huge_exp.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_number_pos_double_huge_exp"
    COMMAND test_coatl_json "test_parsing/i_number_pos_double_huge_exp.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_number_real_neg_overflow"
    COMMAND test_coatl_json "test_parsing/i_number_real_neg_overflow.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_number_real_pos_overflow"
    COMMAND test_coatl_json "test_parsing/i_number_real_pos_overflow.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_number_real_underflow"
    COMMAND test_coatl_json "test_parsing/i_number_real_underflow.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_number_too_big_neg_int"
    COMMAND test_coatl_json "test_parsing/i_number_too_big_neg_int.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_number_too_big_pos_int"
    COMMAND test_coatl_json "test_parsing/i_number_too_big_pos_int.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_number_very_big_negative_int"
    COMMAND test_coatl_json "test_parsing/i_number_very_big_negative_int.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_object_key_lone_2nd_surrogate"
    COMMAND test_coatl_json "test_parsing/i_object_key_lone_2nd_surrogate.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_string_1st_surrogate_but_2nd_missing"
    COMMAND test_coatl_json "test_parsing/i_string_1st_surrogate_but_2nd_missing.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_string_1st_valid_surrogate_2nd_invalid"
    COMMAND test_coatl_json "test_parsing/i_string_1st_valid_surrogate_2nd_invalid.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_string_incomplete_surrogate_and_escape_valid"
    COMMAND test_coatl_json "test_parsing/i_string_incomplete_surrogate_and_escape_valid.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_string_incomplete_surrogate_pair"
    COMMAND test_coatl_json "test_parsing/i_string_incomplete_surrogate_pair.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_string_incomplete_surrogates_escape_valid"
    COMMAND test_coatl_json "test_parsing/i_string_incomplete_surrogates_escape_valid.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_string_invalid_lonely_surrogate"
    COMMAND test_coatl_json "test_parsing/i_string_invalid_lonely_surrogate.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_string_invalid_surrogate"
    COMMAND test_coatl_json "test_parsing/i_string_invalid_surrogate.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_string_invalid_utf-8"
    COMMAND test_coatl_json "test_parsing/i_string_invalid_utf-8.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_string_inverted_surrogates_U+1D11E"
    COMMAND test_coatl_json "test_parsing/i_string_inverted_surrogates_U+1D11E.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_string_iso_latin_1"
    COMMAND test_coatl_json "test_parsing/i_string_iso_latin_1.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_string_lone_second_surrogate"
    COMMAND test_coatl_json "test_parsing/i_string_lone_second_surrogate.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_string_lone_utf8_continuation_byte"
    COMMAND test_coatl_json "test_parsing/i_string_lone_utf8_continuation_byte.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_string_not_in_unicode_range"
    COMMAND test_coatl_json "test_parsing/i_string_not_in_unicode_range.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_string_overlong_sequence_2_bytes"
    COMMAND test_coatl_json "test_parsing/i_string_overlong_sequence_2_bytes.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_string_overlong_sequence_6_bytes"
    COMMAND test_coatl_json "test_parsing/i_string_overlong_sequence_6_bytes.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_string_overlong_sequence_6_bytes_null"
    COMMAND test_coatl_json "test_parsing/i_string_overlong_sequence_6_bytes_null.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_string_truncated-utf-8"
    COMMAND test_coatl_json "test_parsing/i_string_truncated-utf-8.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_string_utf16BE_no_BOM"
    COMMAND test_coatl_json "test_parsing/i_string_utf16BE_no_BOM.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_string_utf16LE_no_BOM"
    COMMAND test_coatl_json "test_parsing/i_string_utf16LE_no_BOM.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_string_UTF-16LE_with_BOM"
    COMMAND test_coatl_json "test_parsing/i_string_UTF-16LE_with_BOM.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_string_UTF-8_invalid_sequence"
    COMMAND test_coatl_json "test_parsing/i_string_UTF-8_invalid_sequence.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_string_UTF8_surrogate_U+D800"
    COMMAND test_coatl_json "test_parsing/i_string_UTF8_surrogate_U+D800.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_structure_500_nested_arrays"
    COMMAND test_coatl_json "test_parsing/i_structure_500_nested_arrays.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/i_structure_UTF-8_BOM_empty_object"
    COMMAND test_coatl_json "test_parsing/i_structure_UTF-8_BOM_empty_object.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
