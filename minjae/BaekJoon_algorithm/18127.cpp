#include <iostream> 
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int a,b;
    cin >> a >> b;
    if(b == 0)  cout << '1';
    else if(b == 1)  cout << a;
    else {
        long long result=a;
        for(int i=2; i<=b; i++){
            result += (i+1) + i*(a-3);
        }
        cout << result;
    }
}