#include <iostream>
using namespace std;

int main(){
	
	int n;
	cin>>n;
	
	int num[n+1];
	int min = 1000000;
	int max = -1000000;
	
	for(int i=0; i<n; i++){
		cin >> num[i];
		if(min > num[i]){
			min = num[i];
		}
		if(max < num[i]){
			max = num[i];
		}
	}
	
	cout << min << " " << max << "\n";
	
	return 0;
}