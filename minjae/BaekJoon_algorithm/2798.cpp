#include<iostream>
#include<cmath>
#include <stdio.h>
using namespace std;


int main()
{
    int n,m;
    int result=0;
    cin >> n >> m;
    int arr[n-1];
    int max =0;
    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int a=0; a<n-2; a++){ // brute force attack
        for (int b=a+1; b<n-1; b++){
            for(int c=b+1; c<n; c++){ 
                int sum = arr[a]+arr[b]+arr[c]; 
                
                if(sum<=m){
                    result = sum;
                    if (max <= result){
                        max = result;
                    }
                }            
            }        
        }
    }
    cout << max;
return 0;
}