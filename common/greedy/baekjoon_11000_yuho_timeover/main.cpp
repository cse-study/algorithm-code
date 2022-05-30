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


class Scheduler {
private:
    int num_lecture;
    int* arr_start;
    int* arr_end;
    int time_min;
    int time_max;
    void SetTimeInterval();
public:
    Scheduler(int, int*, int*);
    int GetMinLectureRoom();
};


Scheduler::Scheduler(int N, int* start, int* end) {
    num_lecture = N;
    arr_start = start;
    arr_end = end;
    time_min = 0;
    time_max = 1000000000;
    SetTimeInterval();
}


void Scheduler::SetTimeInterval() {
    time_min = *std::min_element(arr_start, arr_start + num_lecture);
    time_max = *std::max_element(arr_end, arr_end + num_lecture);
}


int Scheduler::GetMinLectureRoom() {
    int num_room = 0;

    for(int time = time_min; time < time_max; time++) {
        int counter = 0;
        for(int j = 0; j < num_lecture; j++) {
            if(arr_start[j] <= time and time < arr_end[j]) {
                counter++;
            }
        }

        if(counter > num_room) {
            num_room = counter;
        }
    }

    return num_room;
}



int main() {
    // N개의 수업
    int N;
    std::cin >> N;

    // 수업 정보 입력
    int arr_start[N];
    int arr_end[N];
    for(int i = 0; i < N; i ++) {
        std::cin >> arr_start[i];
        std::cin >> arr_end[i];
    }

    // 필요한 강의실 개수 출력
    Scheduler scheduler(N, arr_start, arr_end);
    int num_room = scheduler.GetMinLectureRoom();
    std::cout << num_room;

    return 0;
}
