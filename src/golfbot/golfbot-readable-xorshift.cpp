#include <iostream>

// Xorshift32
int main(int argc, char const *argv[]) {
  std::cout << "Noops Challenge 2019 - Golfbot" << std::endl;
  // ╱ : U+2571
  // ╲ : U+2572

  long x = 1;  // seed
  for (int j = 0; j < 20; ++j) {
    for (int i = 0; i < 200; ++i) {
      x ^= x<<13;
      x ^= x>>17;
      x ^= x<<5;
      std::cout << ((x%2) ? "╱" : "╲");
    }
    std::cout << std::endl;
  }
  return 0;
}

