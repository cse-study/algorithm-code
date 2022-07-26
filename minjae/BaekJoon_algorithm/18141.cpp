#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[10000]={0};
  
  for (int i=1; i<=n; i++){
    cin >> a[i];
  }

  for (int i=1; i<=n; i++){
    for (int j=i+1; j<=n; j++){
      for (int k=j+1; k<=n; k++){
		
        if (abs(a[i]-a[j])%a[k]!=0){
          cout << "no";
          return 0;
        }
        if (abs(a[i]-a[k])%a[j]!=0){
          cout << "no";
          return 0;
		}
        if (abs(a[j]-a[k])%a[i]!=0){
          cout << "no";
          return 0;
        }
      }
    }
  }
  cout << "yes";
  return 0;
}