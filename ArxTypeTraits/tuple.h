#pragma once

#ifndef ARX_TYPE_TRAITS_TUPLE_H
#define ARX_TYPE_TRAITS_TUPLE_H

#if ARX_HAVE_LIBSTDCPLUSPLUS >= 201103L // Have libstdc++11

#include <tuple>

#else // Do not have libstdc++11

namespace arx::stdx {

    // https://theolizer.com/cpp-school2/cpp-school2-15/
    // https://wandbox.org/permlink/C0BWIzjqg4iO3kKZ

    template<typename... Ts>
    struct tuple
    {
        tuple() {}
    };

    template<typename TFirst, typename... TRest>
    class tuple<TFirst, TRest...> : public tuple<TRest...>
    {
    public:
        tuple(TFirst const& iFirst, TRest const&... iRest)
            : tuple<TRest...>(iRest...),
              mMember(iFirst)
        {
        }

        constexpr tuple() {}

    private:
        template<size_t N, typename... TTypes>
        friend struct get_helper;

        TFirst mMember;
    };

    template<size_t N, typename... TTypes>
    struct get_helper { };
    template<typename TFirst, typename... TRest>
    struct get_helper<0, TFirst, TRest...>
    {
        typedef TFirst type;
        static type& get(tuple<TFirst, TRest...>& iTuple)
        {
            return iTuple.mMember;
        }
    };
    template<size_t N, typename TFirst, typename... TRest>
    struct get_helper<N, TFirst, TRest...>
    {
        typedef typename get_helper<N - 1, TRest...>::type type;
        static type& get(tuple<TFirst, TRest...>& iTuple)
        {
            return get_helper<N - 1, TRest...>::get(iTuple);
        }
    };

    template<size_t N, typename... TTypes>
    typename get_helper<N, TTypes...>::type& get(tuple<TTypes...>& iTuple)
    {
        return get_helper<N, TTypes...>::get(iTuple);
    }

    template<typename T> class tuple_size;
    template<typename T> class tuple_size<const T>;
    template<typename T> class tuple_size<volatile T>;
    template<typename T> class tuple_size<const volatile T>;
    template<typename... Types>
    struct tuple_size<tuple<Types...>>
        : integral_constant<size_t, sizeof...(Types)> {};

    template<typename... Types>
    auto make_tuple(Types&&... args)
        -> std::tuple<typename std::remove_reference<Types>::type...>
    {
        return std::tuple<typename std::remove_reference<Types>::type...>(std::forward<typename std::remove_reference<Types>::type>(args)...);
    }

} // namespace arx::stdx

#endif // Do not have libstdc++11

#endif // ARX_TYPE_TRAITS_TUPLE_H
