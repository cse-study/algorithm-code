#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){

    vector <int> v;
    while(1){
    int a,b,c;
    cin >> a >> b >> c;

    if( a==0 && b ==0 && c ==0){
        break;
    }

    v = {a,b,c};

    sort(v.begin(),v.end());
    
    if( v[0]*v[0] + v[1]*v[1] == v[2]*v[2] ) {
        cout << "right" << endl;
    }
    else{
        cout << "wrong" << endl;
    }
    }
    return 0;
}