#pragma once

#ifndef ARX_TYPE_TRAITS_H
#define ARX_TYPE_TRAITS_H

#if defined(ARDUINO_ARCH_AVR)\
 || defined(ARDUINO_ARCH_MEGAAVR)
    #define ARX_TYPE_TRAITS_DISABLED
#endif

// Make sure std namespace exists
namespace std { }

// Import everything from the std namespace into arx::std, so that
// anything we import rather than define is also available through
// arx::arx_std.
// This includes everything yet to be defined, so we can do this early
// (and must do so, to allow e.g. the C++14 additions in the arx::std
// namespace to reference the C++11 stuff from the system headers.
namespace arx {
    namespace arx_std {
        using namespace ::std;
    }
}

// Import everything from arx::std back into the normal std namespace.
// This ensures that you can just use `std::foo` everywhere and you get
// the standard library version if it is available, falling back to arx
// versions for things not supplied by the standard library. Only when
// you really need the arx version (e.g. for constexpr numeric_limits
// when also using ArduinoSTL), you need to qualify with arx::arx_std::
namespace std {
    using namespace ::arx::arx_std;
}

#include "ArxTypeTraits/replace_minmax_macros.h"

#ifndef ARX_TYPE_TRAITS_DISABLED
    #include <utility>
    #include <limits>
    #include <initializer_list>
    #include <type_traits>
    #include <tuple>
    #include <functional>
#endif

#include "ArxTypeTraits/type_traits.h"

#endif // ARX_TYPE_TRAITS_H
