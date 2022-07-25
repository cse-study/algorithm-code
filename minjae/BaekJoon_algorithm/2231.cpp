#include<iostream>
#include<cmath>
#include <stdio.h>
using namespace std;


int main(){
    int n;
    scanf("%d",&n);
    int sum;
    int part;

    for(int i=1; i<n; i++){
        sum =i;
        part = i;

        while(part){
            sum = sum+ (part%10);
            part = part/10;
        }

        if(sum == n){
            printf("%d\n",i);
            return 0;
        }
    }
    printf("0\n");

return 0;
}