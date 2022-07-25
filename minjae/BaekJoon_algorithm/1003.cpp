#include <iostream>
using namespace std;  // dp로 푼다.

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n,num;
    cin >> n;
    int zero[41],one[41];
    zero[0]=1;
    one[0]=0;
    zero[1]=0;
    one[1]=1;
    for(size_t i=2; i<=40; i++){
        zero[i] = zero[i-1]+zero[i-2];
        one[i] = one[i-1]+one[i-2];
    }
    while(n--){
        cin >> num;
        cout << zero[num] << " " << one[num] << '\n';
    }
}