#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);


    int t; // test case
    int n, m; // 마당의 세로 n, 가로 m
    int garden_size;
    int d; // 잔디를 깍는 일 수 d

    cin >> t;
    for (int z = 0; z < t; z++) {
        cin >> n >> m >> d;
        priority_queue<int> pq;
        garden_size = n * m;
        int tem;
        int garden[d]; // day 배열
        int garden_arr[garden_size]; // grow를 위한 배열
        int res[d]; // 그날의 결과를 저장하는 배열

        for (int i = 0; i < garden_size; i++) {
            cin >> tem;
            pq.push(tem);
        }

        for (int i = 0; i < d; i++) { // 배열 각각 초기화
            res[i] = 0;
        }

        for (int i = 0; i < d; i++) {
            cin >> garden[i];
        }

        for (int k = 0; k < d; k++) {
            // 하루가 지나 1씩 자라는 과정 시작
            for (int i = 0; i < garden_size; i++) {
                garden_arr[i] = pq.top() + 1;
                pq.pop();
            }
            for (int i = 0; i < garden_size; i++) {
                pq.push(garden_arr[i]);
            } // 하루가 지나 1씩 자라는 과정 끝

            for (int j = 0; j < garden[k]; j++) { // 가장 높은 나무를 제거하는 과정
                res[k] = res[k] + (pq.top() - 1);
                pq.pop(); // 잔디를 깍고
                pq.push(1); // 1을 추가
            }
        }

        long long ans = 0;
        for (int i = 0; i < d; i++) {
            ans += res[i] * (i + 1);
        }
        cout << "#" << z+1 << " " << ans << '\n';
    }
}


/*
6
4 5 4
8 4 2 3 5
11 17 24 38 19
2 3 41 6 9
11 35 16 17 35
3 2 2 4
3 3 3
4 91 57
95 8 4
34 75 47
8 9 9
3 3 4
33 45 3
84 30 29
3 84 39
3 5 2 2
4 3 12
1 1 1
1 1 1
1 1 1
1 1 1
12 11 10 9 8 7 6 5 4 3 2 1
5 7 16
22 1 37 97 91 76 77
76 5 69 37 48 35 30
35 15 75 87 26 28 31
80 64 16 34 12 45 82
70 59 30 71 27 97 63
5 15 16 3 26 27 28 24 23 27 1 9 30 1 18 9
5 9 19
99 38 45 6 7 97 7 26 37
91 81 74 31 68 45 5 69 44
100 25 22 7 10 33 27 86 64
60 79 52 99 46 96 3 85 20
58 60 99 67 98 4 81 41 54
25 44 35 44 8 5 30 32 26 40 8 5 34 35 41 43 44 41 4
*/