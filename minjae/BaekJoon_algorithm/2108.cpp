#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector<int> arr;
int main() {
    int num,tmp,range,middle = 0,most_val,mean = 0;
    int most = -9999;
    int number[8001] = {0,};
    bool not_first = false;
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
        mean += tmp;
        number[tmp+4000]++;
    }
    sort(arr.begin(),arr.end());
    for(int i = 0; i < 8001; i++)
    {
        if(number[i] == 0)
            continue;
        if(number[i] == most)
        {
            if(not_first)
            {
                most_val = i - 4000;
                not_first = false;
            }
        }
        if(number[i] > most)
        {
            most = number[i];
            most_val = i - 4000;
            not_first = true;
        }
    }
    middle = arr[arr.size()/2];
    mean = round((float)mean / num);
    range = arr.back() - arr.front();
    cout << mean << '\n' << middle << '\n' << most_val << '\n' << range;

    return 0;
}