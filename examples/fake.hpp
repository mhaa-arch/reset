#ifndef MHAA_RESET_EXAMPLE_FAKE_HPP
#define MHAA_RESET_EXAMPLE_FAKE_HPP

#include <reset/reset_info.hpp>
#include <reset/read_clear.hpp>
#include <reset/reset_request.hpp>

namespace example
{
    using namespace mhaa::reset;

    class Fake final : public ReadClear
    {
    public:
        Causes causes() const override { return flags; }
        Causes take_causes() override
        {
            const Causes observed = flags;
            flags = 0;
            return observed;
        }

        Causes flags = static_cast<Causes>(Cause::Watchdog) | static_cast<Causes>(Cause::PowerOn);
    };
}

#endif
