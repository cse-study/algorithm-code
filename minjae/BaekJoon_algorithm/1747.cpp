#include <iostream>
#include <vector>
using namespace std;
#define MAX 1100000

int arr[MAX+1];
vector<int> V;

bool check(int n){ // check if prime is palindrome num.
    if(n%10 == 0)   return false;
    int tar=0,temp, cmp = n;    
    while(1){
        temp = n%10;
        tar = 10*tar + temp;
        n /= 10;
        if(n == 0)  break;
    }
    if(cmp == tar)  return true;
    else    return false;
}

void make_palindrome(){
    for(int i=2; i<=MAX; i++){
        arr[i] = i;
    }
    for(int i=2; i*i<=MAX; i++){
        if(arr[i] == 0) continue;
        for(int j=2*i; j<=MAX; j+=i)    arr[j]=0;
    }
    for(int i=2; i<=MAX; i++){
        if(arr[i] != 0 && check(arr[i]) == true)    V.push_back(i); 
        // num is prime and palin, then push back num to vector
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    make_palindrome();
    
    for(int i=0; i<V.size(); i++){
        if(V[i]>=n){
            cout << V[i];
            break;
        }
    }
}