#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first > b.first;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int n, cnt;
    vector<pair<int, int> > V; // {cnt, num} 정렬은 처음것 우선임으로
    cin >> n >> cnt;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        bool check = false;
        for(auto &a : V){
            if(a.second == num){ //2번째 페어가 num 이다...!
                check = true;
                a.first++; // increase cnt
                break;
            }
        }
        if (!check){ // 처음이거나 숫자가 달라졌을때
            V.push_back(pair<int,int>(1,num));
        }
    }
    stable_sort(V.begin(), V.end(), cmp); // cmp를 안써주면 2번째 페어까지 생각해 전부 정렬이 된다. 그래서 cmp를 쓴다.
    //reverse(V.begin(), V.end());
    
    vector<pair<int, int> >::iterator iter;
    // for(iter = V.begin(); iter != V.end(); iter++){
    //     cout << "[" << iter->first << "," << iter->second << "]" << endl;
    // }

    for(iter = V.begin(); iter != V.end(); iter++){
        for(int i=0; i < iter->first; i++){
            cout << iter -> second << " ";
        }
    }

    return 0;
}