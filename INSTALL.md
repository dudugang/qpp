# Building instructions for the truly impatient

If you really cannot wait anymore, continue reading the remaining. If you afford to be a bit patient, 
please skip the reminder of this section and read the detailed 
[building instructions for POSIX-compliant systems](https://github.com/vsoftco/qpp/wiki/2.-Building-instructions-for-POSIX-compliant-platforms) 
or 
[Windows](https://github.com/vsoftco/qpp/wiki/3.-Building-instructions-for-Windows-platforms) 
in this Wiki.

## Installing and running under POSIX-compliant systems

In this section I assume that you use a POSIX-compliant system (e.g. UNIX-like).
To get started with [Quantum++](https://github.com/vsoftco/qpp), first
install the [Eigen 3](http://eigen.tuxfamily.org/) library into your home directory, 
as `$HOME/eigen`. You can change the name of the directory, but in the
current document I will use `$HOME/eigen` as the location of the
[Eigen 3](http://eigen.tuxfamily.org/) library. Next, download or clone
[Quantum++](https://github.com/vsoftco/qpp) library into the home
directory as `$HOME/qpp`. Finally, make sure that your compiler supports
C++11 and preferably [OpenMP](http://openmp.org/). As a compiler I
recommend [g++](https://gcc.gnu.org/) version 5.0 or later or
[clang](http://clang.llvm.org) version 3.7 or later (previous versions
of [clang](http://clang.llvm.org) do not support
[OpenMP](http://openmp.org/)). You are now ready to go!

Next, we will build a simple minimal example to test that the installation was
successful. Create a directory called `$HOME/testing`, and inside it
create the file `minimal.cpp`, available for download in 
[`examples/minimal.cpp`](https://github.com/vsoftco/qpp/blob/master/examples/minimal.cpp) and with 
the content listed below.

```CPP
// Minimal example
// Source: ./examples/minimal.cpp
#include <iostream>

#include "qpp.h"

int main() {
    using namespace qpp;
    std::cout << "Hello Quantum++!\nThis is the |0> state:\n";
    std::cout << disp(st.z0) << '\n';
}
```

Next, compile the file using the C++11 compliant compiler. In the
following I assume you use [g++](https://gcc.gnu.org/), but the building
instructions are similar for other compilers. From the directory
`$HOME/testing` type

```bash
g++ -std=c++11 -isystem $HOME/eigen -I $HOME/qpp/include minimal.cpp -o minimal
```

Your compile command may differ from the above, depending on the C++
compiler and operating system. If everything went fine, the above
command should build an executable `minimal` in `$HOME/testing`, which
can be run by typing `./minimal`. The output should be similar to the
following:

```text
Hello Quantum++!
This is the |0> state:
1
0
````

The line

```CPP
#include "qpp.h"
```

includes the main header file of the
library `qpp.h` This header file includes all other necessary internal
[Quantum++](https://github.com/vsoftco/qpp) header files. The line
```CPP
using namespace qpp;
```
injects the [Quantum++](https://github.com/vsoftco/qpp)'s namespace into
the working namespace, so we don't need to prefix the library functions by
`qpp::`. Finally the line 

```CPP
std::cout << disp(st.z0) << '\n';
```

displays the state |0> represented by the Singleton `qpp::st.z0` in a
nice format using the display manipulator `qpp::disp()`.

## Installing and running under [Windows](https://www.microsoft.com/en-us/windows)

Double-click on the [Visual Studio](https://www.visualstudio.com)
solution `VisualStudio.sln` located in the 
[`VisualStudio`](https://github.com/vsoftco/qpp/tree/master/VisualStudio) folder.

---
# Building instructions for POSIX-compliant systems

## Pre-requisites

- Recommended compiler: [g++](https://gcc.gnu.org/) version 5.0 or later
(for good C++11 support)
- [Eigen 3](http://eigen.tuxfamily.org) linear algebra library. I assume here that 
the library is installed in `$HOME/eigen`, although the location may vary, e.g. if 
the libary was installed using a package manager.
- [Quantum++](https://github.com/vsoftco/qpp) library located in `$HOME/qpp`

## Optional

- [CMake](http://www.cmake.org/) version 3.0 or later, highly recommended
- [MATLAB](http://www.mathworks.com/products/matlab/) compiler include header 
files:
`/Applications/MATLAB_R2016a.app/extern/include`
- [MATLAB](http://www.mathworks.com/products/matlab/) compiler shared library 
files:
`/Applications/MATLAB_R2016a.app/bin/maci64`

## Building using [CMake](http://www.cmake.org/) (version 3.0 or later)

The current version of the repository has a 
[`CMakeLists.txt`](https://github.com/vsoftco/qpp/blob/master/CMakeLists.txt)
configuration file for building examples using [CMake](http://www.cmake.org/). 
To build an example using [CMake](http://www.cmake.org/), 
I recommend an out-of-source build, i.e., from the root of the project 
(where the `include` folder is located), type

    mkdir build
    cd build
    cmake ..
    make

The commands above build the release version (default) executable `qpp`, 
from the source file `examples/minimal.cpp`,
without [MATLAB](http://www.mathworks.com/products/matlab/) support (default), 
inside the directory `build`. 

If the location of [Eigen 3](http://eigen.tuxfamily.org) is not detected
automatically by the [CMake](http://www.cmake.org/) build script, 
then the build script will fail (with an error message). In this case 
the location of [Eigen 3](http://eigen.tuxfamily.org) needs to be specified
manually in the [CMake](http://www.cmake.org/) build command line by passing
the `-DEIGEN3_INCLUDE_DIR=path_to_eigen3` flag, e.g.

    cmake .. -DEIGEN3_INCLUDE_DIR=/usr/local/eigen3

To build a different configuration, 
e.g. the debug version with [MATLAB](http://www.mathworks.com/products/matlab/)
support, type from the root of the project

    cd build
    rm -rf *
    cmake -DCMAKE_BUILD_TYPE=Debug -DWITH_MATLAB=ON ..
    make
    
Or, to disable [OpenMP](http://openmp.org/) support (enabled by default), type
   
    cd build
    rm -rf *
    cmake -DWITH_OPENMP=OFF ..
    make

To change the name of the example file or the location of 
[MATLAB](http://www.mathworks.com/products/matlab/) installation, 
edit the [`CMakeLists.txt`](https://github.com/vsoftco/qpp/blob/master/CMakeLists.txt) file. Inspect also [`CMakeLists.txt`](https://github.com/vsoftco/qpp/blob/master/CMakeLists.txt) 
for additional fine-tuning options. Do not forget to clean the `build` 
directory before a fresh build!

## Building without an automatic build system

- Example file: `$HOME/qpp/examples/minimal.cpp`
- Output executable: `$HOME/qpp/examples/minimal`
- You must run the commands below from inside the directory 
`$HOME/qpp/examples` 

### Release version (without [MATLAB](http://www.mathworks.com/products/matlab/) support) 

    g++ -pedantic -std=c++11 -Wall -Wextra -Weffc++ -fopenmp \
         -O3 -DNDEBUG -DEIGEN_NO_DEBUG \
         -isystem $HOME/eigen -I $HOME/qpp/include \
         minimal.cpp -o minimal

### Debug version (without [MATLAB](http://www.mathworks.com/products/matlab/) support)

    g++ -pedantic -std=c++11 -Wall -Wextra -Weffc++ -fopenmp \
         -g3 -DDEBUG \
         -isystem $HOME/eigen -I $HOME/qpp/include \
          minimal.cpp -o minimal

### Release version (with [MATLAB](http://www.mathworks.com/products/matlab/) support)

    g++ -pedantic -std=c++11 -Wall -Wextra -Weffc++ -fopenmp \
         -O3 -DNDEBUG -DEIGEN_NO_DEBUG \
         -isystem $HOME/eigen -I $HOME/qpp/include \
         -I/Applications/MATLAB_R2016a.app/extern/include \
         -L/Applications/MATLAB_R2016a.app/bin/maci64 \
         -lmx -lmat minimal.cpp -o minimal

### Debug version (with [MATLAB](http://www.mathworks.com/products/matlab/) support)

    g++ -pedantic -std=c++11 -Wall -Wextra -Weffc++ -fopenmp \
         -g3 -DDEBUG \
         -isystem $HOME/eigen -I $HOME/qpp/include \
         -I /Applications/MATLAB_R2016a.app/extern/include \
         -L /Applications/MATLAB_R2016a.app/bin/maci64 \
         -lmx -lmat minimal.cpp -o minimal

## Additional remarks

### Building with [Clang++](http://clang.llvm.org/)
- If you use [clang++](http://clang.llvm.org/) version 3.7 or later (previous versions do not have [OpenMP](http://openmp.org/) support) and want 
to use [OpenMP](http://openmp.org/) (enabled by default in the library), make sure to modify 
`CLANG_LIBOMP` and `CLANG_LIBOMP_INCLUDE` in [`CMakeLists.txt`](https://github.com/vsoftco/qpp/blob/master/CMakeLists.txt) so they point to 
the correct location of the [OpenMP](http://openmp.org/) library, as otherwise 
[clang++](http://clang.llvm.org/) will not find `<omp.h>` and the `libomp` 
shared library. Under Linux, you may need to modify also `-fopenmp=...` flag
as well. As such, I do not recommend using [clang++](http://clang.llvm.org/)
with [OpenMP](http://openmp.org/) due to various platform-dependent issues.

### Building with [clang++](http://clang.llvm.org/) on [OS X/macOS](http://www.apple.com/osx)

- I highly recommend to install [clang++](http://clang.llvm.org/) version 3.7 or later via [macports](https://www.macports.org/). 
- If you enable
[MATLAB](http://www.mathworks.com/products/matlab/) support, make sure that 
the environment variable `DYLD_LIBRARY_PATH` is set to point to the 
[MATLAB](http://www.mathworks.com/products/matlab/) 
compiler library location, see the `run_mac_MATLAB.sh` script. 
Otherwise, you get a runtime error similar to  

    > dyld: Library not loaded: @rpath/libmat.dylib.
    
   * I recommend running via a script, as otherwise setting the 
    `DYLD_LIBRARY_PATH` globally may interfere with 
    [macports](https://www.macports.org/)' [CMake](http://www.cmake.org/) 
    installation (in case you use [CMake](http://www.cmake.org/) from 
    [macports](https://www.macports.org/)). If you use a script, 
    then the environment variable is local to the script and 
    does not interfere with the rest of the system.

   * Example of running script, assumed to be located in the root directory 
    of [Quantum++](https://github.com/vsoftco/qpp)
        
            #!/bin/sh
            
            MATLAB=/Applications/MATLAB_R2016a.app
            export DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:$MATLAB/bin/maci64
            
            ./build/qpp

### Building debug versions with [g++](https://gcc.gnu.org/) on [OS X/macOS](http://www.apple.com/osx)

- If you build a debug version with [g++](https://gcc.gnu.org/) and use 
[gdb](http://www.gnu.org/software/gdb/) to step inside template functions 
you may want to add `-fno-weak` compiler flag. See 
<http://stackoverflow.com/questions/23330641/gnu-gdb-can-not-step-into-template-functions-os-x-mavericks>
for more details about this problem.

---
# Building instructions for Windows

## Via [Visual Studio](https://www.visualstudio.com)

- [Quantum++](https://github.com/vsoftco/qpp) contains a full [Visual Studio 2017](https://www.visualstudio.com) 
solution under the folder [`VisualStudio`](https://github.com/vsoftco/qpp/tree/master/VisualStudio). 
The solution 
expects [Eigen 3](http://eigen.tuxfamily.org) to be installed 
under `C:\eigen`. Use this solution at first to get you started. 
A unit testing project (`qpp_testing`) with 
[Google Test 1.8.0](https://github.com/google/googletest) is also 
included in the solution.

-  [Visual Studio](https://www.visualstudio.com) versions preceding 
version 2015 do not have full C++11 support. If you decide to use 
[Visual Studio](https://www.visualstudio.com) make sure you install version
2015 or later. I recommend using 
[Visual Studio 2017](https://www.visualstudio.com).
    
- [Visual Studio 2015/2017](https://www.visualstudio.com) only
supports [OpenMP 2.0](http://openmp.org/). 
[Quantum++](https://github.com/vsoftco/qpp) uses features
from [OpenMP 3.0](http://openmp.org/), hence 
[Quantum++](https://github.com/vsoftco/qpp) will not compile
on [Visual Studio 2015/2017](https://www.visualstudio.com) if you 
`#define WITH_OPENMP_` in your source file and enable 
[OpenMP](http://openmp.org/) (disabled by default) in
    
    *Project/Properties/Configuration Properties/C_C++/Language/Open MP Support*
.
    
## Via [Cygwin](https://www.cygwin.com)

- Use the [same building instructions](https://github.com/vsoftco/qpp/wiki/Building-instructions-for-POSIX-compliant-platforms) as for POSIX systems.
- **Note:** some earlier versions of 
[Cygwin](https://www.cygwin.com) had a bug related to lack of support for some 
C++11 math functions, see
<http://stackoverflow.com/questions/28997206/cygwin-support-for-c11-in-g4-9-2>
for more details. Quick fix: patch the standard library header file `<cmath>` 
using the provided patch [`cmath_cygwin.patch`](https://github.com/vsoftco/qpp/blob/master/cmath_cygwin.patch). 
Later [Cygwin](https://www.cygwin.com) versions seem to have fixed the issue (as of Nov. 2016). 