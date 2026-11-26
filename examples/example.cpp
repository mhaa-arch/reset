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
