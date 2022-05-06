// Prevent the C++ compiler from name-mangling the C code
extern "C" {
#include "../../../src/init_from_input_file.h"
}

#include <gtest/gtest.h>

TEST(InitFromInputFileTest, FileDoesNotExist)
{
    EXPECT_FALSE(initFromInputFile("file_does_not_exist.inp",
                                   "dummyVarType",
                                   "dummyKeyName",
                                   NULL));
}

TEST(InitFromInputFileTest, CharSuccess)
{
    char c;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                  "char",
                                  "charSuccess",
                                  &c));
    EXPECT_EQ(c, 'A');
}

TEST(InitFromInputFileTest, SignedCharSuccess)
{
    signed char sc;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                  "schar",
                                  "scharSuccess",
                                  &sc));
    EXPECT_EQ(sc, -1);
}

TEST(InitFromInputFileTest, UnsignedCharSuccess)
{
    unsigned char uc;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                  "uchar",
                                  "ucharSuccess",
                                  &uc));
    EXPECT_EQ(uc, 1U);
}

TEST(InitFromInputFileTest, ShortSuccess)
{
    short s;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                  "short",
                                  "shortSuccess",
                                  &s));
    EXPECT_EQ(s, -2);
}

TEST(InitFromInputFileTest, UnsignedShortSuccess)
{
    unsigned short us;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                  "ushort",
                                  "ushortSuccess",
                                  &us));
    EXPECT_EQ(us, 2U);
}

TEST(InitFromInputFileTest, IntSuccess)
{
    int i;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                  "int",
                                  "intSuccess",
                                  &i));
    EXPECT_EQ(i, -3);
}

TEST(InitFromInputFileTest, UnsignedIntSuccess)
{
    unsigned int ui;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                  "uint",
                                  "uintSuccess",
                                  &ui));
    EXPECT_EQ(ui, 3U);
}

TEST(InitFromInputFileTest, LongSuccess)
{
    long l;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                  "long",
                                  "longSuccess",
                                  &l));
    EXPECT_EQ(l, -4L);
}

TEST(InitFromInputFileTest, UnsignedLongSuccess)
{
    unsigned long ul;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                  "ulong",
                                  "ulongSuccess",
                                  &ul));
    EXPECT_EQ(ul, 4UL);
}

TEST(InitFromInputFileTest, FloatSuccess)
{
    float f;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                  "float",
                                  "floatSuccess",
                                  &f));
    EXPECT_EQ(f, 0.12345F);
}

TEST(InitFromInputFileTest, DoubleSuccess)
{
    double d;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                  "double",
                                  "doubleSuccess",
                                  &d));
    EXPECT_EQ(d, 0.123456789);
}

TEST(InitFromInputFileTest, LongDoubleSuccess)
{
    long double ld;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                  "ldouble",
                                  "ldoubleSuccess",
                                  &ld));
    EXPECT_EQ(ld, 0.12345678987654321L);
}

TEST(InitFromInputFileTest, BoolSuccess)
{
    bool b;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                  "bool",
                                  "boolSuccess",
                                  &b));
    EXPECT_EQ(b, true);
}

TEST(InitFromInputFileTest, StringSuccess)
{
    char str[16];

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                  "string",
                                  "stringSuccess",
                                  str));
    EXPECT_STREQ(str, "Hello, world!");
}

// NOTE: All the "<VariableType>Failure" tests below "EXPECT_FALSE" because,
// for each, the key (i.e., "<variableType>Failure") does not exist in the
// input file
TEST(InitFromInputFileTest, CharFailure)
{
    EXPECT_FALSE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "char",
                                   "charFailure",
                                   NULL));
}

TEST(InitFromInputFileTest, SignedCharFailure)
{
    EXPECT_FALSE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "schar",
                                   "scharFailure",
                                   NULL));
}

TEST(InitFromInputFileTest, UnsignedCharFailure)
{
    EXPECT_FALSE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "uchar",
                                   "ucharFailure",
                                   NULL));
}

TEST(InitFromInputFileTest, ShortFailure)
{
    EXPECT_FALSE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "short",
                                   "shortFailure",
                                   NULL));
}

TEST(InitFromInputFileTest, UnsignedShortFailure)
{
    EXPECT_FALSE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "ushort",
                                   "ushortFailure",
                                   NULL));
}

TEST(InitFromInputFileTest, IntFailure)
{
    EXPECT_FALSE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "int",
                                   "intFailure",
                                   NULL));
}

TEST(InitFromInputFileTest, UnsignedIntFailure)
{
    EXPECT_FALSE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "uint",
                                   "uintFailure",
                                   NULL));
}

TEST(InitFromInputFileTest, LongFailure)
{
    EXPECT_FALSE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "long",
                                   "longFailure",
                                   NULL));
}

TEST(InitFromInputFileTest, UnsignedLongFailure)
{
    EXPECT_FALSE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "ulong",
                                   "ulongFailure",
                                   NULL));
}

TEST(InitFromInputFileTest, FloatFailure)
{
    EXPECT_FALSE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "float",
                                   "floatFailure",
                                   NULL));
}

TEST(InitFromInputFileTest, DoubleFailure)
{
    EXPECT_FALSE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "double",
                                   "doubleFailure",
                                   NULL));
}

TEST(InitFromInputFileTest, LongDoubleFailure)
{
    EXPECT_FALSE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "ldouble",
                                   "ldoubleFailure",
                                   NULL));
}

TEST(InitFromInputFileTest, BoolFailure)
{
    EXPECT_FALSE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "bool",
                                   "boolFailure",
                                   NULL));
}

TEST(InitFromInputFileTest, StringFailure)
{
    EXPECT_FALSE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "string",
                                   "stringFailure",
                                   NULL));
}

TEST(InitFromInputFileTest, InvalidVarType)
{
    EXPECT_FALSE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "invalidVarType",
                                   "dummyKeyName",
                                   NULL));
}
