#include <iostream>
using namespace std;  // dp로 푼다. 

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n, D[1001];
    cin >> n;

    D[1] = 1;
    D[2] = 3;
    for(size_t i=3; i<=n; i++)
        D[i] = (D[i-1] + (2*D[i-2]))%10007; // 빈칸에 |막대(n-1), =막대(n-2), 네모(n-2)
    cout << D[n];
}
    