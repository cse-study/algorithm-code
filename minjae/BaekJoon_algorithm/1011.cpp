#include <iostream>
#include <cmath>
using namespace std;

int dist(int d){
    for(int i=0; i<=(int)sqrt(d); i++){
        if (i*i == d){
            return 1;
            break;
        }
    }

    if (d <= (int)sqrt(d)*(int)sqrt(d) + (int)sqrt(d)){
        return 2;
    }
    else{
        return 3;
    }

}

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; ++i){
        int s,e;
        cin >> s >> e;

        int d;
        d = e-s;
        if ( dist(d) == 1)
            cout << 2*(int)sqrt(d) -1 << endl;
        else if ( dist(d) == 2)
        {
            cout << 2*(int)sqrt(d)  << endl;
        }
        else
            cout << 2*(int)sqrt(d) +1 << endl;
    }
}
