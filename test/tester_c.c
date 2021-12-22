#include "../src/init_from_input_file.h"

#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    /* Variable declarations */
    char varChar;
    signed char varSchar;
    unsigned char varUchar;
    short varShort;
    unsigned short varUshort;
    int varInt;
    unsigned int varUint;
    long varLong;
    unsigned long varUlong;
    float varFloat;
    double varDouble;
    long double varLdouble;
    bool varBool;
    char varString[65];
    bool successFlag;

    /* char */
    varChar = '\0';
    successFlag = initFromInputFile("tester.inp", "char", "keyChar", &varChar);
    printf("keyChar: ");
    if (successFlag)
        printf("%c\n", varChar);
    else
        printf("fail\n");

    /* signed char */
    varSchar = 0;
    successFlag = initFromInputFile("tester.inp", "schar", "keySchar", &varSchar);
    printf("keySchar: ");
    if (successFlag)
        printf("%d\n", varSchar);
    else
        printf("fail\n");

    /* unsigned char */
    varUchar = 0U;
    successFlag = initFromInputFile("tester.inp", "uchar", "keyUchar", &varUchar);
    printf("keyUchar: ");
    if (successFlag)
        printf("%u\n", varUchar);
    else
        printf("fail\n");

    /* short */
    varShort = 0;
    successFlag = initFromInputFile("tester.inp", "short", "keyShort", &varShort);
    printf("keyShort: ");
    if (successFlag)
        printf("%hd\n", varShort);
    else
        printf("fail\n");

    /* unsigned short */
    varUshort = 0U;
    successFlag = initFromInputFile("tester.inp", "ushort", "keyUshort", &varUshort);
    printf("keyUshort: ");
    if (successFlag)
        printf("%hu\n", varUshort);
    else
        printf("fail\n");

    /* int */
    varInt = 0;
    successFlag = initFromInputFile("tester.inp", "int", "keyInt", &varInt);
    printf("keyInt: ");
    if (successFlag)
        printf("%d\n", varInt);
    else
        printf("fail\n");

    /* unsigned int */
    varUint = 0U;
    successFlag = initFromInputFile("tester.inp", "uint", "keyUint", &varUint);
    printf("keyUint: ");
    if (successFlag)
        printf("%u\n", varUint);
    else
        printf("fail\n");

    /* long */
    varLong = 0L;
    successFlag = initFromInputFile("tester.inp", "long", "keyLong", &varLong);
    printf("keyLong: ");
    if (successFlag)
        printf("%ld\n", varLong);
    else
        printf("fail\n");

    /* unsigned long */
    varUlong = 0UL;
    successFlag = initFromInputFile("tester.inp", "ulong", "keyUlong", &varUlong);
    printf("keyUlong: ");
    if (successFlag)
        printf("%lu\n", varUlong);
    else
        printf("fail\n");

    /* float */
    varFloat = 0.0F;
    successFlag = initFromInputFile("tester.inp", "float", "keyFloat", &varFloat);
    printf("keyFloat: ");
    if (successFlag)
        printf("%.9f\n", varFloat);
    else
        printf("fail\n");

    /* double */
    varDouble = 0.0;
    successFlag = initFromInputFile("tester.inp", "double", "keyDouble", &varDouble);
    printf("keyDouble: ");
    if (successFlag)
        printf("%.9f\n", varDouble);
    else
        printf("fail\n");

    /*
    long double
    NOTE: If using MinGW, have to prefix scanf (init_fxns ->
    init_from_input_file) and printf (below) with __mingw_.
    Refer to https://stackoverflow.com/a/14988103.
    */
    varLdouble = 0.0L;
    successFlag = initFromInputFile("tester.inp", "ldouble", "keyLdouble", &varLdouble);
    printf("keyLdouble: ");
    if (successFlag)
        printf("%.17Lf\n", varLdouble);
    else
        printf("fail\n");

    /* bool */
    varBool = false;
    successFlag = initFromInputFile("tester.inp", "bool", "keyBool", &varBool);
    printf("keyBool: ");
    if (successFlag)
        printf("%d\n", varBool);
    else
        printf("fail\n");

    /* string */
    successFlag = initFromInputFile("tester.inp", "string", "keyString", varString);
    printf("keyString: ");
    if (successFlag)
        printf("%s\n", varString);
    else
        printf("fail\n");

    return 0;
}
