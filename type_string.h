#pragma once

#include <utility>
#include <string_view>

template<typename T, T... Ts>
struct integral_constant_array
{
    static constexpr T value[] = { Ts... };
    static constexpr size_t size() noexcept { return sizeof...( Ts ); }
};

template<char... Cs>
using type_string = struct integral_constant_array<char, Cs..., '\0'>;

namespace detail
{
    template<typename Holder, size_t... Is>
    constexpr auto make_type_string_impl( Holder holder, std::index_sequence<Is...> )
    {
        constexpr std::string_view text = holder();
        return type_string<text[Is]...>{};
    }
    template<typename Holder>
    constexpr auto make_type_string_impl( Holder holder )
    {
        constexpr std::string_view text = holder();
        return make_type_string_impl( holder, std::make_index_sequence<text.size()>{} );
    }
}

#define NEBULA_LAMBDA_HOLDER( x ) [](){ return x; }
#define make_type_string( x ) detail::make_type_string_impl( NEBULA_LAMBDA_HOLDER( x ) )