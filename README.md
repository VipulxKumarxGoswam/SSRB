\# SSRB Public SDK v0.1

Time & Space Complexity

- Lookup: O(1) — deterministic,  collision-free routing.
- Insertion: O(1).
- Deletion: O(1).
- Space: O(U) bits, where U is the supported key universe.

This is the public-facing header and example for the SSRB closed-core SDK.

A matching compiled library is required and must be supplied separately.



\## Requirements

\- C++11 or newer

\- Matching SSRB library for your OS, architecture, compiler family and runtime



\## Use



```cpp

\#include "ssrb.h"



ssrb::Index index(1000000000ULL, 2000000ULL);

index.insert(1000000001ULL);

bool found = index.contains(1000000001ULL);

```



Valid keys are `(anchor, anchor + span]`. The anchor itself is excluded.



\## API

\- `insert(key)`: true only if a new key was inserted

\- `contains(key)`: true if the key exists

\- `erase(key)`: true only if an existing key was removed

\- `size()`, `empty()`, `clear()`

\- `anchor()`, `span()`

\- `memory\_usage\_bytes()`



\## Thread safety and persistence

This version provides no internal synchronization. Externally synchronize

access whenever operations may overlap and at least one operation modifies

the index. The index is in-memory only; applications must rebuild it from

their authoritative persistent data after restart.



\## Distribution and Licensing



This SDK intentionally excludes SSRB implementation source code.



The supplied compiled library is distributed under the terms of the accompanying `LICENSE.txt` (SSRB v0.1 Proprietary Evaluation License).



Use is restricted to the permissions expressly granted by that license. Commercial and production use requires a separate written license agreement from the copyright owner.



See `LICENSE.txt` before using the SDK.

