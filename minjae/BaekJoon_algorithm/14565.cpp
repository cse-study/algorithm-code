#include <iostream>
#define ll long long
using namespace std;

void EEA(ll a, ll b, ll &s2, ll &t2, ll &r2){ //as + bt = g
	ll q, r1, r, s1, s, t1, t;
	r1 = a, r2 = b; //a = bq +r 제일 처음식
	s1 = 1, s2 = 0, t1 = 0, t2 = 1; // 1a + 0b, 0a + 1b

	while (true){
		q = r1 / r2;
		r = r1 - (q * r2); // r점화식 s점화식 t점화식
		s = s1 - (q * s2);
		t = t1 - (q * t2);

		if (r == 0){ //  finish euclid algorithm 
			// cout << "GCD : " << r2 << '\n'; // 그위의 식들이 답의 값들이다.
			// cout << "S : " << s2 << '\n';
			// cout << "T : " << t2 << '\n';
			break;
		}
		r1 = r2; // 한칸씩 아래로
		r2 = r; 
		s1 = s2; 
		s2 = s;
		t1 = t2;
		t2 = t;
	}
}

int main(){
    ll n,a;
    cin >> n >> a;
    ll s=0, t=0, g=0;

	cout << n-a << " ";
    EEA(n, a, s, t, g);
    if (g !=1)
        cout << "-1" << '\n';
    else{
        if(t<0){
            cout << t+n << '\n';
        }
        else
            cout << t << '\n';
    }
}