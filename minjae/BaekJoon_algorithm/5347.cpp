#include <iostream>
using namespace std;

long long GCD(long long a, long long b){
    if(b ==0) return a;
    else    return GCD(b,a%b);
}

void LCM(long long a, long long b){
    cout << a*b/GCD(a,b) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    long long n,a,b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        LCM(a,b);
    }
}