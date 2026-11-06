#pragma once

#include <cstddef>
#include <cstdint>
#include <memory>

#if defined(_WIN32) && defined(SSRB_SHARED)
  #if defined(SSRB_BUILD)
    #define SSRB_API __declspec(dllexport)
  #else
    #define SSRB_API __declspec(dllimport)
  #endif
#else
  #define SSRB_API
#endif

namespace ssrb {

using Key = std::uint64_t;

class SSRB_API Index final {
public:
    // Stores keys in the half-open/closed key domain:
    // (anchor, anchor + span]. The anchor itself is not a valid key.
    // Throws std::invalid_argument for an overflowing key range and
    // std::bad_alloc if storage cannot be allocated.
    explicit Index(Key anchor, std::uint64_t span);

    ~Index();

    Index(Index&&) noexcept;
    Index& operator=(Index&&) noexcept;

    Index(const Index&) = delete;
    Index& operator=(const Index&) = delete;

    // Returns true only when a previously absent key is inserted.
    // Returns false for an out-of-range key or an already-present key.
    bool insert(Key key);

    // Returns true only when a present key is removed.
    // Returns false for an out-of-range key or an absent key.
    bool erase(Key key);

    // Returns false for keys outside the configured key domain.
    bool contains(Key key) const noexcept;

    std::size_t size() const noexcept;
    bool empty() const noexcept;
    void clear() noexcept;

    Key anchor() const noexcept;
    std::uint64_t span() const noexcept;

    // Bytes occupied by the Index object, implementation object, and
    // vector payload capacities. Excludes allocator bookkeeping and
    // unrelated process/runtime memory.
    std::size_t memory_usage_bytes() const noexcept;

private:
    struct Impl;
    std::unique_ptr<Impl> impl_;
};

} // namespace ssrb
