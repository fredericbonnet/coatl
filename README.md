# CoATL: The Colibri Advanced Type Library

CoATL stands for "Colibri Advanced Type Library". It is based on the [Colibri
library](https://github.com/fredericbonnet/colibri) and adds advanced features
not supported by the latter because of their reliance on external dependencies.
As Colibri is meant to be lightweight and dependence-free, the goal of CoATL is
to host all features relying on third-party code, heavyweight or external data,
or having specific license issues.

## License

CoATL is released under the terms of the 3-Clause BSD License:

https://opensource.org/licenses/BSD-3-Clause

## Features

At present, CoATL provides the following features:

- Full support for the [Unicode Character Database](https://unicode.org/ucd/)
  (UCD) in its latest version at the time of writing (13.0.0): all properties
  but character names and aliases are statically compiled into the library in an
  efficient manner (the final library file is around 900kB). This provides
  features such as case mapping and folding of individual characters and
  strings, and UCD property accessors on the full range of Unicode codepoints
  (over one million values)

- Regular expressions thanks to Henry Spencer's regexp package. This was ported
  from the Tcl 8.5 codebase and adapted to use Colibri ropes instead of plain
  flat character arrays. This provides transparent support for fixed-width
  8/16/32-bit and variable-width UTF-8/16 Unicode strings

- Large integer words on 32-bit systems

- Multiple precision integer and floating point words thanks to the
  [MPIR](http://mpir.org/) library with conversion support to/from Colibri ropes

- JSON conversion to/from Colibri words
