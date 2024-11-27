#!/usr/bin/env python3
import json
import os
from pathlib import Path

# Read existing compile_commands.json ------------------------------------------
REPO_ROOT = Path(os.path.dirname(Path.cwd()))
print(REPO_ROOT)
COMPILE_COMMANDS_PATH = REPO_ROOT / "build/compile_commands.json"

print(f"Opening file {COMPILE_COMMANDS_PATH}")
with open(COMPILE_COMMANDS_PATH, "r", encoding="utf-8") as fd:
    print("Opened file")
    compile_commands = json.load(fd)

# Filter source files ----------------------------------------------------------
from itertools import chain

EXCLUDE_GLOBS = [
    "third_party/**/*",
]
allowed_paths = (REPO_ROOT.glob(pattern) for pattern in EXCLUDE_GLOBS)
allowed_paths = set(chain.from_iterable(allowed_paths))

# Invert the list of paths -----------------------------------------------------
allowed_paths = set(REPO_ROOT.rglob("*")) - allowed_paths

def keep_condition(cc_entry: dict):
    path = Path(cc_entry["file"])
    return path in allowed_paths

compile_commands = list(filter(keep_condition, compile_commands))

# Save the updated list of source files ----------------------------------------
COMPILE_COMMANDS_PATH.rename(COMPILE_COMMANDS_PATH.with_suffix(".old.json"))
with open(COMPILE_COMMANDS_PATH, "w", encoding="utf-8") as fd:
    json.dump(compile_commands, fd, ensure_ascii=False, indent="\t")