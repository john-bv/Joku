# Errors

The errors module is responsible for printing errors to the user in a neat fashion.

While this module is portable, it is heavily linked to joku.

Make an error:

```cpp
#include <joku>

using namespace joku::compiler;

void raise_compiler_error()
{
    // get a token stream
    Error<ParseError> error = 
}
```
