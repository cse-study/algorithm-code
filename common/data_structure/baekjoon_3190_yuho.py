"""
백준 3190번 문제: 뱀
https://www.acmicpc.net/problem/3190
"""
import sys
import math


class Dummy(object):
    """ Dummy 도스게임 상태를 담은 class
    """
    def __init__(self, N, K, pos_apple):
        """ Dummy class 초기화
        :param N: 보드의 크기 N (2 ≤ N ≤ 100)
        :param K: 사과의 개수 K (0 ≤ K ≤ 100)
        :param pos_apple: 사과의 위치 (첫 번째 정수는 행, 두 번째 정수는 열 위치)
        """
        self.N = N
        self.num_apple = K
        self.pos_apple = pos_apple


class Snake(object):
    """ 뱀의 상태를 담은 class
    """
    def __init__(self, L, head_cmd, dummy):
        """ Snake class 초기화
        :param L: 방향 변환 횟수 L
        :param head_cmd: 뱀의 방향 변환 정보
        :param dummy: Dummy 도스게임 정보
        """
        self.num_rot = L
        self.head_cmd = head_cmd
        self.snake = [[0, dummy.N - 1]]     # 뱀의 정보 (처음에는 맨위 맨좌측, 길이 1), 머리가 0번째에 위치함
        self.tick = 0                       # 전체 소요된 시간
        self.head_dir = [1, 0]              # 뱀 머리의 방향
        self.dummy = dummy

    def __len__(self):
        """ 뱀의 길이
        :return: self.snake list length
        """
        return len(self.snake)

    def _move_head(self):
        """ 뱀 머리 방향으로 한 칸 이동
        """
        pos_head = [self.snake[0][0] + self.head_dir[0], self.snake[0][1] + self.head_dir[1]]
        self.snake.insert(0, pos_head)

    def _check_apple(self):
        """ 이동한 위치에 사과가 있는지 확인 및 섭취
        :return: 사과가 있다면 True, 없다면 False
        """
        if self.snake[0] in self.dummy.pos_apple:
            self.dummy.num_apple -= 1
            self.dummy.pos_apple.remove(self.snake[0])
            return True
        else:
            return False

    def _move_tail(self, eat_apple=False):
        """ 뱀의 꼬리 이동
        """
        if not eat_apple:
            self.snake.pop()

    def _rot_head(self, tick):
        """ head_cmd에 따라 뱀의 방향 변환
        """
        for cmd in self.head_cmd:
            if tick == cmd[0]:
                if cmd[1] == "L":
                    deg = math.pi / 2
                else:
                    deg = - math.pi / 2

                x = self.head_dir[0]
                y = self.head_dir[1]
                self.head_dir = [int(- y * math.sin(deg)), int(x * math.sin(deg))]

    def _check_end(self):
        """ 게임이 끝났는지 판단: 벽 또는 자기자신의 몸과 부딪히면 게임이 끝
        :return: 게임 종료 유무
        """
        # 자기자신의 몸과 부딪힌 경우
        head_in_body = bool(self.snake[0] in self.snake[1:])

        # 벽과 부딪힌 경우
        out_of_board = bool((self.snake[0][0] < 0) or
                            (self.snake[0][0] >= self.dummy.N) or
                            (self.snake[0][1] < 0) or
                            (self.snake[0][1] >= self.dummy.N))

        if head_in_body or out_of_board:
            return True
        else:
            return False

    def update(self):
        """ 뱀의 상태 업데이트
        """
        self.tick += 1
        self._move_head()
        eat_apple = self._check_apple()
        end = self._check_end()
        self._move_tail(eat_apple)

        # 뱀의 방향 변환
        self._rot_head(self.tick)

        return end


def main():
    # 사용자 입력 받기
    N = int(input())
    K = int(input())
    pos_apple = list()

    for i in range(K):
        input_str = sys.stdin.readline().split()
        x = int(input_str[1]) - 1   # from 'column' to 'x-coordinate'
        y = N - int(input_str[0])   # from 'row' to 'y-coordinate'
        pos_apple.append([x, y])

    L = int(input())
    head_cmd = list()

    for i in range(L):
        input_str = sys.stdin.readline().split()
        head_cmd.append([int(input_str[0]), input_str[1]])

    # Dummy, Snake 객체 생성
    dummy = Dummy(N, K, pos_apple)
    snake = Snake(L, head_cmd, dummy)

    # 게임 진행
    while snake.tick < 10000:
        end = snake.update()

        if end is True:
            break

    # 결과 출력
    print(snake.tick)


if __name__ == "__main__":
    main()
