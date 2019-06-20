#include <iostream>

// Xorshift32
int main(int argc, char const *argv[]) {
  std::cout << "Noops Challenge 2019 - Golfbot" << std::endl;
  // ╱ : U+2571
  // ╲ : U+2572

  long x = 53;  // seed
  for (int j = 0; j < 10; ++j) {
    for (int i = 0; i < 100; ++i) {
      x ^= x<<13;
      x ^= x>>17;
      x ^= x<<5;
      std::cout << ((x%2) ? "╱" : "╲");
    }
    std::cout << std::endl;
  }
  return 0;
}

// BLUM BLUM SHUB
// int main(int argc, char const *argv[]) {
//   std::cout << "Noops Challenge 2019 - Golfbot" << std::endl;
//   // ╱ : U+2571
//   // ╲ : U+2572

//   long p = 5651; // must be prime and respect 4m+3 ([i for i in range(10000) if isPrime(i) and i%4==3])
//   long q = 5623; // must be prime and respect 4m+3
//   long x = 53;  // seed must be co prime with p*q
//   for (int j = 0; j < 10; ++j) {
//     for (int i = 0; i < 100; ++i) {
//       x = (x*x)%(p*q);  // Blum Blum Shub pseudorandom number generator
//       std::cout << ((x%2) ? "╱" : "╲");
//     }
//     std::cout << std::endl;
//   }
//   return 0;
// }
