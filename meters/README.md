# Introduction
*Meter* is an educational project which shows how to add a custom pragma
to **clang** compiler.

### Example
```
int foo() {
  ...

  double elapsedTime{};

  #pragma meter time elapsedTime usec
  {
    // your code is here
  }

  std::cout << "elapsed time in the region: "
            << elapsedTime
            << ", usec" std::endl;
  ...
}


```


### Installation

Compile LLVM/Clang as usual. For example:
```
mkdir build && cd build
cmake ../llvm -DLLVM_ENABLE_PROJECTS="clang" \
-DCMAKE_BUILD_TYPE=Release \
-DLLVM_ENABLE_ASSERTIONS=On
make -j <num_proc>
```

You may also consider to make use of `GCC_INSTALL_PREFIX` CMake option
if you use GNU Compiler Collection which is installed in a non-default
path
