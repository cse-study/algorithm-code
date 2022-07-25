#include <iostream>
using namespace std;

int GCD(int a, int b){
    if(b == 0)  return a;
    else        return GCD(b, a%b);
}

bool fun(int a, int b){
    if(a == 1 || b == 1)    return true;
    if(GCD(a,b) == 1)   return false;
    else                return true;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int num,cnt,l,h;
    cin >> num;
    for(int c=1; c<=num; c++){
        cin >> cnt >> l >> h;
        int arr[cnt];
        bool check2 = false;
        for(int i=0; i<cnt; i++){
            cin >> arr[i];
        }
        for(int i=l; i<=h; i++){
            int check = 0;
            for(int j=0; j<cnt; j++){
                if(fun(i,arr[j]) == 1)  check++;

            }
            if(check == cnt){
                cout << "Case #" << c << ": " << i << '\n';
                check2 = true;
                break;
            }
        }
        if(check2 == false)  cout << "Case #" << c << ": " << "NO" << '\n';
    }
}