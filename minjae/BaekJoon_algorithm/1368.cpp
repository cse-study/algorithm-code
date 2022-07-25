#include <iostream>
#include <string>
#include <vector>
#include <queue> // prim's algorithm minimum spanning tree
#include <bits/stdc++.h> // ## 자기자신에게 물을 댄다는것 -> 새로운 n+1 vertex를 만들어서 거기로 연결시켜 그래프를 모델링하는것이 키포인트!
// 왜 시간초과가 나는지 모르겠지만... 고민해도 모르겠다 ㅠㅠㅠㅠ 그래서 일단 남긴다!
using namespace std;
vector<pair<int,int> > adj[305];
bool chk[305];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n,c; cin >> n;
    for(int i=1; i<=n; i++){
        cin >> c;
        adj[i].push_back(make_pair(c,n+1)); // 자기자신 연결을 새로운 vertex로 연결로 생각
        adj[n+1].push_back(make_pair(c,i));
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> c;
            if(c != 0){
                adj[i].push_back(make_pair(c,j));
            }
        }
    }
    int cnt=0, ans=0;
    priority_queue<tuple <int,int,int>, vector<tuple<int,int,int> >, greater<tuple<int,int,int> > > pq;
    chk[1] = true; // start vertex 1 
    for(auto i : adj[1])    pq.push(make_tuple(i.first, 1, i.second)); // cost, vertex1, vertex2

    while(cnt < n*(n+1)/2-1){ // edge 들의 수 -1
        int cost,a,b;
        tie(cost,a,b) = pq.top(); pq.pop();
        if(chk[b])  continue; // 이미 연결에 포함된 vertex인경우
        ans += cost; 
        cnt++; 
        chk[b]=true;
        for(auto i : adj[b]){
            if(!chk[i.second])  pq.push(make_tuple(i.first, b, i.second));
        }
    }
    cout << ans;
}