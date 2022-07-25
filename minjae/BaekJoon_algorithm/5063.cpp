#include <iostream> 
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n,r,e,c;
    cin >> n;
    while(n--){
        cin >> r >> e >> c;
        if(r == e-c)        cout << "does not matter" << '\n';
        else if (r > e-c)   cout << "do not advertise" << '\n';
        else                cout << "advertise" << '\n';
    }
}