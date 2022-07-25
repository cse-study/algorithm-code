#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a,b;
    int sum=0, m_v = 0;

    cin >> a >> b;
    int st = int(sqrt(a)) + 1;
    if((st-1)*(st-1) == a){
        st -= 1;
    }
    for(int i = st; i<= int(sqrt(b)); i++){
        sum += i*i;
    }
    if(sum == 0){
        cout << -1 << '\n';
    }
    else{
        cout << sum << '\n' << st*st;
    }
    return 0;
}