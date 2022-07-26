#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int n; cin >> n;
    string name;
    int kor, math, eng;
    vector<tuple<int,int,int,string> > V;

    for(int i=0; i<n; i++){
        cin >> name >> kor >> math >> eng;
        V.push_back(tuple<int,int,int,string>(-kor,math,-eng,name));
        // 감소한다는것은 큰것부터 작아짐으로 - 를 붙여준다. tuple, pair는 첫째원소부터 알아서 자동정렬한다.
    }

    sort(V.begin(), V.end());
    for(auto i : V) cout << get<3>(i) << '\n'; // get<3>(i) 는 세번째 원소 출력 

    return 0;
}