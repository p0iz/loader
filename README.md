loader
======

A small, portable and RAII DLL loader.

Usage:

```
#include "loader/library.hpp"

loader::Library lib("<DLL name>");
if (lib.loaded()) {
	int funkyNumber = lib.func<int()>("funky")();
}
```

Licensed under MIT license. See LICENSE file.

Uses the lovely <a href="https://github.com/philsquared/Catch">Catch</a> framework for unit tests, licensed under <a href="http://www.boost.org/LICENSE_1_0.txt">Boost software license</a>.
