#include <iostream>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int arr[1000] ={0};

    for (int i = 0; i<n; i++){
        double k;
        cin >> k;
        int sum=0;
        int av=0;
        double count =0;
        double res;
        for (int j=0; j<k; j++){
            cin >> arr[j];
            sum = sum + arr[j];
        }
        av = sum/k;
        for (int j =0; j<k; j++){
            if(arr[j] > av)
                count += 1;
        }
        res = (double)count/k *100;
        cout << fixed;
        cout.precision(3);
        cout << res << "%" << endl;
    }
    return 0;
}