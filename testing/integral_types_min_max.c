/*
Build command:
gcc integral_types_min_max.c -Wall -Wextra -Wpedantic -std=c90 -o integral_types_min_max_c
*/

#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf(" CHAR_MIN: %d\n", CHAR_MIN);
    printf(" CHAR_MAX: %d\n", CHAR_MAX);
    printf("SCHAR_MIN: %d\n", SCHAR_MIN);
    printf("SCHAR_MAX: %d\n", SCHAR_MAX);
    printf("UCHAR_MAX: %u\n\n", UCHAR_MAX);

    printf(" SHRT_MIN: %hd\n", SHRT_MIN);
    printf(" SHRT_MAX: %hd\n", SHRT_MAX);
    printf("USHRT_MAX: %hu\n\n", USHRT_MAX);

    printf(" INT_MIN: %d\n", INT_MIN);
    printf(" INT_MAX: %d\n", INT_MAX);
    printf("UINT_MAX: %u\n\n", UINT_MAX);

    printf(" LONG_MIN: %ld\n", LONG_MIN);
    printf(" LONG_MAX: %ld\n", LONG_MAX);
    printf("ULONG_MAX: %lu\n\n", ULONG_MAX);

    return 0;
}
