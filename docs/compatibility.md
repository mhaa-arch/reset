# Using Reset across targets

The only project dependency is the matching `reset-contract`. Keep its API revision aligned with this Core.

Boot logic can use the same flags on targets that capture them at an appropriate time. Request authority and the affected reset domain belong to composition. Avoid relying on an observation or a clearing policy until the target-specific startup sequence has been verified.

This repository's host simulations and shared API compile/link checks provide source-level evidence. Target timing and physical behavior require hardware validation.
