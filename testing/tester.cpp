// Build command:
// g++ tester.cpp ..\init_from_input_file.c ..\init_tools.c -Wall -Wextra -Wpedantic -std=c++17 -o tester_cpp

#include "../init_from_input_file.h"

#include <iostream>
#include <iomanip>

int main()
{
    // char
    char varChar = '\0';
    bool successFlag = initFromInputFile("tester.inp", "char", "keyChar", &varChar);
    std::cout << "keyChar: ";
    if (successFlag)
        std::cout << varChar << std::endl;
    else
        std::cout << "fail" << std::endl;

    // signed char
    // NOTE: signed char is not treated as a number by the output stream. So,
    // have to static_cast it to an int to print the actual value.
    // Refer to https://newbedev.com/why-is-std-cout-not-printing-the-correct-value-for-my-int8-t-number.
    signed char varSchar = 0;
    successFlag = initFromInputFile("tester.inp", "schar", "keySchar", &varSchar);
    std::cout << "keySchar: ";
    if (successFlag)
        std::cout << static_cast<int>(varSchar) << std::endl;
    else
        std::cout << "fail" << std::endl;

    // unsigned char
    // NOTE: unsigned char is not treated as a number by the output stream. So,
    // have to static_cast it to an unsigned int to print the actual value.
    // Refer to https://newbedev.com/why-is-std-cout-not-printing-the-correct-value-for-my-int8-t-number.
    unsigned char varUchar = 0U;
    successFlag = initFromInputFile("tester.inp", "uchar", "keyUchar", &varUchar);
    std::cout << "keyUchar: ";
    if (successFlag)
        std::cout << static_cast<unsigned int>(varUchar) << std::endl;
    else
        std::cout << "fail" << std::endl;

    // short
    short varShort = 0;
    successFlag = initFromInputFile("tester.inp", "short", "keyShort", &varShort);
    std::cout << "keyShort: ";
    if (successFlag)
        std::cout << varShort << std::endl;
    else
        std::cout << "fail" << std::endl;

    // unsigned short
    unsigned short varUshort = 0U;
    successFlag = initFromInputFile("tester.inp", "ushort", "keyUshort", &varUshort);
    std::cout << "keyUshort: ";
    if (successFlag)
        std::cout << varUshort << std::endl;
    else
        std::cout << "fail" << std::endl;

    // int
    int varInt = 0;
    successFlag = initFromInputFile("tester.inp", "int", "keyInt", &varInt);
    std::cout << "keyInt: ";
    if (successFlag)
        std::cout << varInt << std::endl;
    else
        std::cout << "fail" << std::endl;

    // unsigned int
    unsigned int varUint = 0U;
    successFlag = initFromInputFile("tester.inp", "uint", "keyUint", &varUint);
    std::cout << "keyUint: ";
    if (successFlag)
        std::cout << varUint << std::endl;
    else
        std::cout << "fail" << std::endl;

    // long
    long varLong = 0L;
    successFlag = initFromInputFile("tester.inp", "long", "keyLong", &varLong);
    std::cout << "keyLong: ";
    if (successFlag)
        std::cout << varLong << std::endl;
    else
        std::cout << "fail" << std::endl;

    // unsigned long
    unsigned long varUlong = 0UL;
    successFlag = initFromInputFile("tester.inp", "ulong", "keyUlong", &varUlong);
    std::cout << "keyUlong: ";
    if (successFlag)
        std::cout << varUlong << std::endl;
    else
        std::cout << "fail" << std::endl;

    // float
    float varFloat = 0.0F;
    successFlag = initFromInputFile("tester.inp", "float", "keyFloat", &varFloat);
    std::cout << "keyFloat: ";
    if (successFlag)
        std::cout << std::setprecision(9) << varFloat << std::endl;
    else
        std::cout << "fail" << std::endl;

    // double
    double varDouble = 0.0;
    successFlag = initFromInputFile("tester.inp", "double", "keyDouble", &varDouble);
    std::cout << "keyDouble: ";
    if (successFlag)
        std::cout << std::setprecision(9) << varDouble << std::endl;
    else
        std::cout << "fail" << std::endl;

    // long double
    // NOTE: If using MinGW, have to prefix scanf (init_fxns >
    // initNonBoolNonStr) with __mingw_.
    // Refer to https://stackoverflow.com/a/14988103.
    long double varLdouble = 0.0L;
    successFlag = initFromInputFile("tester.inp", "ldouble", "keyLdouble", &varLdouble);
    std::cout << "keyLdouble: ";
    if (successFlag)
        std::cout << std::setprecision(17) << varLdouble << std::endl;
    else
        std::cout << "fail" << std::endl;

    // bool
    bool varBool = false;
    successFlag = initFromInputFile("tester.inp", "bool", "keyBool", &varBool);
    std::cout << "keyBool: ";
    if (successFlag)
        std::cout << varBool << std::endl;
    else
        std::cout << "fail" << std::endl;

    // string
    char varString[65];
    successFlag = initFromInputFile("tester.inp", "string", "keyString", varString);
    std::cout << "keyString: ";
    if (successFlag)
        std::cout << varString << std::endl;
    else
        std::cout << "fail" << std::endl;

    return 0;
}
