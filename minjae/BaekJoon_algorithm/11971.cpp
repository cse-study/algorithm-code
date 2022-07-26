#include <iostream>
using namespace std;

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin >> n >> m;
	int limit[101], speed[101];
	int a,b;

	int temp_n[n+1], temp_m[m+1];
	temp_n[0] = 0, temp_m[0]=0;
	for(int i=1; i<=n; i++){
		cin >> a >> b;
		temp_n[i] = temp_n[i-1] + a;
		for(int j = temp_n[i-1]; j<temp_n[i]; j++){ 
		// 문제를 예로 들면 int j = 0; j<40, 한바퀴돌고 j=40; j<90, 한바퀴돌고 j=90; j<100
			limit[j] = b;
		}
	}

	for(int i=1; i<=m; i++){
		cin >> a >> b;
		temp_m[i] = temp_m[i-1] + a;
		for(int j = temp_m[i-1]; j<temp_m[i]; j++){
			speed[j] = b;
		}
	}

	int max_v=0;
	for(int i=0; i<100; i++){
		max_v = max(max_v, speed[i] - limit[i]); // 0~100km 중 가장 큰 속도차이를 찾는다.
	}
	cout << max_v;
}