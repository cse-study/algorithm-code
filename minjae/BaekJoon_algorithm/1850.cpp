#include <iostream> // 1의 갯수을 입력받고 그것의 gcd를 구해서 그 값만큼 1의 갯수를 반환한다.
using namespace std;


int gcd(long long a, long long b){
    if (b == 0) return a;
    else{
        return gcd(b, a%b);
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    long long a,b;
    cin >> a >> b;

    int r = gcd(a,b);

    for(size_t i=0; i<r; i++)
        cout << "1";
}