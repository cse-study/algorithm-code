#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	vector<int> grade(5);

	int* result = new int[t];

	for (int i = 0; i < t; i++){
		for (int j = 0; j < 5; j++){
			cin >> grade[j];
		}
		sort(grade.begin(), grade.end());
        
		if (grade[3] - grade[1] >= 4)
			result[i] = -1;
		else
			result[i] = grade[1] + grade[2] + grade[3];
	}

	for (int i = 0; i < t; i++){
		if (result[i] != -1) cout << result[i];
		else cout << "KIN";
		cout << "\n";
	}
	
}