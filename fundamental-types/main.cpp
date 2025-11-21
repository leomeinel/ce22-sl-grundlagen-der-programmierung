/*
 * File: main.cpp
 * Author: Leopold Johannes Meinel (leo@meinel.dev)
 * -----
 * Copyright (c) 2025 Leopold Johannes Meinel & contributors
 * SPDX ID: Apache-2.0
 * URL: https://www.apache.org/licenses/LICENSE-2.0
 */

#include <cstdint>
#include <iostream>

void print_type_details(auto var) {
  std::cout << "TypeID: " << typeid(var).name() << "; Size: " << sizeof(var)
            << "b" << "\n";
  // TODO: Also print max_value();
}

struct int_struct {
  const int int_;
  const unsigned int unsigned_int_;
  const int8_t int8_t_;
  const uint8_t uint8_t_;
  // INFO: Can also use long long
  const unsigned long unsigned_long_;
  const uint64_t uint64_t_;
  const unsigned long long unsigned_long_long_;
};

int main(int argc, char *argv[]) {
  int_struct int_struct_ = {0, 1, 2, 3, 4, 5, 6};
  print_type_details(int_struct_.int_);
  print_type_details(int_struct_.unsigned_int_);
  print_type_details(int_struct_.int8_t_);
  print_type_details(int_struct_.uint8_t_);
  print_type_details(int_struct_.unsigned_long_);
  print_type_details(int_struct_.uint64_t_);
  print_type_details(int_struct_.unsigned_long_long_);

  return 0;
}
