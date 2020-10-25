add_test(
    NAME "test_parsing/y_array_arraysWithSpaces"
    COMMAND test_coatl_json "test_parsing/y_array_arraysWithSpaces.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_array_empty"
    COMMAND test_coatl_json "test_parsing/y_array_empty.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_array_empty-string"
    COMMAND test_coatl_json "test_parsing/y_array_empty-string.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_array_ending_with_newline"
    COMMAND test_coatl_json "test_parsing/y_array_ending_with_newline.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_array_false"
    COMMAND test_coatl_json "test_parsing/y_array_false.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_array_heterogeneous"
    COMMAND test_coatl_json "test_parsing/y_array_heterogeneous.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_array_null"
    COMMAND test_coatl_json "test_parsing/y_array_null.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_array_with_1_and_newline"
    COMMAND test_coatl_json "test_parsing/y_array_with_1_and_newline.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_array_with_leading_space"
    COMMAND test_coatl_json "test_parsing/y_array_with_leading_space.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_array_with_several_null"
    COMMAND test_coatl_json "test_parsing/y_array_with_several_null.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_array_with_trailing_space"
    COMMAND test_coatl_json "test_parsing/y_array_with_trailing_space.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_number"
    COMMAND test_coatl_json "test_parsing/y_number.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_number_0e+1"
    COMMAND test_coatl_json "test_parsing/y_number_0e+1.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_number_0e1"
    COMMAND test_coatl_json "test_parsing/y_number_0e1.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_number_after_space"
    COMMAND test_coatl_json "test_parsing/y_number_after_space.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_number_double_close_to_zero"
    COMMAND test_coatl_json "test_parsing/y_number_double_close_to_zero.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_number_int_with_exp"
    COMMAND test_coatl_json "test_parsing/y_number_int_with_exp.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_number_minus_zero"
    COMMAND test_coatl_json "test_parsing/y_number_minus_zero.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_number_negative_int"
    COMMAND test_coatl_json "test_parsing/y_number_negative_int.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_number_negative_one"
    COMMAND test_coatl_json "test_parsing/y_number_negative_one.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_number_negative_zero"
    COMMAND test_coatl_json "test_parsing/y_number_negative_zero.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_number_real_capital_e"
    COMMAND test_coatl_json "test_parsing/y_number_real_capital_e.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_number_real_capital_e_neg_exp"
    COMMAND test_coatl_json "test_parsing/y_number_real_capital_e_neg_exp.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_number_real_capital_e_pos_exp"
    COMMAND test_coatl_json "test_parsing/y_number_real_capital_e_pos_exp.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_number_real_exponent"
    COMMAND test_coatl_json "test_parsing/y_number_real_exponent.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_number_real_fraction_exponent"
    COMMAND test_coatl_json "test_parsing/y_number_real_fraction_exponent.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_number_real_neg_exp"
    COMMAND test_coatl_json "test_parsing/y_number_real_neg_exp.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_number_real_pos_exponent"
    COMMAND test_coatl_json "test_parsing/y_number_real_pos_exponent.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_number_simple_int"
    COMMAND test_coatl_json "test_parsing/y_number_simple_int.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_number_simple_real"
    COMMAND test_coatl_json "test_parsing/y_number_simple_real.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_object"
    COMMAND test_coatl_json "test_parsing/y_object.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_object_basic"
    COMMAND test_coatl_json "test_parsing/y_object_basic.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_object_duplicated_key"
    COMMAND test_coatl_json "test_parsing/y_object_duplicated_key.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_object_duplicated_key_and_value"
    COMMAND test_coatl_json "test_parsing/y_object_duplicated_key_and_value.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_object_empty"
    COMMAND test_coatl_json "test_parsing/y_object_empty.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_object_empty_key"
    COMMAND test_coatl_json "test_parsing/y_object_empty_key.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_object_escaped_null_in_key"
    COMMAND test_coatl_json "test_parsing/y_object_escaped_null_in_key.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_object_extreme_numbers"
    COMMAND test_coatl_json "test_parsing/y_object_extreme_numbers.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_object_long_strings"
    COMMAND test_coatl_json "test_parsing/y_object_long_strings.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_object_simple"
    COMMAND test_coatl_json "test_parsing/y_object_simple.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_object_string_unicode"
    COMMAND test_coatl_json "test_parsing/y_object_string_unicode.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_object_with_newlines"
    COMMAND test_coatl_json "test_parsing/y_object_with_newlines.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_1_2_3_bytes_UTF-8_sequences"
    COMMAND test_coatl_json "test_parsing/y_string_1_2_3_bytes_UTF-8_sequences.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_accepted_surrogate_pair"
    COMMAND test_coatl_json "test_parsing/y_string_accepted_surrogate_pair.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_accepted_surrogate_pairs"
    COMMAND test_coatl_json "test_parsing/y_string_accepted_surrogate_pairs.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_allowed_escapes"
    COMMAND test_coatl_json "test_parsing/y_string_allowed_escapes.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_backslash_and_u_escaped_zero"
    COMMAND test_coatl_json "test_parsing/y_string_backslash_and_u_escaped_zero.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_backslash_doublequotes"
    COMMAND test_coatl_json "test_parsing/y_string_backslash_doublequotes.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_comments"
    COMMAND test_coatl_json "test_parsing/y_string_comments.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_double_escape_a"
    COMMAND test_coatl_json "test_parsing/y_string_double_escape_a.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_double_escape_n"
    COMMAND test_coatl_json "test_parsing/y_string_double_escape_n.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_escaped_control_character"
    COMMAND test_coatl_json "test_parsing/y_string_escaped_control_character.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_escaped_noncharacter"
    COMMAND test_coatl_json "test_parsing/y_string_escaped_noncharacter.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_in_array"
    COMMAND test_coatl_json "test_parsing/y_string_in_array.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_in_array_with_leading_space"
    COMMAND test_coatl_json "test_parsing/y_string_in_array_with_leading_space.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_last_surrogates_1_and_2"
    COMMAND test_coatl_json "test_parsing/y_string_last_surrogates_1_and_2.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_nbsp_uescaped"
    COMMAND test_coatl_json "test_parsing/y_string_nbsp_uescaped.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_nonCharacterInUTF-8_U+10FFFF"
    COMMAND test_coatl_json "test_parsing/y_string_nonCharacterInUTF-8_U+10FFFF.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_nonCharacterInUTF-8_U+FFFF"
    COMMAND test_coatl_json "test_parsing/y_string_nonCharacterInUTF-8_U+FFFF.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_null_escape"
    COMMAND test_coatl_json "test_parsing/y_string_null_escape.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_one-byte-utf-8"
    COMMAND test_coatl_json "test_parsing/y_string_one-byte-utf-8.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_pi"
    COMMAND test_coatl_json "test_parsing/y_string_pi.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_reservedCharacterInUTF-8_U+1BFFF"
    COMMAND test_coatl_json "test_parsing/y_string_reservedCharacterInUTF-8_U+1BFFF.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_simple_ascii"
    COMMAND test_coatl_json "test_parsing/y_string_simple_ascii.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_space"
    COMMAND test_coatl_json "test_parsing/y_string_space.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_surrogates_U+1D11E_MUSICAL_SYMBOL_G_CLEF"
    COMMAND test_coatl_json "test_parsing/y_string_surrogates_U+1D11E_MUSICAL_SYMBOL_G_CLEF.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_three-byte-utf-8"
    COMMAND test_coatl_json "test_parsing/y_string_three-byte-utf-8.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_two-byte-utf-8"
    COMMAND test_coatl_json "test_parsing/y_string_two-byte-utf-8.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_u+2028_line_sep"
    COMMAND test_coatl_json "test_parsing/y_string_u+2028_line_sep.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_u+2029_par_sep"
    COMMAND test_coatl_json "test_parsing/y_string_u+2029_par_sep.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_uEscape"
    COMMAND test_coatl_json "test_parsing/y_string_uEscape.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_uescaped_newline"
    COMMAND test_coatl_json "test_parsing/y_string_uescaped_newline.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_unescaped_char_delete"
    COMMAND test_coatl_json "test_parsing/y_string_unescaped_char_delete.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_unicode"
    COMMAND test_coatl_json "test_parsing/y_string_unicode.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_unicode_2"
    COMMAND test_coatl_json "test_parsing/y_string_unicode_2.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_unicode_escaped_double_quote"
    COMMAND test_coatl_json "test_parsing/y_string_unicode_escaped_double_quote.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_unicode_U+10FFFE_nonchar"
    COMMAND test_coatl_json "test_parsing/y_string_unicode_U+10FFFE_nonchar.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_unicode_U+1FFFE_nonchar"
    COMMAND test_coatl_json "test_parsing/y_string_unicode_U+1FFFE_nonchar.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_unicode_U+200B_ZERO_WIDTH_SPACE"
    COMMAND test_coatl_json "test_parsing/y_string_unicode_U+200B_ZERO_WIDTH_SPACE.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_unicode_U+2064_invisible_plus"
    COMMAND test_coatl_json "test_parsing/y_string_unicode_U+2064_invisible_plus.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_unicode_U+FDD0_nonchar"
    COMMAND test_coatl_json "test_parsing/y_string_unicode_U+FDD0_nonchar.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_unicode_U+FFFE_nonchar"
    COMMAND test_coatl_json "test_parsing/y_string_unicode_U+FFFE_nonchar.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_unicodeEscapedBackslash"
    COMMAND test_coatl_json "test_parsing/y_string_unicodeEscapedBackslash.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_utf8"
    COMMAND test_coatl_json "test_parsing/y_string_utf8.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_string_with_del_character"
    COMMAND test_coatl_json "test_parsing/y_string_with_del_character.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_structure_lonely_false"
    COMMAND test_coatl_json "test_parsing/y_structure_lonely_false.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_structure_lonely_int"
    COMMAND test_coatl_json "test_parsing/y_structure_lonely_int.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_structure_lonely_negative_real"
    COMMAND test_coatl_json "test_parsing/y_structure_lonely_negative_real.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_structure_lonely_null"
    COMMAND test_coatl_json "test_parsing/y_structure_lonely_null.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_structure_lonely_string"
    COMMAND test_coatl_json "test_parsing/y_structure_lonely_string.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_structure_lonely_true"
    COMMAND test_coatl_json "test_parsing/y_structure_lonely_true.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_structure_string_empty"
    COMMAND test_coatl_json "test_parsing/y_structure_string_empty.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_structure_trailing_newline"
    COMMAND test_coatl_json "test_parsing/y_structure_trailing_newline.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_structure_true_in_array"
    COMMAND test_coatl_json "test_parsing/y_structure_true_in_array.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
add_test(
    NAME "test_parsing/y_structure_whitespace_array"
    COMMAND test_coatl_json "test_parsing/y_structure_whitespace_array.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
