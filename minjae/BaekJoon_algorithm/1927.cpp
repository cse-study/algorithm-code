#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long long heap[1000005];
long long sz = 0;

void push(long long x){
    heap[++sz] = x;
    long long now = sz;
    while( now != 1){ // 부모를 확인하며 조건 끝날때까지 확인
        long long par = now/2;
        if(heap[par] <= heap[now]) break; // 조건 만족하면 그만
        swap(heap[par],heap[now]);        // 조건 만족못하면 바꾸고
        now = par;                        // 다시 아래로가서 탐색
    }
}

long long top(){
    return heap[1]; // 최솟값 바로 반환
}

void pop(){ // 루트의 노드를 삭제한다.(힙은 루트노드만 삭제)
    heap[1] = heap[sz--];
    long long now = 1;
    while(2*now <= sz){ // 왼쪽 자식의 인덱스가 sz보다 크면 이미 now는 리프이다. 리프면 그만돈다.
        long long lc = 2*now; long long rc= 2*now+1; // 왼쪽 오른쪽 자식도느 정의
        long long min_c = lc; // 자식중 작은값을 아래의 if문을 통해 mic_c에 저장 -> 나중에 부모와 비교해서 교환
        if(rc <= sz && heap[rc] < heap[lc]) min_c = rc;
        //else                                min_c = lc;

        if(heap[now] <= heap[min_c])        break; // 만족하면 종료
        swap(heap[now], heap[min_c]);
        now = min_c; // 쭉 아래로 내려감
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    long long n,k; cin >> n;
    for(long long i=0; i<n; i++){
       cin >> k;
       if(!k && sz == 0)    cout << 0 << '\n'; // 빈큐일때도 처리해줘야 한다.
       else if(k == 0){
           cout << top() << '\n';
           pop();
       }
       else{
           push(k);
       }
    }
}