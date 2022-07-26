#include <iostream>
#include <random>
using namespace std; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1,10);
    
    cout << dis(gen);
}