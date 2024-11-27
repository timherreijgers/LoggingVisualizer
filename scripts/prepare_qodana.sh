#! /bin/sh

sudo apt update
sudo apt install -y qt6-base-dev

mkdir -p build
cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..

python3 ../scripts/filter_qodana_paths.py