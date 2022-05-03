#include <iostream>
#include <vector>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> k;
	vector<int> V,P;

    for(size_t i=0; i<=10000000; i++){
        V.push_back(i);
    }
    for(size_t i=2; i*i<=10000000; i++){
        if(V[i] == 0)   continue;
        for(size_t j=2*i; j<=10000000; j+=i){
            V[j] = 0;
        }
    }
    for(size_t i=2; i<=10000000; i++){
        if(V[i] != 0){
            P.push_back(V[i]);
        }   
    }
	cout << P[k-1];
}