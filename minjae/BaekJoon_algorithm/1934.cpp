#include <iostream>
using namespace std;

int gcd_fun(int a, int b){
	if (b == 0) 
		return a;
	else
		return gcd_fun(b, a % b);
}

int main(){
    int n;
    cin >> n;
    for(size_t i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        cout <<  a*b/gcd_fun(a,b) << '\n';
    }

}