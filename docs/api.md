# Use the Reset Core

Public entry headers are [reset/reset.hpp](../include/reset/reset.hpp).

## Inspect at startup

Borrow a live `ResetInfo` to inspect a complete `causes()` mask or use `has_cause` for one flag. If the application must acknowledge the record, construct from `ReadClear&` and use `try_take_causes`. False means clearing is unavailable and preserves the output. A true result supplies the observed mask, including zero for an empty record.

Pass a `ResetRequest*` only for the same reset domain. `request_reset` returns false if that facet is absent or the request is denied. Treat any required preparation as work to complete before invoking it, because an accepted request may not return.

## Composition and lifetime

Application code calls the Reset Core. It borrows the matching Contract, which an Adapter implements using its Hardware Definitions. Future Devices will create or bind these objects and establish their lifetime. To use the examples today, construct the facade directly with the supplied fake. Keep each borrowed resource alive for its use by the facade and follow the Adapter's access and synchronization requirements.
