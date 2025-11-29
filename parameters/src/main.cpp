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
#include <string_view>

int main(int argc, char* argv[])
{
  std::span<char*> params{ argv, static_cast<uint32_t>(argc) };

  std::string_view input_file;
  std::string_view output_file;

  bool expected_input_file = false;
  bool expected_output_file = false;

  bool decompress = false;

#pragma unroll 2
  for (std::string_view param : params)
  {
    if (params.size() == 1 || param == "-h" || param == "--help")
    {
      std::cout << "USAGE:" << "\n"
                << "\t" << params[0] << " -i input_file -o output_file -d"
                << "\n";
      return 0;
    }
    if (expected_input_file)
    {
      input_file = param;
      expected_input_file = false;
      continue;
    }
    if (expected_output_file)
    {
      output_file = param;
      expected_output_file = false;
      continue;
    }
    if (param == "-i")
    {
      expected_input_file = true;
      continue;
    }
    if (param == "-o")
    {
      expected_output_file = true;
      continue;
    }
    if (param == "-d")
    {
      decompress = true;
      continue;
    }
  }
  std::cout << input_file << "\n" << output_file << "\n";
}
