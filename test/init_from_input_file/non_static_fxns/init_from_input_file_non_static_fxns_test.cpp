// Prevent the C++ compiler from name-mangling the C code
extern "C" {
#include "../../../src/init_from_input_file.h"
}

#include <gtest/gtest.h>

// TODO: Add tests
TEST(InitFromInputFileTest, FileDoesNotExist)
{
    int dummyVar {0};

    EXPECT_FALSE(initFromInputFile("file_does_not_exist",
                                   "dummyVarType",
                                   "dummyKeyName",
                                   &dummyVar));
}
