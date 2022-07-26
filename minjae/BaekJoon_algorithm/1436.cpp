#include <iostream>
#include <string>
using namespace std;


int res(int n){
    int i = 666;
    int series =0;
    string target;
    while (1){
        target = to_string(i);
        for(int j=0; j<target.length()-2; j++)
            if(target[j] == '6' && target[j+1] == '6' && target[j+2] == '6'){
                series +=1;
                if(series == n)
                    return i;
                break;
            }
        i +=1;
    }
}

int main(){
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

    int n;
    cin >> n;
    cout << res(n);

}