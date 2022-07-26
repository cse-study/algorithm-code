#include <iostream> 
#include <cmath>
using namespace std;

double get_v (int *arr, int c){ // get V
    double sum=0, v_sum=0;
    for(int i=0; i<c; i++){
        sum += arr[i];
    }
    double m = sum/c;
    for(int i=0; i<c; i++){
        v_sum += (arr[i]-m)*(arr[i]-m);
    }
    double res = sqrt(v_sum/c);
    return res;
}

void fun (int *arr, int c, int len){
    if (c == 1 || c == len) cout << "1" << '\n';
    else{
        double max_v=0;
        int ans=0;
        for(int i=0; i<= len-c; i++){
            if (max_v < get_v(arr+i, c)){ // start i_th array element.
                max_v = get_v(arr+i, c);
                ans = i+1;
            }
        }
        cout << ans << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=1; i<=n; i++){
        fun(arr,i,n);
    }
}