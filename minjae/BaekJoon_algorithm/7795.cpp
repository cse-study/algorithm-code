#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    int t; cin >> t;
    while(t--){
        int a,b, na, nb;
        vector<int> A,B;
        cin >> a >> b;
        for(int i=0; i<a; i++){
            cin >> na;
            A.push_back(na);
        }
        for(int i=0; i<b; i++){
            cin >> nb;
            B.push_back(nb);
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int cnt=0;
        for(int i=0; i<a; i++){
            for(int j=0; j<b; j++){
                if(A[i] > B[j]) cnt++;
                else            break;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}