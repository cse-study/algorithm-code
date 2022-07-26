#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    getline(cin, a); // 전체를 받음
    int c=1; // 단어 1개로 시작
    for (int i=0; i<a.length(); ++i){
        int n =0;

        n = a.at(i);
        if (n == 32){ // space바가 있으면 
            c++;
        }
    }
    if( (int)a.at(0) == 32 ){
        c = c-1; // 처음에 스페이스로 시작은 단어가 아니다
    }
    if( (int)a.at(a.length()-1) == 32 ){
        c = c-1; // 끝에 스페이스가 있는것은 단어가 아니다
    }
    cout << c << endl;
    return 0;
}
