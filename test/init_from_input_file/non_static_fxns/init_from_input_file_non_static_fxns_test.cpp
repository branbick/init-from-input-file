// Prevent the C++ compiler from name-mangling the C code
extern "C" {
#include "../../../src/init_from_input_file.h"
}

#include <gtest/gtest.h>

// TODO: Add tests
TEST(InitFromInputFileTest, FileDoesNotExist)
{
    EXPECT_FALSE(initFromInputFile("file_does_not_exist.inp",
                                   "dummyVarType",
                                   "dummyKeyName",
                                   NULL));
}

TEST(InitFromInputFileTest, Char)
{
    char c;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "char",
                                   "keyChar",
                                   &c));
    EXPECT_EQ(c, 'A');
}

TEST(InitFromInputFileTest, SignedChar)
{
    signed char sc;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "schar",
                                   "keySchar",
                                   &sc));
    EXPECT_EQ(sc, -1);
}

TEST(InitFromInputFileTest, UnsignedChar)
{
    unsigned char uc;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "uchar",
                                   "keyUchar",
                                   &uc));
    EXPECT_EQ(uc, 1U);
}

TEST(InitFromInputFileTest, Short)
{
    short s;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "short",
                                   "keyShort",
                                   &s));
    EXPECT_EQ(s, -2);
}

TEST(InitFromInputFileTest, UnsignedShort)
{
    unsigned short us;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "ushort",
                                   "keyUshort",
                                   &us));
    EXPECT_EQ(us, 2U);
}

TEST(InitFromInputFileTest, Int)
{
    int i;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "int",
                                   "keyInt",
                                   &i));
    EXPECT_EQ(i, -3);
}

TEST(InitFromInputFileTest, UnsignedInt)
{
    unsigned int ui;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "uint",
                                   "keyUint",
                                   &ui));
    EXPECT_EQ(ui, 3U);
}

TEST(InitFromInputFileTest, Long)
{
    long l;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "long",
                                   "keyLong",
                                   &l));
    EXPECT_EQ(l, -4L);
}

TEST(InitFromInputFileTest, UnsignedLong)
{
    unsigned long ul;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "ulong",
                                   "keyUlong",
                                   &ul));
    EXPECT_EQ(ul, 4UL);
}

TEST(InitFromInputFileTest, Float)
{
    float f;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "float",
                                   "keyFloat",
                                   &f));
    EXPECT_EQ(f, 0.12345F);
}

TEST(InitFromInputFileTest, Double)
{
    double d;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "double",
                                   "keyDouble",
                                   &d));
    EXPECT_EQ(d, 0.123456789);
}

TEST(InitFromInputFileTest, LongDouble)
{
    long double ld;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "ldouble",
                                   "keyLdouble",
                                   &ld));
    EXPECT_EQ(ld, 0.12345678987654321L);
}

TEST(InitFromInputFileTest, Bool)
{
    bool b;

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "bool",
                                   "keyBool",
                                   &b));
    EXPECT_EQ(b, true);
}

TEST(InitFromInputFileTest, String)
{
    char str[16];

    EXPECT_TRUE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "string",
                                   "keyString",
                                   str));
    EXPECT_STREQ(str, "Hello, world!");
}

TEST(InitFromInputFileTest, InvalidVarType)
{
    EXPECT_FALSE(initFromInputFile("../InitFromInputFileTest.inp",
                                   "invalidVarType",
                                   "dummyKeyName",
                                   NULL));
}
