#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
 
int arr[300010];
 
int main(int argc, char *argv[]){
	memset(arr, 0, sizeof(arr));
	arr[0] = 1;
	arr[1] = 1;
 
	for (int i = 2; i < 300000; ++i) {
		if (arr[i] == 1)
			continue;
 
		for (int j = i * 2; j < 300000; j += i)
			arr[j] = 1;
	}
 
	while (1) {
		int x;
		int num = 0;
 
		cin >> x;
 
		if (x == 0) {
			return 0;
		}
 
		for (int i = x + 1; i <= 2 * x; ++i) {
			if (arr[i] == 0)
				++num;
		}
		cout << num << endl;
	}
}