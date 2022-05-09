# init-from-input-file
## Introduction
`init-from-input-file` allows C and C++ variables to be initialized from an input text file, consequently **eliminating the need to recompile** source code merely due to a changed initialization value. For example, consider a simulation of an air-launched missile. Instead of writing ...
```
const double kAltitudeInitial = 10000.0;  /* meters (m) */
```
where the right-hand side (i.e., floating constant / floating-point literal) must be updated for different scenarios, requiring recompilation of the source code after every update, write ...
```
double altitudeInitial = 0.0;  /* meters (m) */
const bool kSuccessFlag = initFromInputFile("missile.inp", "double", "altInit", &altitudeInitial);
```
where `src/init_from_input_file.h` must be `#include`d. Breaking down the above, the input text file `missile.inp` is searched for the key `altInit`, and the value corresponding to that key is assigned to `altitudeInitial` (passed by reference), which is a `double`; and, assuming success, `true` is returned by `initFromInputFile`. A relevant snippet of `missile.inp` could be ...
```
latInit 33.2385  # Initial latitude in degrees (deg)
lonInit -106.3464  # Initial longitude in degrees (deg)
altInit 10000.0  # Initial altitude in meters (m)
```

## Rules for the input text file
1. The extension of the input text file is insignificant.
2. Only one key-value pair is permitted per line.
3. Each key must *exactly* match the `kKeyName` argument passed to `initFromInputFile`.
4. Each key must be left-aligned, i.e., must not be preceded by white space (unless the `kKeyName` argument passed to `initFromInputFile` contains the same white space, but don't do that).
5. Each key must be unique. Otherwise, only the first instance--with respect to reading from top to bottom, left to right--will be found by the parser.
6. There must be at least one space or (horizontal) tab between each key and its corresponding value.
7. Boolean values must be either `true` or `false`. (`1` and `0`, respectively, are not supported.)
8. String values must be contained within double quotes and must not contain a double quotation mark. For example, ...
   - For the string value `Hey, Bob!`, the file must list `"Hey, Bob!"` after (and on the same line as) the corresponding key
   - `She said, 'Hey, Bob!'` (single quotes) is an acceptable string value, whereas `She said, "Hey, Bob!"` (double quotes) is not
9. No specific character (sequence) denotes the start of a comment, as the parser simply searches for the specified key and then its corresponding value (starting from the character after the last one of the found key). Consequently, a comment can be anything--as long as, starting from the beginning of the line on which the comment begins, (part of) it doesn't match any of the `kKeyName` arguments passed to `initFromInputFile`. For example, ...
```
This is a comment unless one of the specified keys matches (part of) the text of this line, starting from the beginning--e.g., if "This is a comment" is a specified key. HOWEVER, it's best practice to start all comments with a consistent, non-letter (and non-number) identifier.

# This is almost certainly a comment (because no key should start with "#"; you CAN start a key with "#", but don't)

/* This is also almost certainly a comment (because no key should start with "/*"; again, you CAN start a key with "/*", but don't) */
```

## Supported variable types
The following  table lists the supported `kVarType` arguments that can be passed to `initFromInputFile` and the variable type corresponding to each:

| Argument | Type |
| -------- | ---- |
| `"char"` | `char` |
| `"schar"` | `signed char` |
| `"uchar"` | `unsigned char` |
| `"short"` | (`signed`) `short` (`int`) |
| `"ushort"` | `unsigned short` (`int`) |
| `"int"` | (`signed`) `int` |
| `"uint"` | `unsigned int` |
| `"long"` | (`signed`) `long` (`int`) |
| `"ulong"` | `unsigned long` (`int`) |
| `"float"` | `float` |
| `"double"` | `double` |
| `"ldouble"` | `long double` |
| `"bool"` | `bool` |
| `"string"` | `char*` |

## How to use this tool
1. Download the source code from [GitHub](https://github.com/branbick/init-from-input-file) into the appropriate directory on your machine.
2. `#include` the header file `src/init_from_input_file.h` in the C and/or C++ source code you desire to use the aforementioned functionality in.
3. Call `initFromInputFile`--which is declared in the latter header file--with the following arguments, in order:
   1. `const char* kFileName`: The relative or absolute path of the input text file
   2. `const char* kVarType`: The type of the to-be-initialized variable (discussed in the previous section)
   3. `const char* kKeyName`: The name of the key to search the input text file for, corresponding to the value to initialize the to-be-initialized variable with
   4. `void* pVar`: The address of the to-be-initialized variable
4. Incorporate the source files `src/init_from_input_file.c` and `src/init_tools.c` into the build. (The former `#include`s `src/init_tools.h`.)

## Miscellaneous notes
### Compatibility
One of the primary objectives of this project was ensuring 1) compatibility with C *and* C++ and 2) backward compatibility. Hence, this tool is written in [ANSI C](https://en.wikipedia.org/wiki/ANSI_C) and compatible with [C++17](https://en.wikipedia.org/wiki/C%2B%2B17).

### User responsibilities
Due to the nature of C, as well as various deliberate design decisions made for the sakes of both efficiency and simplicity, this tool grants the user power, which must be accompanied by responsibility. That being said, some noteworthy user responsibilities are as follows:
- Ensure the type of the to-be-initialized variable is capable of accurately storing the corresponding value listed in the input text file. For example, concerning C code, the value corresponding to an `int` must be inclusively between `INT_MIN` and `INT_MAX`, which are machine-dependent and `#define`d in `limits.h`. (Otherwise, integer overflow--which may lead to undefined behavior--or loss of precision will occur.)
- Regarding strings, ensure sufficient memory is allocated for the to-be-initialized variable based on the length of the corresponding value listed in the input text file. For example, the variable corresponding to the value `Hey, Bob!` must be able to hold (at least) ten `char`s--including the null terminator--and, therefore, be defined (in C code specifically) as either `char str[10]` or `char* str = malloc(10 * sizeof(char))`. [Otherwise, you'll end up "touching" memory you shouldn't and (hopefully!) be presented with an error.]
- As previously mentioned, ensure string values listed in the input text file both start and end with a double quotation mark. [If the opening one isn't included, the first `char` of the value will be skipped; and, if the closing one isn't included, you'll likely end up "touching" memory you shouldn't and definitely encounter an `initFromInputFile` failure.]
- Check `initFromInputFile`'s return value; don't just assume it worked. There are many things--both machine and user faults (e.g., a memory shortage and an inconspicuous typo, respectively)--that can cause it to fail.

### Error insight
If the macro `PRINT_ERRORS` is `#define`d, then a message containing the following information is written to the output stream `stderr`--which is normally directed to the screen by default--whenever an error is encountered:
1. Name of the source file in which the error occurred
2. Line number on which it occurred
3. `kFileName` argument passed to `initFromInputFile`
4. `kKeyName` argument passed to `initFromInputFile`

Detailed error messages greatly help with debugging. If you decide to not always `#define PRINT_ERRORS`, you should *absolutely* do so if `initFromInputFile` has returned `false`.

## Unit testing
Every function that's unique to this tool--i.e., not part of the [standard library](https://en.wikipedia.org/wiki/C_standard_library)--has been thoroughly unit tested using [GoogleTest](https://github.com/google/googletest) (framework) paired with [CMake](https://cmake.org/) (build system).

### How to run the unit tests*
`cd` into the `test` directory and execute `./run_tests.sh`, which triggers all the `run_test.sh` scripts located in the following subdirectories:
1. `init_from_input_file/non_static_fxns`
2. `init_from_input_file/static_fxns`
3. `init_tools/non_static_fxns/other`
4. `init_tools/non_static_fxns/printError`
5. `init_tools/static_fxns`

\* Only works on Linux

### Future improvements
- Add preprocessor directives that allow the tests to run with or without `PRINT_ERRORS` `#define`d
   - Currently, all but one of the unit tests only work if `PRINT_ERRORS` is *not* `#define`d
   - `init_tools_non_static_fxns_printError_test` inherently requires `PRINT_ERRORS` to be `#define`d
- Try to use [test fixtures](https://google.github.io/googletest/primer.html#same-data-multiple-tests) to avoid code duplication
- Regarding the `run_test.sh` scripts, figure out how to get (or construct) the names of the `.cpp` files so they don't have to be hard-coded
