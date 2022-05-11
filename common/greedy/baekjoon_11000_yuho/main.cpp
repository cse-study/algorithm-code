/**
    Baekjoon 11000: 강의실 배정
    https://www.acmicpc.net/problem/11000

    문제: 수강신청의 마스터 김종혜 선생님에게 새로운 과제가 주어졌다.
    김종혜 선생님한테는 Si에 시작해서 Ti에 끝나는 N개의 수업이 주어지는데, 최소의 강의실을 사용해서 모든 수업을 가능하게 해야 한다.
    참고로, 수업이 끝난 직후에 다음 수업을 시작할 수 있다. (즉, Ti ≤ Sj 일 경우 i 수업과 j 수업은 같이 들을 수 있다.)
    수강신청 대충한 게 찔리면, 선생님을 도와드리자!

    입력: 첫 번째 줄에 N이 주어진다. (1 ≤ N ≤ 200,000) 이후 N개의 줄에 Si, Ti가 주어진다. (0 ≤ Si < Ti ≤ 10^9)
    출력: 강의실의 개수를 출력하라.

    @author Yuho Jeong
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>


class Scheduler {
private:
    int num_lecture;
    std::vector <int> vec_start;
    std::vector <int> vec_end;
public:
    Scheduler(int, std::vector <int>, std::vector <int>);
    int GetMinLectureRoom();
};


Scheduler::Scheduler(int N, std::vector <int> start, std::vector <int> end) {
    num_lecture = N;
    vec_start = std::move(start);
    vec_end = std::move(end);

    // 벡터 정렬
    sort(vec_start.rbegin(), vec_start.rend());
    sort(vec_end.rbegin(), vec_end.rend());
}


int Scheduler::GetMinLectureRoom() {
    int item_start, item_end;
    int num_room = 0;
    int num_cur_lecture = 0;

    // 현재 몇 개의 강의가 겹쳐서 진행 중인지 파악
    // 다만 시간 초과를 방지하기 위해서, 강의 시작 시간과 강의 끝 시간에 초점을 두고 파악
    do {
        item_start = vec_start.back();  // 확인하지 않은 강의 시작 시간 중 가장 빠른 시간
        item_end = vec_end.back();      // 확인하지 않은 강의 끝 시간 중 가장 빠른 시간

        // 현재 진행 중인 강의 수(num_cur_lecture)에, 새로운 강의 하나 추가
        if(item_start < item_end) {
            num_cur_lecture++;
            vec_start.pop_back();
        }
        // 현재 진행 중인 강의 수(num_cur_lecture)에서, 기존의 강의 하나가 끝남
        else {
            num_cur_lecture--;
            vec_end.pop_back();
        }

        // 강의가 최고 많이 겹치는 경우 파악
        if(num_cur_lecture > num_room) {
            num_room = num_cur_lecture;
        }
    } while (!vec_start.empty());

    return num_room;
}



int main() {
    // N개의 수업
    int N, user_input;
    std::cin >> N;

    // 수업 정보 입력
    std::vector <int> vec_start;
    std::vector <int> vec_end;

    for(int i = 0; i < N; i ++) {
        std::cin >> user_input;
        vec_start.push_back(user_input);
        std::cin >> user_input;
        vec_end.push_back(user_input);
    }

    // 필요한 강의실 개수 출력
    Scheduler scheduler(N, vec_start, vec_end);
    int num_room = scheduler.GetMinLectureRoom();
    std::cout << num_room;

    return 0;
}
