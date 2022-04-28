// Prevent the C++ compiler from name-mangling the C code
extern "C" {
#include "../../../src/init_from_input_file.c"
}

#include <gtest/gtest.h>

TEST(InitNonBoolNonStrTest, FindKeyFailure)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_FALSE(initNonBoolNonStr(pFile,
                                   "keyDoesNotExist",
                                   "dummyFormatSpec",
                                   NULL));

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, FindValueFailure)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_FALSE(initNonBoolNonStr(pFile,
                                   "keyExistsButValueDoesNot",
                                   "dummyFormatSpec",
                                   NULL));

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, MatchingFailure)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    signed char sc;

    // Attempting to populate a signed char (i.e., sc) with a non-numeric
    // character constant (i.e., the value corresponding to keyChar) causes a
    // matching failure
    EXPECT_FALSE(initNonBoolNonStr(pFile, "keyChar", "%d", &sc));

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, Char)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    char c;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "keyChar", "%c", &c));
    EXPECT_EQ(c, 'A');

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, SignedChar)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    signed char sc;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "keySchar", "%d", &sc));
    EXPECT_EQ(sc, -1);

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, UnsignedChar)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    unsigned char uc;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "keyUchar", "%u", &uc));
    EXPECT_EQ(uc, 1U);

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, Short)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    short s;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "keyShort", "%hd", &s));
    EXPECT_EQ(s, -2);

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, UnsignedShort)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    unsigned short us;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "keyUshort", "%hu", &us));
    EXPECT_EQ(us, 2U);

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, Int)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    int i;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "keyInt", "%d", &i));
    EXPECT_EQ(i, -3);

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, UnsignedInt)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    unsigned int ui;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "keyUint", "%u", &ui));
    EXPECT_EQ(ui, 3U);

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, Long)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    long l;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "keyLong", "%ld", &l));
    EXPECT_EQ(l, -4L);

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, UnsignedLong)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    unsigned long ul;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "keyUlong", "%lu", &ul));
    EXPECT_EQ(ul, 4UL);

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, Float)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    float f;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "keyFloat", "%f", &f));
    EXPECT_EQ(f, 0.12345F);

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, Double)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    double d;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "keyDouble", "%lf", &d));
    EXPECT_EQ(d, 0.123456789);

    fclose(pFile);
}

TEST(InitNonBoolNonStrTest, LongDouble)
{
    const char* const kFileName {"../input/InitNonBoolNonStrTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    long double ld;

    EXPECT_TRUE(initNonBoolNonStr(pFile, "keyLdouble", "%Lf", &ld));
    EXPECT_EQ(ld, 0.12345678987654321L);

    fclose(pFile);
}

TEST(InitBoolTest, FindKeyFailure)
{
    const char* const kFileName {"../input/InitBoolTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_FALSE(initBool(pFile, "keyDoesNotExist", NULL));

    fclose(pFile);
}

TEST(InitBoolTest, FindValueFailure)
{
    const char* const kFileName {"../input/InitBoolTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_FALSE(initBool(pFile, "keyExistsButValueDoesNot", NULL));

    fclose(pFile);
}

// Regarding initBool, it's impossible to cause a matching failure--like what's
// done in the case of initNonBoolNonStr (refer to the "MatchingFailure" test
// above)--because temp is a char (array), which can hold any type of constant.

TEST(InitBoolTest, NumberOneInsteadOfTrue)
{
    const char* const kFileName {"../input/InitBoolTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_FALSE(initBool(pFile, "numberOneInsteadOfTrue", NULL));

    fclose(pFile);
}

TEST(InitBoolTest, NumberZeroInsteadOfFalse)
{
    const char* const kFileName {"../input/InitBoolTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_FALSE(initBool(pFile, "numberZeroInsteadOfFalse", NULL));

    fclose(pFile);
}

TEST(InitBoolTest, WordThatStartsWithTrue)
{
    const char* const kFileName {"../input/InitBoolTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_FALSE(initBool(pFile, "wordThatStartsWithTrue", NULL));

    fclose(pFile);
}

TEST(InitBoolTest, WordThatStartsWithFalse)
{
    const char* const kFileName {"../input/InitBoolTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_FALSE(initBool(pFile, "wordThatStartsWithFalse", NULL));

    fclose(pFile);
}

TEST(InitBoolTest, ExactlyTrue)
{
    const char* const kFileName {"../input/InitBoolTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    bool b;

    EXPECT_TRUE(initBool(pFile, "exactlyTrue", &b));
    EXPECT_EQ(b, true);

    fclose(pFile);
}

TEST(InitBoolTest, ExactlyFalse)
{
    const char* const kFileName {"../input/InitBoolTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    bool b;

    EXPECT_TRUE(initBool(pFile, "exactlyFalse", &b));
    EXPECT_EQ(b, false);

    fclose(pFile);
}

// TODO: Add tests for initString. Add tests for successes that have different
// values--letters, numbers, symbols, and combinations. (Note that the key
// "prematureEof" must be listed last in the input file.)
TEST(InitStringTest, FindKeyFailure)
{
    const char* const kFileName {"../input/InitStringTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_FALSE(initString(pFile, "keyDoesNotExist", NULL));

    fclose(pFile);
}

TEST(InitStringTest, FindValueFailure)
{
    const char* const kFileName {"../input/InitStringTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    EXPECT_FALSE(initString(pFile, "keyExistsButValueDoesNot", NULL));

    fclose(pFile);
}

TEST(InitStringTest, FirstCharSkipped)
{
    const char* const kFileName {"../input/InitStringTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    char str[65];

    EXPECT_TRUE(initString(pFile, "firstCharSkipped", str));
    EXPECT_STREQ(str, "ecause the opening double quotation mark is missing");

    fclose(pFile);
}

TEST(InitStringTest, PrematureEof)
{
    const char* const kFileName {"../input/InitStringTest.inp"};
    FILE* const pFile {fopen(kFileName, "r")};
    if (pFile == NULL)
        FAIL() << "Unable to open " << kFileName << std::endl;

    char str[65];

    EXPECT_FALSE(initString(pFile, "prematureEof", str));

    fclose(pFile);
}
