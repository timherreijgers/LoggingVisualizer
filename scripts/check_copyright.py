import utils

def main():
    all_files_have_valid_copyright = True

    cpp_files = utils.find_all_files_with_extension([".cpp", ".h", ".cxx", ".cc", ".hpp", ".c"])
    for file in cpp_files:
        if not has_valid_copyright(file):
            all_files_have_valid_copyright = False
            print(f"The file {file} has no valid copyright header")

    if not all_files_have_valid_copyright:
        exit(1)
    exit(0)

def has_valid_copyright(path: str):
    file_content = open(path, "r", encoding="utf-8").read()
    return utils.copyright_regex.match(file_content)

if __name__ == "__main__":
    main()