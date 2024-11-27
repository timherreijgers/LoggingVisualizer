#! /bin/sh

#
# Copyright © 2024 Tim Herreijgers
# Licensed using the MIT license
#

apt update
apt install -y mesa-common-dev libglu1-mesa-dev freeglut3-dev libxkbcommon-x11-0 libxcb-icccm4 libxcb-image0 libxcb-keysyms1 libxcb-render-util0 libxcb-xinerama0 libxcb-xkb1 libxcb-shape0
# libxkbcommon-x11-0 libxcb-icccm4 libxcb-image libxcb-keysyms libxcb-render_util libxcb-xinerama libxcb-xkb
curl https://d13lb3tujbc8s0.cloudfront.net/onlineinstallers/qt-online-installer-linux-x64-4.8.1.run --output ~/qt-installer.run
chmod +x ./qt-installer.run
./qt-installer.run --root ~/qt_install_dir --email <email> --pw <password> --accept-licenses --default-answer --confirm-command --accept-obligations install qt.qt6.680.linux_gcc_64
ls ~/qt_install_dir/6.8.0
echo -------------------------
ls ~/qt_install_dir/6.8.0/gcc_64/bin
mkdir -p build
cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_PREFIX_PATH=~/qt_install_dir/6.8.0/gcc_64/lib/cmake ..