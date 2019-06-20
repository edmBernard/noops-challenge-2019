#include <iostream>

// Xorshift32
// Golfed : int main(){for(int x=1,i=1;i<1001;[&]{x^=x<<13;x^=x>>17;x^=x<<5;}(),++i)std::cout<<(x%2?"╱":"╲")<<(i%100?"":"\n");}
int main(int argc, char const *argv[]) {
  std::cout << "Noops Challenge 2019 - Golfbot" << std::endl;
  // ╱ : U+2571
  // ╲ : U+2572

  int x = 1;  // seed
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

