// utility.h

#ifndef ARX_TYPE_TRAITS_UTILITY_H
#define ARX_TYPE_TRAITS_UTILITY_H

#if ARX_HAVE_LIBSTDCPLUSPLUS >= 201703L // Have libstdc++17

#include <utility>

#else // Do not have libstdc++17

#include "type_traits.h"

namespace arx::stdx {

template<typename T>
[[nodiscard]]
constexpr add_const_t<T>& as_const(T& val) noexcept
{
    return val;
}

template<typename T>
void as_const(const T&&) = delete;

} // namespace arx::stdx

#endif // Do not have libstdc++17

#endif // ARX_TYPE_TRAITS_UTILITY_H