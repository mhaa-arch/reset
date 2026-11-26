# Run the Reset Core example

The fake exposes a record and clearing through the same `ReadClear` object. The Core takes the record into `boot` and the program checks both the nonempty snapshot and the empty live record. The behavior test shows a read-only binding and a separately supplied reset-request capability.

## Example program

The [program](../examples/example.cpp) uses the [local fake](../examples/fake.hpp) to demonstrate injection. A concrete Adapter implementing the same Contract can be supplied to the same facade.

```cpp
#include <reset/reset.hpp>
#include "fake.hpp"

using namespace mhaa::reset;
using namespace example;

int main()
{
    Fake monitor;
    Reset reset(monitor);
    Causes boot = 0;
    return reset.try_take_causes(boot) && boot != 0 && reset.causes() == 0 ? 0 : 1;
}
```

## Build and run

Build from this repository root. Set `contract_include` to the matching Contract's `include/` directory. The value below applies to the MHAA development workspace. Both programs exit with status 0 on success and print no output. On Windows execute `example.exe` and `behavior.exe`.

```sh
contract_include=../../contracts/reset-contract/include
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -I"$contract_include" examples/example.cpp -o example
./example
g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror -fno-rtti -fno-exceptions -Iinclude -I"$contract_include" tests/behavior.cpp -o behavior
./behavior
```

See the [behavior test](../tests/behavior.cpp) for the additional cases described above.
