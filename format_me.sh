#
# Copyright © 2024 Tim Herreijgers
# Licensed using the MIT license
#

find . -iname "*.cpp" -not -path "*build*" -not -path "*third_party*" -exec clang-format -style=file -i {} \;
find . -iname "*.hpp" -not -path "*build*" -not -path "*third_party*" -exec clang-format -style=file -i {} \;
find . -iname "*.cc" -not -path "*build*" -not -path "*third_party*" -exec clang-format -style=file -i {} \;
find . -iname "*.cxx" -not -path "*build*" -not -path "*third_party*" -exec clang-format -style=file -i {} \;
find . -iname "*.h" -not -path "*build*" -not -path "*third_party*" -exec clang-format -style=file -i {} \;
