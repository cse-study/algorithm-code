#include <iostream>
#include <vector>
using namespace std;

long long sum(std::vector<int> &a){
    long long answer = 0;
    for(size_t i=0; i<a.size(); i++){
        answer += a[i];
    }

    return answer;
}