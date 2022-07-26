#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string a,b;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> a >> b;
    int na = a.size(), nb = b.size();
    int arr[na+5][nb+5];

    fill(&arr[0][0], &arr[na+1][nb+1], 0); // 뭔가 이상해서 그냥 한칸더 0으로 채움..

    for(int i=1; i<=na; i++){
        for(int j=1; j<=nb; j++){
            if(a[i-1] == b[j-1]) arr[i][j] = arr[i-1][j-1] + 1; // a[0]이 첫글자이기 때문에 a[i-1] == b[j-1]로한다.
            else{
                arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }
    cout << arr[na][nb]; // 맨끝이 그길이를 나타냄

}