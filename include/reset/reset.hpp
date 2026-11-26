#ifndef MHAA_RESET_HPP
#define MHAA_RESET_HPP

#include <reset/reset_info.hpp>
#include <reset/read_clear.hpp>
#include <reset/reset_request.hpp>
#include <reset/types.hpp>

namespace mhaa
{
    namespace reset
    {
        /** @brief Observes the recorded causes on one borrowed source. */
        class Reset
        {
        public:
            explicit Reset(const ResetInfo &info, ResetRequest *request = nullptr)
                : info_(info), clear_(nullptr), request_(request) {}

            explicit Reset(ReadClear &source, ResetRequest *request = nullptr)
                : info_(source), clear_(&source), request_(request) {}

            Reset(const ResetInfo &&, ResetRequest * = nullptr) = delete;

            Causes causes() const { return info_.causes(); }

            /** @brief Tests one cause without acknowledging any flags. */
            bool has_cause(Cause cause) const
            {
                return (causes() & static_cast<Causes>(cause)) != 0;
            }

            /** @brief Retrieves and acknowledges flags where the same source supports it. */
            bool try_take_causes(Causes &causes)
            {
                if (!clear_)
                {
                    return false;
                }
                causes = clear_->take_causes();
                return true;
            }

            /** @brief False indicates an unavailable or declined request. Success may not return. */
            bool request_reset() { return request_ && request_->request_reset(); }

        private:
            const ResetInfo &info_;
            ReadClear *clear_;
            ResetRequest *request_;
        };
    }
}

#endif
