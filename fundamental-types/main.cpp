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
#include <limits>
#include <tuple>

template <typename T>
concept is_char_type =
    std::is_same_v<T, char> || std::is_same_v<T, signed char> ||
    std::is_same_v<T, unsigned char>;

using int_tuple =
    std::tuple<int, unsigned int, int8_t, uint8_t, unsigned long, uint64_t,
               unsigned long long, long, int64_t, long long>;

void print_int_details(auto &var) {
  using T = std::remove_reference_t<decltype(var)>;

  constexpr auto min = (is_char_type<T>)
                           ? static_cast<int>(std::numeric_limits<T>::min())
                           : std::numeric_limits<T>::min();
  constexpr auto max = (is_char_type<T>)
                           ? static_cast<int>(std::numeric_limits<T>::max())
                           : std::numeric_limits<T>::max();

  std::cout << "TypeID: " << typeid(var).name() << "; Size: " << sizeof(var)
            << "b"
            << "; Minimum value: " << min << "; Maximum value: " << max << "\n";
}

int main(int argc, char *argv[]) {
  int_tuple integer_types;

  std::apply([](auto &&...args) { ((print_int_details(args)), ...); },
             integer_types);

  return 0;
}
