#include <reset/reset.hpp>
#include "../examples/fake.hpp"

#include <cassert>
#include <type_traits>

using namespace mhaa::reset;
using namespace example;

class FakeResetRequest final : public ResetRequest
{
public:
    bool request_reset() override
    {
        ++calls;
        return allow;
    }

    bool allow = false;
    unsigned calls = 0;
};

int main()
{
    static_assert(!std::is_constructible<Reset, Fake &&>::value,
                  "A reset monitor cannot borrow a temporary");
    Fake first;
    Fake second;
    Reset read_only(static_cast<const ResetInfo &>(first));
    Causes captured = 0;
    assert(read_only.has_cause(Cause::Watchdog) && read_only.has_cause(Cause::PowerOn));
    assert(!read_only.has_cause(Cause::BrownOut));
    assert(!read_only.try_take_causes(captured) && captured == 0);
    Reset clearable(first);
    assert(clearable.try_take_causes(captured));
    assert(captured == second.causes() && clearable.causes() == 0);
    assert(second.causes() != 0);

    assert(!read_only.request_reset());
    FakeResetRequest requests;
    Reset reset(first, &requests);
    assert(!reset.request_reset() && requests.calls == 1);
    requests.allow = true;
    assert(reset.request_reset() && requests.calls == 2);
}
