#include <iostream>
#include <algorithm>
using namespace std;
int l,c;
char store[16];
char arr[16];
int help[16];
bool isused[16] = {0};

void fun(int cnt){

    if(cnt == l){
        bool check1 = false;
        bool check2 = false;
        for(int i=0; i<l; i++){
            if( arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
                check1 = true;
        }
        int count = 0;
        for(int i=0; i<l; i++){
            if( arr[i]=='b'||arr[i]=='c'||arr[i]=='d'||arr[i]=='f'||arr[i]=='g'||arr[i]=='h'||arr[i]=='j'||arr[i]=='k'||arr[i]=='l'||arr[i]=='m'||arr[i]=='n'||arr[i]=='p'||arr[i]=='q'||arr[i]=='r'||arr[i]=='s'||arr[i]=='t'||arr[i]=='v'||arr[i]=='w'||arr[i]=='x'||arr[i]=='y'||arr[i]=='z')
                count++;
        }
        if(count >= 2)    check2 = true;
        
        if(check1 == true && check2 == true){
            for(int i=0; i<l; i++){
                cout<< arr[i];
            }
            cout << '\n';
        }
        return;
    }

    int start = 0;
    if(cnt != 0 )   start = help[cnt-1]+1;
    for(int i=start; i<c; i++){
        if(!isused[i]){
            isused[i] = true;
            help[cnt] = i;
            arr[cnt] = store[i]; // arr[i] X, arr[cnt] O
            fun(cnt+1);
            isused[i] = false;
        }
    }
}

int main(){
    cin >> l >> c;
    for(int i=0; i<c; i++){
        cin >>  store[i];
    }
    sort(store, store+c);
    fun(0);
    return 0;
}