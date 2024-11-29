#!/bin/sh

cmake -S .. -B ../build-coverage -G Ninja -DCMAKE_PREFIX_PATH=<path/to/qt/cmake> \
      -DCMAKE_C_FLAGS=--coverage -DCMAKE_CXX_FLAGS=--coverage
pushd ../build-coverage
ninja
ctest
popd
pushd ..
rm -rf coverage
mkdir coverage
gcovr -e third_party -e build-coverage -e ".*tests.*" -e ".*mocks.*" --html-details coverage/test.html
popd
