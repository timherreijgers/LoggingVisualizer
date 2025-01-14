#  Copyright © 2025 Tim Herreijgers
#  Licensed using the MIT license

import utils
import re
from pathlib import Path

def cpp_has_header(cpp_file_name: str, header_files: [str]):
    for header_file in header_files:
        if f"{cpp_file_name}." in header_file:
            return True

    return False

def corresponding_header_is_first(cpp_file: str):
    file_contents = open(cpp_file, "r", encoding="utf-8").read()
    file_name = Path(cpp_file).stem
#    header_regex = re.compile(f"\/\*\n\s\*\sCopyright\s.\s(\d{4}-*\d{4}|\d*)\sTim\sHerreijgers\n\s\*\sLicensed\susing\sthe\sMIT\slicense\n\s\*\/\n*#include.*{file_name}.(hpp|h)")
    header_regex = re.compile(f"\*\/\s\s#include.*{file_name}.(hpp|h)")
    return header_regex.search(file_contents)

def main():
    all_header_files = utils.find_all_files_with_extension([".hpp", ".h"])
    all_cpp_files = utils.find_all_files_with_extension([".c", ".cc", ".cxx", ".cpp"])
    cpp_files_have_correct_first_include = True

    for cpp_file in all_cpp_files:
        file_name = Path(cpp_file).stem
        if cpp_has_header(file_name, all_header_files):
            if not corresponding_header_is_first(cpp_file):
                print(f"File {cpp_file} should include {file_name}.h or {file_name}.hpp as the first include")
                cpp_files_have_correct_first_include = False

    if not cpp_files_have_correct_first_include:
        exit(1)
    exit(0)

if __name__ == "__main__":
    main()