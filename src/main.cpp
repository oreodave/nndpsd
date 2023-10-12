/* Copyright (C) 2023 Aryadev Chavali

 * You may distribute and modify this code under the terms of the
 * GPLv2 license.  You should have received a copy of the GPLv2
 * license with this file.  If not, please write to:
 * aryadev@aryadevchavali.com.

 * Created: 2023-10-11
 * Author: Aryadev Chavali
 * Description: The entrypoint to the program.
 */

#include <cstdint>
#include <iostream>

using std::cout, std::endl;

using byte = std::uint8_t;
using u16  = std::uint16_t;
using u64  = std::uint64_t;
using i64  = std::int64_t;

struct Machine
{
  u64 clock;
  u16 PC;
  byte A, X, Y, S;
  byte P : 7;

  byte *program;
  byte memory[1 << 17]; // 64 KB

  constexpr bool N(void)
  {
    return (P & 0b10000000);
  }

  constexpr bool V(void)
  {
    return (P & 0b01000000);
  }

  constexpr bool B(void)
  {
    return (P & 0b00010000);
  }

  constexpr bool D(void)
  {
    return (P & 0b00001000);
  }

  constexpr bool I(void)
  {
    return (P & 0b00000100);
  }

  constexpr bool Z(void)
  {
    return (P & 0b00000010);
  }

  constexpr bool C(void)
  {
    return (P & 0b00000001);
  }
};

int main(void)
{
  cout << "Hello, world!" << endl;
  return 0;
}
