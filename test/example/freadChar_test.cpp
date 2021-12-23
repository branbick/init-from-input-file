// Prevent C++ from name mangling the C code
extern "C" {
#include "../../src/init_tools.h"
}

#include <gtest/gtest.h>
#include <stdio.h>
#include <iostream>

TEST(FreadCharTest, BasicAssertions)
{
    FILE* pFile = fopen("../freadChar_test.inp", "r");  // TODO: Change to C++ way
    if (pFile == NULL)
    {
        std::cout << "Unable to open input file" << std::endl;
        return;
    }
    
    char c;
    freadChar(pFile, &c);

    EXPECT_EQ(c, 'a');
}
