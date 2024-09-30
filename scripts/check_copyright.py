import os
import re

copyright_regex = re.compile(r"\/\*\n\s\*\sCopyright\s.\s(\d{4}-*\d{4}|\d*)\sTim\sHerreijgers\n\s\*\sLicensed\susing\sthe\sMIT\slicense\n\s\*\/")

def main():
    all_files_have_valid_copyright = True

    cpp_files = find_all_cpp_files()
    for file in cpp_files:
        if not has_valid_copyright(file):
            all_files_have_valid_copyright = False
            print(f"The file {file} has no valid copyright header")

    if not all_files_have_valid_copyright:
        exit(1)
    exit(0)

def find_all_cpp_files():
    cpp_files = []

    for root, dirs, files in os.walk('.'):
        if is_in_excluded_folder(root):
            continue

        for file in files:
            if file_has_copyright_mandatory_file_extension(file):
                cpp_files.append(os.path.join(root, file))

    return cpp_files

def is_in_excluded_folder(root: str):
    ignored_folders = ["build", "third_party", ".git", ".idea", "scripts", ".github", "cmake"]

    for folder in ignored_folders:
        if folder in root:
            return True

    return False

def file_has_copyright_mandatory_file_extension(file: str):
    file_extensions = [".cpp", ".h", ".cxx", ".cc", ".hpp", ".c"]

    for file_extension in file_extensions:
        if file.endswith(file_extension):
            return True

    return False

def has_valid_copyright(path: str):
    file_content = open(path, "r", encoding="utf-8").read()
    return copyright_regex.match(file_content)

if __name__ == "__main__":
    main()