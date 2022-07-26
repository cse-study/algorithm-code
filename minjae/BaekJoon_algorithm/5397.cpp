#include <iostream>
#include <string>
#include <list> // 텍스트 에디터는 리스트가 효율적이다.
using namespace std;


int main(){
    int n;
    cin >> n;

    for(size_t i=0; i<n; i++){
        string a;
        cin >> a;

        list<char> L={};
        for (auto c : a)
            L.push_back(c);

        list<char> K = {};
        auto cursor = K.end();
        for (auto c : L){
            if(c == '<'){
                if(cursor != K.begin())
                    cursor--;
            }
            else if(c =='>'){
                if(cursor != K.end())
                    cursor++;
            }
            else if(c == '-'){
                if(cursor != K.begin()){
                    cursor--; // 오른쪽을 지움으로 cursor 하나 왼쪽으로 옮기고 지운다.
                    cursor = K.erase(cursor); // 이거안하면 출력초과뜸.
                }
            }
            else{
                K.insert(cursor, c);
            }
        }

        for (auto c : K)
            cout << c;
        
        cout << '\n';
    }
}