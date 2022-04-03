"""
Baekjoon 1149. RGB거리
https://www.acmicpc.net/problem/1149
"""
import sys


class CostCalculator(object):
    def __init__(self, house_info):
        self.house_info = house_info
        self.final_costs = list()
        self.color2idx = {"red": 0, "green": 1, "blue": 2}

    def _check_end(self, idx_h, cost):
        """ Check end condition
        :param idx_h: index of house
        :param cost: current cost
        :return: boolean flag for the recursive function termination
        """
        if idx_h == len(self.house_info):
            self.final_costs.append(cost)   # append final cost
            return True
        else:
            return False

    def _recursion(self, idx_c, idx_h, cost):
        """ Main calculation
        :param idx_c: index of color
        :param idx_h: index of house
        :param cost: current cost
        """
        if not self._check_end(idx_h, cost):
            for next_idx_c in [0, 1, 2]:
                if next_idx_c != idx_c:     # condition: N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
                    next_idx_h = idx_h + 1  # next house index
                    next_cost = cost + self.house_info[idx_h][idx_c]    # update cost: previous cost + current cost
                    self._recursion(next_idx_c, next_idx_h, next_cost)

    def run(self, init_color):
        """ Calculate all costs of specific initial color input
        :param init_color: color of the first house
        """
        init_idx_c = self.color2idx[init_color]     # initial color index
        init_idx_h = 0  # initial house index = 0
        init_cost = 0   # initial cost = 0
        self._recursion(init_idx_c, init_idx_h, init_cost)

    def print_result(self):
        """ Print minimum value of the final costs
        """
        result = min(self.final_costs)  # get minimum value
        print(result)


def main():
    num_house = sys.stdin.readline().split()[0]
    house_info = list()

    # Get the information of houses
    for i in range(int(num_house)):
        costs = sys.stdin.readline().split()
        costs = [int(cost) for cost in costs]   # from string to int
        house_info.append(costs)

    # Run CostCalculator
    ccl = CostCalculator(house_info)
    for color in ["red", "green", "blue"]:
        ccl.run(color)

    # Print final result
    ccl.print_result()


if __name__ == "__main__":
    main()
