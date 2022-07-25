#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 스택에 넣었다가 빼서 그 뺸것으로 수열을 만든다.

int main(){
    int n,k;
    stack<int> S;
    vector<char> sol;
    int solidx=0;
    int max = 0;

    cin >> n;

    while(n--){
        cin >> k;
        if(k>max){
            for(size_t i=max + 1; i<=k; i++){ // push해야해서 i=1로시작
                S.push(i);
                sol[solidx++] = '+';
            }
        }
        else{
            if(S.top() != k){
                cout << "NO"; // No 가 아니라 NO 였다....
                return 0;
            }
        }
        S.pop(); // 끝난후 빼면서 수열에 넣어줘야 함으로
        sol[solidx++] = '-';
        if (max < k) // 그지점에서 갱신한다.
            max = k;
    }
    for (size_t i=0; i<solidx; i++)
        cout << sol[i] << '\n';

    return 0;
}