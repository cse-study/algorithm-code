#include <iostream>
#include <queue>
using namespace std;

int dx[2] = {1,-1};
int dist[100002];

int main(){
    int n,k;
    cin >> n >> k;

    queue <int> Q;
    Q.push(n);
    fill(dist,dist+100001,-1);
    dist[n]=0;

    while(dist[k] == -1){ // until meet young boy
        int cur = Q.front();
        Q.pop();
        for(int i=0; i<3; i++){
            int nx = cur;
            if(i==2){
                nx = cur*2;
            }
            else{
                nx = cur + dx[i];
            }
            if(nx < 0 || nx >100000)  continue;
            if(dist[nx] != -1)       continue;
            dist[nx] = dist[cur] + 1;
            Q.push(nx);
        }
    }
    cout << dist[k];
    
}