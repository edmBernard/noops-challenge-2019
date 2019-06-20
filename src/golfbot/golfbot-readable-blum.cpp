#include <iostream>

// Blum Blum Shub
// Golfed : int main(){for(int x=53,i=1;i<1001;x=x*x%(5651*5623),++i)std::cout<<(x%2?"╱":"╲")<<(i%100?"":"\n");}
int main(int argc, char const *argv[]) {
  std::cout << "Noops Challenge 2019 - Golfbot" << std::endl;
  // ╱ : U+2571
  // ╲ : U+2572

  long p = 5651; // must be prime and respect 4m+3 ([i for i in range(10000) if isPrime(i) and i%4==3])
  long q = 5623; // must be prime and respect 4m+3
  long x = 53;  // seed must be co prime with p*q
  for (int j = 0; j < 10; ++j) {
    for (int i = 0; i < 100; ++i) {
      x = (x*x)%(p*q);  // Blum Blum Shub pseudorandom number generator
      std::cout << ((x%2) ? "╱" : "╲");
    }
    std::cout << std::endl;
  }
  return 0;
}
