#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;              
    cin >> m >> n;

    vector<int> check(n+1);
    vector<int> prime_vec;

    check[0] = true; // 2부터 시작
    check[1] = true;

    for (int i = 2; i <= n; i++){
        if (check[i] == false){ // 소수를 하나찍 넣음
            if (i >= m) 
                prime_vec.push_back(i);

            for (int j = i*2; j <= n; j += i) //소수의 배수들은 제외
                check[j] = true;
        }
    }

    for (int i = 0; i < prime_vec.size(); i++)
        cout << prime_vec[i] << "\n";
}