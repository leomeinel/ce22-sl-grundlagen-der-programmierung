#include <algorithm>
#include <iostream>
#include <span>
#include <string>
#include <string_view>
#include <vector>

int main(int argc, char** argv)
{
  std::span<char*> params{ argv, static_cast<uint32_t>(argc) };
  // span ist wie vector, aber auf "fremdem speicher"

  // string_view ist wie string, aber auf "fremdem speicher"
#pragma unroll 2
  for (std::string_view param : params)
  {
    std::cout << param << "\n";
  }

  std::vector<std::string> pi_hosts{ "192.168.0.100", "192.168.0.101", "192.168.0.102" };

  // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
  std::vector<int> numbers0{ 1, 2, 3, 4, 5 };

  // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
  std::vector<std::vector<int>> numbers1{ { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 }, { 1, 2, 3, 4, 5 } };

  // range based for loop
#pragma unroll 2
  for (const std::string& string : pi_hosts)
  {
    std::cout << string << "\n";
  }
  // initializer list
#pragma unroll 2
  for (const std::string& string : { "eins", "zwei", "drei" })
  {
    std::cout << string << "\n";
  }

  // klassischen for loop
#pragma unroll 2
  // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
  for (int i = 0; (i < 10) && (i < pi_hosts.size()); i++)
  {
    std::cout << pi_hosts[i] << "\n";
    pi_hosts[i] = "Foo";
  }

  // late 2000s
  // std::vector<std::string>::iterator it;
#pragma unroll 2
  // NOLINTBEGIN(modernize-loop-convert)
  for (auto it = pi_hosts.begin(); it != pi_hosts.end(); it++)
  {
    if (*it == "192.168.0.101")
    {
      *it = "192.168.1.101";
      break;
    }
  }
  // NOLINTEND(modernize-loop-convert)

  // NOLINTNEXTLINE(modernize-use-ranges, boost-use-ranges)
  auto iter_old = std::find(pi_hosts.begin(), pi_hosts.end(), "192.168.0.101");
  if (iter_old != pi_hosts.end())
  {
    // ich hab den string gefunden!!
    *iter_old = "192.168.1.101";
  }

  auto iter = std::ranges::find(pi_hosts, "192.168.0.101");
  if (iter != pi_hosts.end())
  {
    // ich hab den string gefunden!!
    *iter = "192.168.1.101";
  }

  return 0;
}
