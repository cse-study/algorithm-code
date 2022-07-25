#include <iostream>
using namespace std;

int main(void){
    int a;
    int n=0;
    cin >> a;
    int a_first =a;

    while(1){
        if (a<10) {
            a = a*11;
            n++;
        }   
        else{
            a = (a%10)*10+((a/10)+ (a%10))%10;
            n++;
        }
        if (a == a_first){
            break;
        }
    }
    cout << n;
return 0;
}