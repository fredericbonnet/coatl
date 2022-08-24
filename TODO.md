# TODO

## Integers

- Refactor parsing with digit consume macros
- https://github.com/kokke/tiny-bignum-c

## Unicode

- Define public types for UCD property accessors

## Docs

- tagfiles for cross-linking Colibri doc: https://www.doxygen.nl/manual/external.html

## JSON

Standards, test suites, benchmarks etc.:

- https://github.com/miloyip/nativejson-benchmark
- https://github.com/mloskot/json_benchmark
- https://chadaustin.me/2013/01/json-parser-benchmarking/
- https://lemire.me/blog/2018/05/03/how-fast-can-you-parse-json/
- https://vinniefalco.github.io/doc/json/json/benchmarks.html
- https://github.com/ibireme/yyjson_benchmark
- https://reposhub.com/cpp/json/ibireme-yyjson_benchmark.html
- https://lemire.me/blog/2020/03/31/we-released-simdjson-0-3-the-fastest-json-parser-in-the-world-is-even-better/
- https://tools.ietf.org/html/rfc8259#section-7
- http://seriot.ch/parsing_json.php
- https://github.com/nst/JSONTestSuite
- https://rapidjson.org/md_doc_performance.html
- https://dave.cheney.net/high-performance-json.html

## Math

Integers:

- Conversion Functions
  - native c
  - colibri words
  - coatl numbers
- Arithmetic Functions :
  - [x] add
  - [x] sub
  - [x] mul
  - [x] div
  - [ ] addmul
  - [ ] submul
  - [ ] mul_2exp
  - [ ] neg
  - [ ] abs
- Division Functions :
  - cdiv / fdiv / tdiv
  - q / r / qr
  - 2exp
- Exponentiation :
  - pow
  - powm
- Root Extraction Functions :
  - root / ntroot / rootrem
  - sqrt / sqrtrem
  - perfect_power
  - perfect_square
- Comparison Functions :
  - cmp
  - cmpabs
  - sgn
- Logical and Bit Manipulation Functions
  - and
  - ior
  - xor
  - com
  - setbit
  - clrbit
  - combit
  - tstbit
