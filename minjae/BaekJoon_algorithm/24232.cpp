#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

struct NODE {
	int vertex;
	bool flag;
	int index;
};

int n;
vector<vector<NODE> > Edge(100005, vector<NODE>());
vector<bool> Flip(100005, 0);
vector<bool> result(100005, 0);
int bigg = 2e9;

int Init(int node, int prev) {
	int sum = 0;
	for(int i=0; i<Edge[node].size(); i++){
		int next = Edge[node][i].vertex;
		bool flag = Edge[node][i].flag;
		int index = Edge[node][i].index;
		if (next == prev) continue;
		Flip[index] = flag;
		sum += Init(next, node) + flag;
	}
	return sum;
}

void DFS(int node, int prev, int flip_cnt) {
	if (bigg > flip_cnt) {
		bigg = flip_cnt;
		for(int i=0; i<n-1; i++){
			result[i] = Flip[i];
		}
	}
	for(int i=0; i<Edge[node].size(); i++){
		int next = Edge[node][i].vertex;
		bool flag = Edge[node][i].flag;
		int index = Edge[node][i].index;
		if (next == prev) continue;
		if (flag) {
			Flip[index] = 0;
			DFS(next, node, flip_cnt - 1);
			Flip[index] = 1;
		}
		else if (!flag) {
			Flip[index] = 1;
			DFS(next, node, flip_cnt + 1);
			Flip[index] = 0;
		}
	}
}

int main() {
	cin >> n;
	for(int i=0; i<n-1; i++){
		int u, v;
		cin >> u >> v;
		Edge[u].push_back({ v, 0, i });
		Edge[v].push_back({ u, 1, i });
	}
	int flip_cnt = Init(1, 0);
	DFS(1, 0, flip_cnt);
	for(int i=0; i<n-1; i++){
		cout << result[i];
	}
} 