#include "type_string.h"
#include <cstdio>

#define typestring( x ) make_type_string( x )

int main( int argc, char** argv )
{
    using tag1_t = const type_string<'t', 'a', 'g'>;
    constexpr auto tag2 = make_type_string( "tag" );

    printf( "std::is_same = %s\n", std::is_same<tag1_t, decltype( tag2 )>::value ? "true" : "false" );
    printf( "tag = %s\n", tag1_t::value );
    printf( "tag = %s\n", decltype( tag2 )::value );

    return 0;
}