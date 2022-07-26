#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int arr_a[101],arr_b[101];
    string a,b,u;
    cin >> a;
    cin >> u;
    cin >> b;

    if(u == "*"){
        cout << "1";
        for(size_t i=1; i<=a.size()+b.size()-2; i++){
            cout <<"0";
        }
    }
    
    if(u == "+"){
        if(a.size()==b.size()){
            cout << 2;
            for(size_t i=1; i<=a.size()-1; i++){
                cout <<"0";
            }
        }
        if(a.size()>b.size()){
            cout << "1";
            for(size_t i=1; i<=a.size()-b.size()-1; i++)
                cout << "0";
            cout << "1";
            for(size_t i=1; i<=b.size()-1; i++)
                cout << "0";
        }
        if(a.size()<b.size()){
            cout << "1";
            for(size_t i=1; i<=b.size()-a.size()-1; i++)
                cout << "0";
            cout << "1";
            for(size_t i=1; i<=a.size()-1; i++)
                cout << "0";
        }
    }
}