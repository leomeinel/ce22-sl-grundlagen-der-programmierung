/*
 * File: main.cpp
 * Author: Leopold Johannes Meinel (leo@meinel.dev)
 * -----
 * Copyright (c) 2025 Leopold Johannes Meinel & contributors
 * SPDX ID: Apache-2.0
 * URL: https://www.apache.org/licenses/LICENSE-2.0
 */

#include <iostream>
#include <span>
#include <string>
#include <string_view>

int main(int argc, char *argv[]) {
  std::span<char *> parameters{argv, static_cast<uint32_t>(argc)};

  std::string input_file;
  std::string output_file;

  bool expected_input_file = false;
  bool expected_output_file = false;

  bool decompress = false;

  for (std::string_view sv : parameters) {
    if (parameters.size() == 1 || sv == "-h" || sv == "--help") {
      std::cout << "USAGE:" << "\n"
                << "\t" << parameters[0] << " -i input_file -o output_file -d"
                << "\n";
      return 0;
    }
    if (expected_input_file) {
      input_file = sv;
      expected_input_file = false;
      continue;
    }
    if (expected_output_file) {
      output_file = sv;
      expected_output_file = false;
      continue;
    }
    if (sv == "-i") {
      expected_input_file = true;
      continue;
    }
    if (sv == "-o") {
      expected_output_file = true;
      continue;
    }
    if (sv == "-d") {
      decompress = true;
      continue;
    }
  }
  std::cout << input_file << "\n" << output_file << "\n";
}
