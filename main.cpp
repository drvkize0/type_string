#include "type_string.h"
#include <cstdio>

#define typestring( x ) make_type_string( x )

int main( int argc, char** argv )
{
    constexpr auto tag = make_type_string( "test-tag0" );

    printf( "tag = %s\n", decltype( tag )::value );

    return 0;
}