"""
Baekjoon 10814. 나이순 정렬
https://www.acmicpc.net/problem/10814
문제: 온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주어진다.
이때, 회원들을 나이가 증가하는 순으로, 나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 정렬하는 프로그램을 작성하시오.

입력: 첫째 줄에 온라인 저지 회원의 수 N이 주어진다. (1 ≤ N ≤ 100,000)
둘째 줄부터 N개의 줄에는 각 회원의 나이와 이름이 공백으로 구분되어 주어진다.
나이는 1보다 크거나 같으며, 200보다 작거나 같은 정수이고, 이름은 알파벳 대소문자로 이루어져 있고, 길이가 100보다 작거나 같은 문자열이다.
입력은 가입한 순서로 주어진다.

출력: 첫째 줄부터 총 N개의 줄에 걸쳐 온라인 저지 회원을 나이 순,
나이가 같으면 가입한 순으로 한 줄에 한 명씩 나이와 이름을 공백으로 구분해 출력한다.
"""
import sys
from typing import List, Tuple


class UserTable(object):
    def __init__(self):
        self.users = list()

    def append_user(self, age: int, name: str):
        """ 유저 1명 추가 """
        self.users.append((age, name))

    def _sort_users(self) -> List[Tuple]:
        """ 나이순으로 유저 테이블 정렬 """
        return sorted(self.users, key=lambda x: x[0])

    def _get_sorted_users(self) -> List[Tuple]:
        """ 정렬된 유저 테이블 리턴 """
        return self._sort_users()

    def print_sorted_users(self):
        """ 정렬된 유저 테이블 print """
        sorted_users = self._get_sorted_users()
        for i in range(len(sorted_users)):
            print(*sorted_users[i])


def main():
    num_user = input()  # 회원의 수
    user_table = UserTable()

    for i in range(int(num_user)):
        input_str = sys.stdin.readline().split()
        user_table.append_user(int(input_str[0]), input_str[1])

    user_table.print_sorted_users()


if __name__ == "__main__":
    main()
