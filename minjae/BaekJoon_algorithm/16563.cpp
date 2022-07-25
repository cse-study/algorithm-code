#include <iostream>
#include <vector>
using namespace std;

const int MAX = 5000000;
int arr[MAX+1];

void era(){
    for (int i = 1; i <= MAX; i++)
        arr[i] = i;
    for(int i=2; i*i<=MAX; i++){
        if(arr[i]==i){
            for(int j= i*i; j<=MAX; j+=i){
                if(arr[j] == j)
                    arr[j]=i;
            }
        }
    }
}

vector<int> P(int x){
    vector<int> res;
    while (x != 1){
        res.push_back(arr[x]);
        x = x/ arr[x];
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n;
    era();

    while(n--){
        cin >> m;
        vector<int> res = P(m);
        for(auto a: res)
            cout << a << " ";
        cout << '\n';
    }
}