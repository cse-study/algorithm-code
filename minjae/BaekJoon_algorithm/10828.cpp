#include <iostream> // stack 구현
using namespace std;

int arr[10001]={};

int main(){
    int n;
    cin >> n;
    int c = 0;
    for(size_t i=0; i<n; i++){
        string a;
        cin >> a;
        if(a == "push"){
            int k;
            cin >> k;
            arr[c] = k;
            c++;
        }
        else if(a == "top"){
            if(c == 0)
                cout << "-1" << '\n';
            else
                cout << arr[c-1] << '\n';
        }
        else if (a == "size"){
            cout << c << '\n';
        }
        else if (a == "empty"){
            if(c == 0)
                cout << "1" << '\n';
            else 
                cout << "0" << '\n';
        }
        else{ // pop
            if(c == 0)
                cout << "-1" << '\n';
            else{
                int r = arr[c-1];
                cout << r << '\n';
                c--;
            }
        }
    }
}