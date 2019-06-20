#include<iostream>
int main(){for(int x=53,i=1;i<1001;x=x*x%31775573,++i)std::cout<<(x%2?"╱":"╲")<<(i%100?"":"\n");}
