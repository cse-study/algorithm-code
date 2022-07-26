#include <iostream>
using namespace std;

int main(){
    int a,b,v;
    cin >> a >> b >> v;
    int cnt= (v-a)/(a-b);

    if((v-a)%(a-b) == 0){
        cout << cnt +1 << endl;
    }

    else{
        cout << cnt+2 << endl;
    }

return 0;
}
