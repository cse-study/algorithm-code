#include <iostream> 
using namespace std;

unsigned long long get_p(unsigned long long init, unsigned long long time, unsigned long long addp, unsigned long long total_time){
    unsigned long long p = init;
    unsigned long long charge;
    if(total_time % time == 0)  charge = total_time/time -1;
    else                        charge = total_time/time;

    p += (1+charge)*addp*charge/2;
    return p;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    unsigned long long n,q,p,k,c;
    cin >> n >> q;
    unsigned long long min_v=10000000000;
    unsigned long long idx;
    for(unsigned long long i=1; i<=n; i++){
        cin >> p >> k >> c;
        if(min_v > get_p(p,k,c,q)){
            min_v = get_p(p,k,c,q);
            idx = i;
        }
    }
    cout << idx << " " << min_v;
}