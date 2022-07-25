#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int i=0;
    for (int sum=2; sum<=n; ++i){
        sum += 6*i;
    }

    if (n ==1){
        i = 1;
    }

    cout << i << endl;

}
