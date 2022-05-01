// Prevent the C++ compiler from name-mangling the C code
extern "C" {
#include "../../../../src/init_tools.h"
}

#include <gtest/gtest.h>

#include <cstring>
#include <cmath>

TEST(PrintErrorTest, StderrBuffer)
{
    const char* const kMsg {"Dummy message (ignore me)"};
    const char* const kFileMacro {__FILE__};
    const int kLineMacro {__LINE__};
    const char* const kFileName {"dummy_file_name.inp"};
    const char* const kKeyName {"dummyKeyName"};

    // Specify a buffer, buf, for stderr such that the error message written to
    // stderr via printError gets added to buf. Then, before 1) buf's lifetime
    // ends and 2) stderr is written to again, close stderr.
    char buf[BUFSIZ] {'\0'};  // Best practice: initialize all the elements
    setbuf(stderr, buf);
    printError(kMsg, kFileMacro, kLineMacro, kFileName, kKeyName);
    fclose(stderr);

    const char* const kFormatErrMsg {
        "ERROR: %s\n       Source: %s | Line: %d | Input: %s | Key: %s\n"};
    char* const errMsg {new char[
        std::strlen(kFormatErrMsg) - 10  // "- 10" for the format specifiers
        + std::strlen(kMsg)
        + std::strlen(kFileMacro)
        // The below is the number of digits in kLineMacro
        + static_cast<int>(std::floor(std::log10(kLineMacro))) + 1
        + std::strlen(kFileName)
        + std::strlen(kKeyName)
        + 1]};  // For the null terminator
    sprintf(errMsg,
            kFormatErrMsg,
            kMsg, kFileMacro, kLineMacro, kFileName, kKeyName);

    EXPECT_STREQ(buf, errMsg);

    delete[] errMsg;
}
