# JSON Parsing Test Suite
# see https://github.com/nst/JSONTestSuite

# /test_parsing/
# 
# The name of these files tell if their contents should be accepted or rejected.
# 
# - y_ content must be accepted by parsers
# - n_ content must be rejected by parsers
# - i_ parsers are free to accept or reject content
#
include(tests/json/test_parsing_y.cmake)
include(tests/json/test_parsing_n.cmake)
include(tests/json/test_parsing_i.cmake)

# 
# /test_transform/
# 
# These files contain weird structures and characters that parsers may understand differently, eg:
# 
# - huge numbers
# - dictionaries with similar keys
# - NULL characters
# - escaped invalid strings
# 
include(tests/json/test_transform.cmake)