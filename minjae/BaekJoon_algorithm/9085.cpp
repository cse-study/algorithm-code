#include <iostream> 
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n,f,s;
    cin >> n;
    while(n--){
        cin >> f;
        int sum=0;
        while(f--){
            cin >> s;
            sum += s;
        }
        cout << sum << '\n';
    }
    
}