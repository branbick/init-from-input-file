# init-from-input-file
## Introduction
`init-from-input-file` allows C and C++ variables to be initialized from an input text file, consequently **eliminating the need to recompile** source code merely due to a changed initialization value. For example, consider a simulation of an air-launch missile. Instead of writing ...
```
const double kAltitudeInitial = 10000.0;  /* meters (m) */
```
where the right-hand side (i.e., floating constant / floating-point literal) must be updated for different scenarios, requiring recompilation of the source code after every update, write ...
```
double altitudeInitial;  /* meters (m) */
const bool kSuccessFlag = initFromInputFile("missile.inp", "double", "altInit", &altitudeInitial);
```
where `init_from_input_file.h` (and, for C code, `stdbool.h`) must be `#include`d. Breaking down the above, the input text file `missile.inp` is searched for the key `altInit`, and the value corresponding to that key is assigned to `altitudeInitial` (passed by reference), which is a `double`; and, assuming success, `true` is returned by `initFromInputFile` and assigned to `kSuccessFlag`. A snippet of `missile.inp` could look like the following:
```
latInit 33.2385  # Initial latitude in degrees (deg)
lonInit -106.3464  # Initial longitude in degrees (deg)
altInit 10000.0  # Initial altitude in meters (m)
```

## Rules for the input text file
1. The extension of the input text file is insignificant
2. Only one key-value pair is permitted per line
3. Each key must *exactly* match the `kKeyName` argument passed to `initFromInputFile`
4. Each key must be left-aligned, i.e., must not be preceded by white space (unless the `kKeyName` argument passed to `initFromInputFile` contains the same white space, but don't do that)
5. Each key must be unique; otherwise, only the first instance--with respect to reading from top to bottom, left to right--will be found by the parser
6. There must be at least one space or (horizontal) tab between each key and its corresponding value
7. String values must be contained within double quotes and cannot themselves contain double quotes--only single quotes; e.g., ...
   - For the value `Hey, Bob!`, the file must list `"Hey, Bob!"` after (and on the same line as) the corresponding key
   - `She said, 'Hey, Bob!'` is an acceptable value, whereas `She said, "Hey, Bob!"` is not

## Supported variable types
The following  table lists the supported `kVarType` arguments that can be passed to `initFromInputFile` and variable type corresponding to each:

| Argument | Type |
| ------ | ---- |
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
1. Download the source code from [GitHub](https://github.com/branbick/init-from-input-file) into the appropriate folder on your machine
2. `#include` the header file `init_from_input_file.h` in the C and/or C++ source code you desire to use the aforementioned functionality in
3. Call `initFromInputFile`--which is declared in the latter header file--with the following arguments, in order:
   1. `const char* kFileName`: The relative or absolute path of the input text file
   2. `const char* kVarType`: The type of the to-be-initialized variable (discussed in the previous section)
   3. `const char* kKeyName`: The name of the key to search the input text file for, corresponding to the value to initialize the to-be-initialized variable with
   4. `void* pVar`: The address of the to-be-initialized variable

## Additional notes
### Compatibility
One of the primary objectives of this project was ensuring 1) compatibility with C *and* C++ and 2) backward compatibility. Hence, this tool is written in [ANSI C](https://en.wikipedia.org/wiki/ANSI_C) and compatible with [C++17](https://en.wikipedia.org/wiki/C%2B%2B17).
