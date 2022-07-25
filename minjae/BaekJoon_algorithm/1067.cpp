#include <iostream>
#include <algorithm>
#include <vector>
#include <complex>
using namespace std; 

typedef long long ll;
typedef complex<double> base; // 복소수 정의미리 쉽게
const double PI = acos(-1);
ll n,a; 
// 그냥 풀면 당연히 안된다. n^2은 시간초과가 나니 고속 푸리에 변환을 이용하여, nlogn으로 시간을 줄여야한다.

void fft(vector<base> &a, bool inv = false){
    int n = a.size(), j = 0;
    vector<base> roots(n/2);
    for(int i=1; i<n; i++){
        int bit = (n >> 1);
        while(j >= bit){
            j -= bit;
            bit >>=1;
        }
        j += bit;
        if(i < j)   swap(a[i], a[j]);
    }
    double ang = 2 * acos(-1) / n * (inv ? -1 : 1);
    for(int i=0; i<n/2; i++){
        roots[i] = base(cos(ang*i), sin(ang*i));
    }
    for(int i=2; i<=n; i<<=1){
        int step = n/i;
        for(int j=0; j<n; j+=i){
            for(int k = 0; k <i/2; k++){
                base u = a[j+k], v = a[j+k+i/2] * roots[step * k];
                a[j+k] = u+v;
                a[j+k+i/2] = u-v;
            }
        }
    }
    if(inv) for(int i=0; i<n; i++) a[i] /= n;
}

vector<ll> multiply(vector<ll> &v, vector<ll> &w){
    vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
    int n = 2;
    while(n < v.size() + w.size()){
        n <<= 1;
    }
    fv.resize(n); fw.resize(n);
    fft(fv,0); fft(fw,0);
    for(int i=0; i<n; i++){
        fv[i] *= fw[i];
    }
    fft(fv,1);
    vector<ll> ret(n);
    for(int i=0; i<n; i++){
        ret[i] = (ll)round(fv[i].real());
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);

    // int n,a; cin >> n;
    // vector<int> A,B;
    // for(int i=0; i<n; i++){
    //     cin >> a;
    //     A.push_back(a);
    // }
    // for(int i=0; i<n; i++){
    //     cin >> a;
    //     B.push_back(a);
    // }
    // vector<int> ans;
    // for(int j=0; j<n; j++){
    //     int temp = B[n-1];
    //     B.insert(B.begin(),temp);
    //     B.pop_back();
    //     int sum=0;
    //     for(int i=0; i<n; i++){
    //         sum += A[i]*B[i];
    //     }
    //     ans.push_back(sum);
    // }
    // sort(ans.begin(), ans.end());
    // cout << ans[n-1];

    cin >> n;
    vector<ll> A(2*n),B(n);
    for(int i=0; i<n; i++){
        cin >> A[i];
        A[i+n] = A[i];
    }
    for(int i=1; i<=n; i++){
        cin >> B[n-i];
    }
    

    vector<ll> ans = multiply(A,B);
    ll res = 0;
    for(auto i : ans){
        res = max(i,res);
    }
    cout << res;

    return 0;
}