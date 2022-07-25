#include <iostream>
using namespace std;

int main() {
  int X;
  cin>>X;

  int a = 0;
  int i = 1;
  for(; a<X; i++){
    a+=i;
  }
  i--;
  int numerator;
  int denominator;
  int t = a-X;
  if(i%2 == 1){
    numerator = 1+t;
    denominator = i-t;
  }
  else{
    numerator = i-t;
    denominator = 1+t;
  }

  cout<<numerator<<"/"<<denominator<<'\n';
}
