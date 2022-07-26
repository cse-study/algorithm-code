#include <iostream>
#include <string>
using namespace std;

int main(){
    string a,b;
    int arr1[100050], arr2[100050], result[100050]={0,};
    cin >> a >> b;

    int diff;
    int big;
    if(a.size()>= b.size()){ // 계산할수 있게 칸을 맞추기 위해 비교하고 그만큼 옮긴다
        diff = a.size() - b.size();
        big = a.size();
        for(size_t i=0; i<a.size(); i++)    arr1[i+2] = a[i]-'0'; // 연속올림을 고려해 +2를 한다
        for(size_t i=0; i<b.size(); i++)    arr2[i+2+diff] = b[i]-'0';
    }
    else{
        diff = b.size() - a.size();
        big = b.size();
        for(size_t i=0; i<a.size(); i++)    arr1[i+2+diff] = a[i]-'0';
        for(size_t i=0; i<b.size(); i++)    arr2[i+2] = b[i]-'0';
    }

    for(size_t i=10005; i>=1; i--){
        if(arr1[i]+ arr2[i] >= 10){ // 자리수 올림 고려
            result[i] = arr1[i] + arr2[i] - 10;
            arr1[i - 1] += 1;
            if(arr1[i-1]==10){ // 자릿수 연속올림 고려
                arr1[i-1] -= 10;
                arr1[i-2] += 1;
            }
        }
        else{
            result[i] = arr1[i] + arr2[i];
        }
    }

    for(size_t i =0; i<=1; i++){
        if(result[i] != 0){
            cout << result[i];
        }
    }
    for(size_t i =2; i<=big+1; i++){
        cout << result[i];
    }

    return 0;
}