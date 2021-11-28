#!/bin/bash

ROOT="$(realpath ../../../llvm-11.0/build)"

export CC=${ROOT}/bin/clang
export CXX=${ROOT}/bin/clang++
export PATH=${ROOT}/bin:${PATH}
export LD_LIBRARY_PATH=${ROOT}/lib:${LD_LIBRARY_PATH}
export LIBRARY_PATH=${ROOT}/lib:${LIBRARY_PATH}
