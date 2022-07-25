#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std; 

int n,a;
vector<int> V;
vector<tuple<int,int,int> > sum;
// 메모리 초과되어 _2를 참고해 아까워서 남겨둠

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a;
        V.push_back(a);
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            sum.push_back(tuple<int,int,int>(abs(V[i]+V[j]),i,j));
        }
    }
    sort(sum.begin(), sum.end());
    cout << V[get<1>(sum[0])] << " " << V[get<2>(sum[0])] <<'\n';

    return 0;
}