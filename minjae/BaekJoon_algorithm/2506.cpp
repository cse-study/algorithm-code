#include <iostream> 
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n,k,cnt=0,sum=0;
    cin >> n;
    while(n--){
        cin >> k;
        if(k == 0)  cnt=0;
        else{
            cnt++;
            sum += cnt;
        }
    }
    cout << sum;
}