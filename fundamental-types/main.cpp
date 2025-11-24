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

/**

 */

/**
 * @brief Concept that checks if type T is derived from any char type
 *
 * https://en.cppreference.com/w/cpp/language/templates.html
 *
 * Templates are parameterized by one or more template parameters, of three
 * kinds: type template parameters, constant template parameters, and template
 * template parameters.
 *
 * https://en.cppreference.com/w/cpp/language/templates.html#Syntax
 *
 * - (1) `template <parameter-list > requires-clause (optional) declaration`
 * - (2) `export template<parameter-list > declaration` (until C++11)
 * - (3) (since C++20) `template <parameter-list> concept concept-name =
 * constraint-expression ;` (used here)
 *
 * - `parameter-list`: a non-empty comma-separated list of the template
 * parameters, each of which is either constant parameter, a type parameter, a
 * template parameter, or a parameter pack of any of those (since C++11).
 * - `requires-clause`: (since C++20) a requires-clause that specifies the
 * constraints on the template arguments.
 * - `declaration`: declaration of a class (including struct and union), a
 * member class or member enumeration type, a function or member function, a
 * static data member at namespace scope, a variable or static data member at
 * class scope (since C++14), or an alias template (since C++11). It may also
 * define a template specialization.
 * - `concept-name, constraint-expression`: see
 * https://en.cppreference.com/w/cpp/language/constraints.html (since C++20)
 *
 * https://en.cppreference.com/w/cpp/language/constraints.html
 *
 * Declaration of the concept `derived_from_any_char`, which is satisfied by any
 * type `T` such that its expression `a || b || c` compiles.
 *
 * https://en.cppreference.com/w/cpp/language/constraints.html#Concepts
 *
 * A concept is a named set of requirements. The definition of a concept must
 * appear at namespace scope.
 *
 * @tparam T Any type
 */
template <typename T>
concept derived_from_any_char =
    std::derived_from<T, char> || std::derived_from<T, signed char> ||
    std::derived_from<T, unsigned char>;

/**

 */

/**
 * @brief Type-alias that contains multiple integer types
 *
 * https://en.cppreference.com/w/cpp/language/type_alias.html
 *
 * Type alias is a name that refers to a previously defined type (similar to
 * typedef).
 * Alias template is a name that refers to a family of types.
 *
 * https://en.cppreference.com/w/cpp/language/type_alias.html#Syntax
 *
 * - (1) `using identifier attr (optional) = type-id;` (used here)
 * - (2) `template <template-parameter-list> using identifier attr (optional) =
 * type-id;`
 * - (3) (since C++20) `template <template-parameter-list> requires constraint
 * using identifier attr (optional) = type-id;`
 *
 * - `attr`: optional sequence of any number of attributes
 * - `identifier`: the name that is introduced by this declaration, which
 * becomes either a type name (1) or a template name (2)
 * - `template-parameter-list`: template parameter list, as in template
 * declaration
 * - `constraint`: a constraint expression which restricts the template
 * parameters accepted by this alias template
 * - `type-id`: abstract declarator or any other valid type-id (which may
 * introduce a new type, as noted in type-id). The type-id cannot directly or
 * indirectly refer to identifier. Note that the point of declaration of the
 * identifier is at the semicolon following type-id.
 *
 * https://en.cppreference.com/w/cpp/language/type_alias.html#Explanation
 *
 * - 1) A type alias declaration introduces a name which can be used as a
 * synonym for the type denoted by type-id. It does not introduce a new type and
 * it cannot change the meaning of an existing type name. There is no difference
 * between a type alias declaration and typedef declaration. This declaration
 * may appear in block scope, class scope, or namespace scope.
 * - 2)  An alias template is a template which, when specialized, is equivalent
 * to the result of substituting the template arguments of the alias template
 * for the template parameters in the type-id.
 */
using int_tuple =
    std::tuple<int, unsigned int, int8_t, uint8_t, unsigned long, uint64_t,
               unsigned long long, long, int64_t, long long>;

/**
 * @brief Print details about the type of var
 *
 * This is not type checked but meant for numeric types, specifically integers.
 *
 * @param target Target variable
 */
void print_int_details(auto &target) {
  // We have to remove reference here because type T needs to be initialized
  using T = std::remove_reference_t<decltype(target)>;

  // Get min/max value of target. We need to `static_cast<int>()` if the type is
  // not actually numeric.
  constexpr auto min = (derived_from_any_char<T>)
                           ? static_cast<int>(std::numeric_limits<T>::min())
                           : std::numeric_limits<T>::min();
  constexpr auto max = (derived_from_any_char<T>)
                           ? static_cast<int>(std::numeric_limits<T>::max())
                           : std::numeric_limits<T>::max();

  // Print details
  std::cout << "TypeID: " << typeid(target).name()
            << "; Size: " << sizeof(target) << "b"
            << "; Minimum value: " << min << "; Maximum value: " << max << "\n";
}

/**
 * @brief Main class
 *
 * @param argc Number of arguments
 * @param argv List of arguments
 * @return int Success value
 */
int main(int argc, char *argv[]) {
  // Initialize tuples
  int_tuple integer_types;

  // Loop through integer tuple
  std::apply([](auto &&...args) { ((print_int_details(args)), ...); },
             integer_types);

  return 0;
}
