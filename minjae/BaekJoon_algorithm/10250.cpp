#include <iostream>
using namespace std;

int val(int h,int w,int n){
    int num=0;
    for(int i=1; i<=w; ++i){
        for(int j=1; j<=h; ++j){
            num = num+1;
            if(num == n){
                return j*100 + i;
            }

        }
    }

}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; ++i){
        int h,w,n;
        cin >> h >> w >> n;
        cout << val(h,w,n) << endl;
    }
}
