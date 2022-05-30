/**
    Baekjoon 2217: 로프
    https://www.acmicpc.net/problem/2217

    문제: N(1 ≤ N ≤ 100,000)개의 로프가 있다. 이 로프를 이용하여 이런 저런 물체를 들어올릴 수 있다.
    각각의 로프는 그 굵기나 길이가 다르기 때문에 들 수 있는 물체의 중량이 서로 다를 수도 있다.
    하지만 여러 개의 로프를 병렬로 연결하면 각각의 로프에 걸리는 중량을 나눌 수 있다.
    k개의 로프를 사용하여 중량이 w인 물체를 들어올릴 때, 각각의 로프에는 모두 고르게 w/k 만큼의 중량이 걸리게 된다.
    각 로프들에 대한 정보가 주어졌을 때, 이 로프들을 이용하여 들어올릴 수 있는 물체의 최대 중량을 구해내는 프로그램을 작성하시오.
    모든 로프를 사용해야 할 필요는 없으며, 임의로 몇 개의 로프를 골라서 사용해도 된다.

    입력: 첫째 줄에 정수 N이 주어진다. 다음 N개의 줄에는 각 로프가 버틸 수 있는 최대 중량이 주어진다. 이 값은 10,000을 넘지 않는 자연수이다.

    출력: 첫째 줄에 답을 출력한다.

    @author Yuho Jeong
*/

#include <iostream>
#include <algorithm>


class Algorithm {
    private:
        int num_rope;
        int* arr_rope;
        int max_weight;

    public:
        Algorithm(int, int*);
        int GetMaxTolerableWeight();
};


// Constructor
Algorithm::Algorithm(int N, int* rope) {
    num_rope = N;
    arr_rope = rope;
    max_weight = 0;
    std::sort(arr_rope, arr_rope + N);  // Sorting
}


int Algorithm::GetMaxTolerableWeight() {
    for(int i = 0; i < num_rope; i++) {
        int num_use = i + 1;    // 사용하는 로프 개수
        int cur_weight = arr_rope[num_rope - num_use] * num_use;    // 로프 k개 사용 시 들 수 있는 무게

        if(cur_weight > max_weight){
            max_weight = cur_weight;
        }
    }
    return max_weight;
}


// Main part
int main() {
    // The number of ropes
    int N;
    std::cin >> N;

    // Rope information array
    int rope[N];
    for(int i = 0; i < N; i++){
        std::cin >> rope[i];
    }

    // Get maximum tolerable weight
    Algorithm algo = Algorithm(N, rope);
    int weight = algo.GetMaxTolerableWeight();
    std::cout << weight;

    return 0;
}
