#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(void){
    int n;
    cin >> n;

    char arr[81];
    int sum=0;
    int score =0;

    for(int i = 0 ; i<n; i++){
        cin >> arr;
        for(int j = 0; j<(int)strlen(arr); j++){
            if(arr[j] == 'O'){
                score += 1;
                sum += score;
            }
            else{
                score =0;
            }
        }
        cout << sum << endl;
        sum =0;
        score = 0;
    }

    return 0;
}