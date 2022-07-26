#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; // floyd algorithm

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n,m; cin >> n >> m;
    int a,b,c;
    int arr[105][105];
    for(int i=1;i<=n; i++){
        fill(arr[i], arr[i]+1+n, 100000000);
    }
    int record[105][105]; // 최단거리 경로 기록을 위한 array
    for(int i=1; i<=n; i++){
        fill(record[i], record[i]+1+n, -1);
    }
    
    while(m--){
        cin >> a >> b >> c;
        // 문제를 보면 1 4 1, 1 4 2 처럼 길이 2개가 주어진다. 그떄는 짧은 거리것을 넣어줘야 하기 때문에, min 함수로 check해준다.
        arr[a][b]=min(c, arr[a][b]);
        record[a][b]=b;
    }
    for(int i=1; i<=n; i++){
        arr[i][i] = 0;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(arr[j][k] > arr[j][i]+arr[i][k]){
                    arr[j][k] = arr[j][i]+arr[i][k]; // 갱신해줌
                    record[j][k] = record[j][i];
                }  
            }
        }
    }

    // output
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(arr[i][j] == 100000000)  cout << 0 << " "; // 갈수 없는 경우 input 2 1 1 2 1로 테스트 했을때 inf나오는거 방지
            else                        cout << arr[i][j] << " ";
        } 
        cout << '\n';
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(arr[i][j] == 0 || arr[i][j] == 100000000){
                cout << 0 << '\n';
                continue;
            }  
            else{
                vector<int> path;
                int st = i;
                while(st != j){ // until path is end
                    path.push_back(st);
                    st = record[st][j];
                }
                path.push_back(j);
                cout << path.size() << " ";
                for(auto i : path)  cout << i << " ";
                cout << '\n';
            }
        }
    }
}