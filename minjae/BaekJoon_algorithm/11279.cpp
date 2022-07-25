#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int heap[100005];
int sz = 0;

void push(int x){
    heap[++sz] = x;
    int now = sz;
    while( now != 1){ // 부모를 확인하며 조건 끝날때까지 확인
        int par = now/2;
        if(heap[par] >= heap[now]) break; // 조건 만족하면 그만
        swap(heap[par],heap[now]);        // 조건 만족못하면 바꾸고
        now = par;                        // 다시 아래로가서 탐색
    }
}

int top(){
    return heap[1]; // 최댓값 바로 반환
}

void pop(){ // 루트의 노드를 삭제한다.(힙은 루트노드만 삭제)
    heap[1] = heap[sz--];
    int now = 1;
    while(2*now <= sz){ // 왼쪽 자식의 인덱스가 sz보다 크면 이미 now는 리프이다. 리프면 그만돈다.
        int lc = 2*now; int rc= 2*now+1; // 왼쪽 오른쪽 자식도느 정의
        int max_c = lc; // 자식중 큰값을 아래의 if문을 통해 mic_c에 저장 -> 나중에 부모와 비교해서 교환
        if(rc <= sz && heap[rc] > heap[lc]) max_c = rc;
        //else                                max_c = lc;

        if(heap[now] >= heap[max_c])        break; // 만족하면 종료
        swap(heap[now], heap[max_c]);
        now = max_c; // 쭉 아래로 내려감
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n,k; cin >> n;
    for(int i=0; i<n; i++){
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