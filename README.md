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
## Acceptable variable types
## Special notes
### ISO compatibility
