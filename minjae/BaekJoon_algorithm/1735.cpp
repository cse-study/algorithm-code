#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c,d;
    cin >> a >> b;
    cin >> c >> d;

    int r_t = a*d + b*c; // ac+bd/cd
    int r_b = b*d;
    
    for(int i=2; i<=min(r_t,r_b); i++){ // 약분
        if(r_t %i==0 && r_b%i ==0)
            while(r_t %i==0 && r_b%i ==0){
                r_t /= i;
                r_b /= i;
            }
    }
    cout << r_t << " " << r_b;
}