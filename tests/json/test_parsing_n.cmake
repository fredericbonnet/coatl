add_test(
    NAME "test_parsing/n_array_1_true_without_comma"
    COMMAND test_coatl_json "test_parsing/n_array_1_true_without_comma.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_1_true_without_comma" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_a_invalid_utf8"
    COMMAND test_coatl_json "test_parsing/n_array_a_invalid_utf8.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_a_invalid_utf8" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_colon_instead_of_comma"
    COMMAND test_coatl_json "test_parsing/n_array_colon_instead_of_comma.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_colon_instead_of_comma" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_comma_after_close"
    COMMAND test_coatl_json "test_parsing/n_array_comma_after_close.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_comma_after_close" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_comma_and_number"
    COMMAND test_coatl_json "test_parsing/n_array_comma_and_number.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_comma_and_number" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_double_comma"
    COMMAND test_coatl_json "test_parsing/n_array_double_comma.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_double_comma" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_double_extra_comma"
    COMMAND test_coatl_json "test_parsing/n_array_double_extra_comma.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_double_extra_comma" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_extra_close"
    COMMAND test_coatl_json "test_parsing/n_array_extra_close.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_extra_close" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_extra_comma"
    COMMAND test_coatl_json "test_parsing/n_array_extra_comma.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_extra_comma" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_incomplete"
    COMMAND test_coatl_json "test_parsing/n_array_incomplete.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_incomplete" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_incomplete_invalid_value"
    COMMAND test_coatl_json "test_parsing/n_array_incomplete_invalid_value.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_incomplete_invalid_value" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_inner_array_no_comma"
    COMMAND test_coatl_json "test_parsing/n_array_inner_array_no_comma.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_inner_array_no_comma" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_invalid_utf8"
    COMMAND test_coatl_json "test_parsing/n_array_invalid_utf8.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_invalid_utf8" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_items_separated_by_semicolon"
    COMMAND test_coatl_json "test_parsing/n_array_items_separated_by_semicolon.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_items_separated_by_semicolon" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_just_comma"
    COMMAND test_coatl_json "test_parsing/n_array_just_comma.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_just_comma" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_just_minus"
    COMMAND test_coatl_json "test_parsing/n_array_just_minus.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_just_minus" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_missing_value"
    COMMAND test_coatl_json "test_parsing/n_array_missing_value.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_missing_value" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_newlines_unclosed"
    COMMAND test_coatl_json "test_parsing/n_array_newlines_unclosed.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_newlines_unclosed" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_number_and_comma"
    COMMAND test_coatl_json "test_parsing/n_array_number_and_comma.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_number_and_comma" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_number_and_several_commas"
    COMMAND test_coatl_json "test_parsing/n_array_number_and_several_commas.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_number_and_several_commas" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_spaces_vertical_tab_formfeed"
    COMMAND test_coatl_json "test_parsing/n_array_spaces_vertical_tab_formfeed.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_spaces_vertical_tab_formfeed" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_star_inside"
    COMMAND test_coatl_json "test_parsing/n_array_star_inside.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_star_inside" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_unclosed"
    COMMAND test_coatl_json "test_parsing/n_array_unclosed.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_unclosed" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_unclosed_trailing_comma"
    COMMAND test_coatl_json "test_parsing/n_array_unclosed_trailing_comma.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_unclosed_trailing_comma" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_unclosed_with_new_lines"
    COMMAND test_coatl_json "test_parsing/n_array_unclosed_with_new_lines.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_unclosed_with_new_lines" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_array_unclosed_with_object_inside"
    COMMAND test_coatl_json "test_parsing/n_array_unclosed_with_object_inside.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_array_unclosed_with_object_inside" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_incomplete_false"
    COMMAND test_coatl_json "test_parsing/n_incomplete_false.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_incomplete_false" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_incomplete_null"
    COMMAND test_coatl_json "test_parsing/n_incomplete_null.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_incomplete_null" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_incomplete_true"
    COMMAND test_coatl_json "test_parsing/n_incomplete_true.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_incomplete_true" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_multidigit_number_then_00"
    COMMAND test_coatl_json "test_parsing/n_multidigit_number_then_00.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_multidigit_number_then_00" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_.-1"
    COMMAND test_coatl_json "test_parsing/n_number_.-1.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_.-1" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_.2e-3"
    COMMAND test_coatl_json "test_parsing/n_number_.2e-3.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_.2e-3" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_++"
    COMMAND test_coatl_json "test_parsing/n_number_++.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_++" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_+1"
    COMMAND test_coatl_json "test_parsing/n_number_+1.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_+1" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_+Inf"
    COMMAND test_coatl_json "test_parsing/n_number_+Inf.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_+Inf" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_0.1.2"
    COMMAND test_coatl_json "test_parsing/n_number_0.1.2.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_0.1.2" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_0.3e"
    COMMAND test_coatl_json "test_parsing/n_number_0.3e.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_0.3e" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_0.3e+"
    COMMAND test_coatl_json "test_parsing/n_number_0.3e+.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_0.3e+" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_0.e1"
    COMMAND test_coatl_json "test_parsing/n_number_0.e1.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_0.e1" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_0_capital_E"
    COMMAND test_coatl_json "test_parsing/n_number_0_capital_E.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_0_capital_E" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_0_capital_E+"
    COMMAND test_coatl_json "test_parsing/n_number_0_capital_E+.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_0_capital_E+" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_-01"
    COMMAND test_coatl_json "test_parsing/n_number_-01.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_-01" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_0e"
    COMMAND test_coatl_json "test_parsing/n_number_0e.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_0e" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_0e+"
    COMMAND test_coatl_json "test_parsing/n_number_0e+.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_0e+" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_-1.0."
    COMMAND test_coatl_json "test_parsing/n_number_-1.0..json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_-1.0." PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_1.0e"
    COMMAND test_coatl_json "test_parsing/n_number_1.0e.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_1.0e" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_1.0e-"
    COMMAND test_coatl_json "test_parsing/n_number_1.0e-.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_1.0e-" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_1.0e+"
    COMMAND test_coatl_json "test_parsing/n_number_1.0e+.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_1.0e+" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_1_000"
    COMMAND test_coatl_json "test_parsing/n_number_1_000.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_1_000" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_1eE2"
    COMMAND test_coatl_json "test_parsing/n_number_1eE2.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_1eE2" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_-2."
    COMMAND test_coatl_json "test_parsing/n_number_-2..json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_-2." PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_2.e+3"
    COMMAND test_coatl_json "test_parsing/n_number_2.e+3.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_2.e+3" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_2.e3"
    COMMAND test_coatl_json "test_parsing/n_number_2.e3.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_2.e3" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_2.e-3"
    COMMAND test_coatl_json "test_parsing/n_number_2.e-3.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_2.e-3" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_9.e+"
    COMMAND test_coatl_json "test_parsing/n_number_9.e+.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_9.e+" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_expression"
    COMMAND test_coatl_json "test_parsing/n_number_expression.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_expression" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_hex_1_digit"
    COMMAND test_coatl_json "test_parsing/n_number_hex_1_digit.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_hex_1_digit" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_hex_2_digits"
    COMMAND test_coatl_json "test_parsing/n_number_hex_2_digits.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_hex_2_digits" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_Inf"
    COMMAND test_coatl_json "test_parsing/n_number_Inf.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_Inf" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_infinity"
    COMMAND test_coatl_json "test_parsing/n_number_infinity.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_infinity" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_invalid+-"
    COMMAND test_coatl_json "test_parsing/n_number_invalid+-.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_invalid+-" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_invalid-negative-real"
    COMMAND test_coatl_json "test_parsing/n_number_invalid-negative-real.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_invalid-negative-real" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_invalid-utf-8-in-bigger-int"
    COMMAND test_coatl_json "test_parsing/n_number_invalid-utf-8-in-bigger-int.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_invalid-utf-8-in-bigger-int" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_invalid-utf-8-in-exponent"
    COMMAND test_coatl_json "test_parsing/n_number_invalid-utf-8-in-exponent.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_invalid-utf-8-in-exponent" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_invalid-utf-8-in-int"
    COMMAND test_coatl_json "test_parsing/n_number_invalid-utf-8-in-int.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_invalid-utf-8-in-int" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_minus_infinity"
    COMMAND test_coatl_json "test_parsing/n_number_minus_infinity.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_minus_infinity" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_minus_sign_with_trailing_garbage"
    COMMAND test_coatl_json "test_parsing/n_number_minus_sign_with_trailing_garbage.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_minus_sign_with_trailing_garbage" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_minus_space_1"
    COMMAND test_coatl_json "test_parsing/n_number_minus_space_1.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_minus_space_1" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_NaN"
    COMMAND test_coatl_json "test_parsing/n_number_NaN.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_NaN" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_-NaN"
    COMMAND test_coatl_json "test_parsing/n_number_-NaN.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_-NaN" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_neg_int_starting_with_zero"
    COMMAND test_coatl_json "test_parsing/n_number_neg_int_starting_with_zero.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_neg_int_starting_with_zero" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_neg_real_without_int_part"
    COMMAND test_coatl_json "test_parsing/n_number_neg_real_without_int_part.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_neg_real_without_int_part" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_neg_with_garbage_at_end"
    COMMAND test_coatl_json "test_parsing/n_number_neg_with_garbage_at_end.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_neg_with_garbage_at_end" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_real_garbage_after_e"
    COMMAND test_coatl_json "test_parsing/n_number_real_garbage_after_e.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_real_garbage_after_e" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_real_with_invalid_utf8_after_e"
    COMMAND test_coatl_json "test_parsing/n_number_real_with_invalid_utf8_after_e.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_real_with_invalid_utf8_after_e" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_real_without_fractional_part"
    COMMAND test_coatl_json "test_parsing/n_number_real_without_fractional_part.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_real_without_fractional_part" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_starting_with_dot"
    COMMAND test_coatl_json "test_parsing/n_number_starting_with_dot.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_starting_with_dot" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_U+FF11_fullwidth_digit_one"
    COMMAND test_coatl_json "test_parsing/n_number_U+FF11_fullwidth_digit_one.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_U+FF11_fullwidth_digit_one" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_with_alpha"
    COMMAND test_coatl_json "test_parsing/n_number_with_alpha.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_with_alpha" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_with_alpha_char"
    COMMAND test_coatl_json "test_parsing/n_number_with_alpha_char.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_with_alpha_char" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_number_with_leading_zero"
    COMMAND test_coatl_json "test_parsing/n_number_with_leading_zero.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_number_with_leading_zero" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_bad_value"
    COMMAND test_coatl_json "test_parsing/n_object_bad_value.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_bad_value" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_bracket_key"
    COMMAND test_coatl_json "test_parsing/n_object_bracket_key.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_bracket_key" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_comma_instead_of_colon"
    COMMAND test_coatl_json "test_parsing/n_object_comma_instead_of_colon.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_comma_instead_of_colon" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_double_colon"
    COMMAND test_coatl_json "test_parsing/n_object_double_colon.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_double_colon" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_emoji"
    COMMAND test_coatl_json "test_parsing/n_object_emoji.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_emoji" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_garbage_at_end"
    COMMAND test_coatl_json "test_parsing/n_object_garbage_at_end.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_garbage_at_end" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_key_with_single_quotes"
    COMMAND test_coatl_json "test_parsing/n_object_key_with_single_quotes.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_key_with_single_quotes" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_lone_continuation_byte_in_key_and_trailing_comma"
    COMMAND test_coatl_json "test_parsing/n_object_lone_continuation_byte_in_key_and_trailing_comma.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_lone_continuation_byte_in_key_and_trailing_comma" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_missing_colon"
    COMMAND test_coatl_json "test_parsing/n_object_missing_colon.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_missing_colon" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_missing_key"
    COMMAND test_coatl_json "test_parsing/n_object_missing_key.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_missing_key" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_missing_semicolon"
    COMMAND test_coatl_json "test_parsing/n_object_missing_semicolon.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_missing_semicolon" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_missing_value"
    COMMAND test_coatl_json "test_parsing/n_object_missing_value.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_missing_value" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_no-colon"
    COMMAND test_coatl_json "test_parsing/n_object_no-colon.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_no-colon" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_non_string_key"
    COMMAND test_coatl_json "test_parsing/n_object_non_string_key.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_non_string_key" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_non_string_key_but_huge_number_instead"
    COMMAND test_coatl_json "test_parsing/n_object_non_string_key_but_huge_number_instead.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_non_string_key_but_huge_number_instead" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_repeated_null_null"
    COMMAND test_coatl_json "test_parsing/n_object_repeated_null_null.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_repeated_null_null" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_several_trailing_commas"
    COMMAND test_coatl_json "test_parsing/n_object_several_trailing_commas.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_several_trailing_commas" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_single_quote"
    COMMAND test_coatl_json "test_parsing/n_object_single_quote.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_single_quote" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_trailing_comma"
    COMMAND test_coatl_json "test_parsing/n_object_trailing_comma.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_trailing_comma" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_trailing_comment"
    COMMAND test_coatl_json "test_parsing/n_object_trailing_comment.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_trailing_comment" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_trailing_comment_open"
    COMMAND test_coatl_json "test_parsing/n_object_trailing_comment_open.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_trailing_comment_open" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_trailing_comment_slash_open"
    COMMAND test_coatl_json "test_parsing/n_object_trailing_comment_slash_open.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_trailing_comment_slash_open" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_trailing_comment_slash_open_incomplete"
    COMMAND test_coatl_json "test_parsing/n_object_trailing_comment_slash_open_incomplete.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_trailing_comment_slash_open_incomplete" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_two_commas_in_a_row"
    COMMAND test_coatl_json "test_parsing/n_object_two_commas_in_a_row.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_two_commas_in_a_row" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_unquoted_key"
    COMMAND test_coatl_json "test_parsing/n_object_unquoted_key.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_unquoted_key" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_unterminated-value"
    COMMAND test_coatl_json "test_parsing/n_object_unterminated-value.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_unterminated-value" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_with_single_string"
    COMMAND test_coatl_json "test_parsing/n_object_with_single_string.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_with_single_string" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_object_with_trailing_garbage"
    COMMAND test_coatl_json "test_parsing/n_object_with_trailing_garbage.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_object_with_trailing_garbage" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_single_space"
    COMMAND test_coatl_json "test_parsing/n_single_space.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_single_space" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_1_surrogate_then_escape"
    COMMAND test_coatl_json "test_parsing/n_string_1_surrogate_then_escape.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_1_surrogate_then_escape" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_1_surrogate_then_escape_u"
    COMMAND test_coatl_json "test_parsing/n_string_1_surrogate_then_escape_u.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_1_surrogate_then_escape_u" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_1_surrogate_then_escape_u1"
    COMMAND test_coatl_json "test_parsing/n_string_1_surrogate_then_escape_u1.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_1_surrogate_then_escape_u1" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_1_surrogate_then_escape_u1x"
    COMMAND test_coatl_json "test_parsing/n_string_1_surrogate_then_escape_u1x.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_1_surrogate_then_escape_u1x" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_accentuated_char_no_quotes"
    COMMAND test_coatl_json "test_parsing/n_string_accentuated_char_no_quotes.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_accentuated_char_no_quotes" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_backslash_00"
    COMMAND test_coatl_json "test_parsing/n_string_backslash_00.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_backslash_00" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_escape_x"
    COMMAND test_coatl_json "test_parsing/n_string_escape_x.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_escape_x" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_escaped_backslash_bad"
    COMMAND test_coatl_json "test_parsing/n_string_escaped_backslash_bad.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_escaped_backslash_bad" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_escaped_ctrl_char_tab"
    COMMAND test_coatl_json "test_parsing/n_string_escaped_ctrl_char_tab.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_escaped_ctrl_char_tab" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_escaped_emoji"
    COMMAND test_coatl_json "test_parsing/n_string_escaped_emoji.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_escaped_emoji" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_incomplete_escape"
    COMMAND test_coatl_json "test_parsing/n_string_incomplete_escape.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_incomplete_escape" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_incomplete_escaped_character"
    COMMAND test_coatl_json "test_parsing/n_string_incomplete_escaped_character.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_incomplete_escaped_character" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_incomplete_surrogate"
    COMMAND test_coatl_json "test_parsing/n_string_incomplete_surrogate.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_incomplete_surrogate" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_incomplete_surrogate_escape_invalid"
    COMMAND test_coatl_json "test_parsing/n_string_incomplete_surrogate_escape_invalid.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_incomplete_surrogate_escape_invalid" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_invalid_backslash_esc"
    COMMAND test_coatl_json "test_parsing/n_string_invalid_backslash_esc.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_invalid_backslash_esc" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_invalid_unicode_escape"
    COMMAND test_coatl_json "test_parsing/n_string_invalid_unicode_escape.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_invalid_unicode_escape" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_invalid_utf8_after_escape"
    COMMAND test_coatl_json "test_parsing/n_string_invalid_utf8_after_escape.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_invalid_utf8_after_escape" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_invalid-utf-8-in-escape"
    COMMAND test_coatl_json "test_parsing/n_string_invalid-utf-8-in-escape.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_invalid-utf-8-in-escape" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_leading_uescaped_thinspace"
    COMMAND test_coatl_json "test_parsing/n_string_leading_uescaped_thinspace.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_leading_uescaped_thinspace" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_no_quotes_with_bad_escape"
    COMMAND test_coatl_json "test_parsing/n_string_no_quotes_with_bad_escape.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_no_quotes_with_bad_escape" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_single_doublequote"
    COMMAND test_coatl_json "test_parsing/n_string_single_doublequote.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_single_doublequote" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_single_quote"
    COMMAND test_coatl_json "test_parsing/n_string_single_quote.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_single_quote" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_single_string_no_double_quotes"
    COMMAND test_coatl_json "test_parsing/n_string_single_string_no_double_quotes.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_single_string_no_double_quotes" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_start_escape_unclosed"
    COMMAND test_coatl_json "test_parsing/n_string_start_escape_unclosed.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_start_escape_unclosed" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_unescaped_ctrl_char"
    COMMAND test_coatl_json "test_parsing/n_string_unescaped_ctrl_char.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_unescaped_ctrl_char" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_unescaped_newline"
    COMMAND test_coatl_json "test_parsing/n_string_unescaped_newline.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_unescaped_newline" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_unescaped_tab"
    COMMAND test_coatl_json "test_parsing/n_string_unescaped_tab.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_unescaped_tab" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_unicode_CapitalU"
    COMMAND test_coatl_json "test_parsing/n_string_unicode_CapitalU.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_unicode_CapitalU" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_string_with_trailing_garbage"
    COMMAND test_coatl_json "test_parsing/n_string_with_trailing_garbage.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_string_with_trailing_garbage" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_100000_opening_arrays"
    COMMAND test_coatl_json "test_parsing/n_structure_100000_opening_arrays.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_100000_opening_arrays" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_angle_bracket_."
    COMMAND test_coatl_json "test_parsing/n_structure_angle_bracket_..json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_angle_bracket_." PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_angle_bracket_null"
    COMMAND test_coatl_json "test_parsing/n_structure_angle_bracket_null.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_angle_bracket_null" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_array_trailing_garbage"
    COMMAND test_coatl_json "test_parsing/n_structure_array_trailing_garbage.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_array_trailing_garbage" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_array_with_extra_array_close"
    COMMAND test_coatl_json "test_parsing/n_structure_array_with_extra_array_close.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_array_with_extra_array_close" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_array_with_unclosed_string"
    COMMAND test_coatl_json "test_parsing/n_structure_array_with_unclosed_string.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_array_with_unclosed_string" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_ascii-unicode-identifier"
    COMMAND test_coatl_json "test_parsing/n_structure_ascii-unicode-identifier.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_ascii-unicode-identifier" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_capitalized_True"
    COMMAND test_coatl_json "test_parsing/n_structure_capitalized_True.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_capitalized_True" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_close_unopened_array"
    COMMAND test_coatl_json "test_parsing/n_structure_close_unopened_array.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_close_unopened_array" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_comma_instead_of_closing_brace"
    COMMAND test_coatl_json "test_parsing/n_structure_comma_instead_of_closing_brace.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_comma_instead_of_closing_brace" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_double_array"
    COMMAND test_coatl_json "test_parsing/n_structure_double_array.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_double_array" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_end_array"
    COMMAND test_coatl_json "test_parsing/n_structure_end_array.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_end_array" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_incomplete_UTF8_BOM"
    COMMAND test_coatl_json "test_parsing/n_structure_incomplete_UTF8_BOM.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_incomplete_UTF8_BOM" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_lone-invalid-utf-8"
    COMMAND test_coatl_json "test_parsing/n_structure_lone-invalid-utf-8.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_lone-invalid-utf-8" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_lone-open-bracket"
    COMMAND test_coatl_json "test_parsing/n_structure_lone-open-bracket.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_lone-open-bracket" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_no_data"
    COMMAND test_coatl_json "test_parsing/n_structure_no_data.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_no_data" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_null-byte-outside-string"
    COMMAND test_coatl_json "test_parsing/n_structure_null-byte-outside-string.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_null-byte-outside-string" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_number_with_trailing_garbage"
    COMMAND test_coatl_json "test_parsing/n_structure_number_with_trailing_garbage.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_number_with_trailing_garbage" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_object_followed_by_closing_object"
    COMMAND test_coatl_json "test_parsing/n_structure_object_followed_by_closing_object.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_object_followed_by_closing_object" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_object_unclosed_no_value"
    COMMAND test_coatl_json "test_parsing/n_structure_object_unclosed_no_value.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_object_unclosed_no_value" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_object_with_comment"
    COMMAND test_coatl_json "test_parsing/n_structure_object_with_comment.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_object_with_comment" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_object_with_trailing_garbage"
    COMMAND test_coatl_json "test_parsing/n_structure_object_with_trailing_garbage.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_object_with_trailing_garbage" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_open_array_apostrophe"
    COMMAND test_coatl_json "test_parsing/n_structure_open_array_apostrophe.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_open_array_apostrophe" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_open_array_comma"
    COMMAND test_coatl_json "test_parsing/n_structure_open_array_comma.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_open_array_comma" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_open_array_object"
    COMMAND test_coatl_json "test_parsing/n_structure_open_array_object.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_open_array_object" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_open_array_open_object"
    COMMAND test_coatl_json "test_parsing/n_structure_open_array_open_object.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_open_array_open_object" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_open_array_open_string"
    COMMAND test_coatl_json "test_parsing/n_structure_open_array_open_string.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_open_array_open_string" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_open_array_string"
    COMMAND test_coatl_json "test_parsing/n_structure_open_array_string.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_open_array_string" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_open_object"
    COMMAND test_coatl_json "test_parsing/n_structure_open_object.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_open_object" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_open_object_close_array"
    COMMAND test_coatl_json "test_parsing/n_structure_open_object_close_array.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_open_object_close_array" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_open_object_comma"
    COMMAND test_coatl_json "test_parsing/n_structure_open_object_comma.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_open_object_comma" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_open_object_open_array"
    COMMAND test_coatl_json "test_parsing/n_structure_open_object_open_array.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_open_object_open_array" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_open_object_open_string"
    COMMAND test_coatl_json "test_parsing/n_structure_open_object_open_string.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_open_object_open_string" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_open_object_string_with_apostrophes"
    COMMAND test_coatl_json "test_parsing/n_structure_open_object_string_with_apostrophes.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_open_object_string_with_apostrophes" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_open_open"
    COMMAND test_coatl_json "test_parsing/n_structure_open_open.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_open_open" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_single_eacute"
    COMMAND test_coatl_json "test_parsing/n_structure_single_eacute.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_single_eacute" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_single_star"
    COMMAND test_coatl_json "test_parsing/n_structure_single_star.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_single_star" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_trailing_\\#"
    COMMAND test_coatl_json "test_parsing/n_structure_trailing_\#.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_trailing_\\#" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_U+2060_word_joined"
    COMMAND test_coatl_json "test_parsing/n_structure_U+2060_word_joined.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_U+2060_word_joined" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_uescaped_LF_before_string"
    COMMAND test_coatl_json "test_parsing/n_structure_uescaped_LF_before_string.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_uescaped_LF_before_string" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_unclosed_array"
    COMMAND test_coatl_json "test_parsing/n_structure_unclosed_array.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_unclosed_array" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_unclosed_array_partial_null"
    COMMAND test_coatl_json "test_parsing/n_structure_unclosed_array_partial_null.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_unclosed_array_partial_null" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_unclosed_array_unfinished_false"
    COMMAND test_coatl_json "test_parsing/n_structure_unclosed_array_unfinished_false.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_unclosed_array_unfinished_false" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_unclosed_array_unfinished_true"
    COMMAND test_coatl_json "test_parsing/n_structure_unclosed_array_unfinished_true.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_unclosed_array_unfinished_true" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_unclosed_object"
    COMMAND test_coatl_json "test_parsing/n_structure_unclosed_object.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_unclosed_object" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_unicode-identifier"
    COMMAND test_coatl_json "test_parsing/n_structure_unicode-identifier.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_unicode-identifier" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_UTF8_BOM_no_data"
    COMMAND test_coatl_json "test_parsing/n_structure_UTF8_BOM_no_data.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_UTF8_BOM_no_data" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_whitespace_formfeed"
    COMMAND test_coatl_json "test_parsing/n_structure_whitespace_formfeed.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_whitespace_formfeed" PROPERTIES WILL_FAIL yes)
add_test(
    NAME "test_parsing/n_structure_whitespace_U+2060_word_joiner"
    COMMAND test_coatl_json "test_parsing/n_structure_whitespace_U+2060_word_joiner.json"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/json
)
set_tests_properties("test_parsing/n_structure_whitespace_U+2060_word_joiner" PROPERTIES WILL_FAIL yes)
