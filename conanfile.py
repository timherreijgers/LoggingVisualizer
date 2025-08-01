#  Copyright © 2025 Tim Herreijgers
#  Licensed using the MIT license

from conan import ConanFile
from conan.tools.cmake import cmake_layout

class MyProjectConan(ConanFile):
    name = "LoggingVisualizer"
    version = "0.1"
    settings = "os", "compiler", "build_type", "arch"
    requires = [
        "benchmark/1.9.4",
        "fmt/11.2.0",
        "gtest/1.16.0",
        "yaml-cpp/0.8.0",
#        "qt/6.5.3",
    ]
    generators = "CMakeDeps"

    def layout(self):
        cmake_layout(self)
