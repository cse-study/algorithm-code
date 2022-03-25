"""
백준 1406번 문제: 에디터
https://www.acmicpc.net/problem/1406
"""
import sys

left_list = list(input())
right_list = []
input_num = int(input())

for i in range(input_num):
    input_str = sys.stdin.readline().strip()
    command = input_str[0]
    
    if command == "L" and left_list:
        right_list.append(left_list.pop())
    
    elif command == "D" and right_list:
        left_list.append(right_list.pop())
                
    elif command == "B" and left_list:
        left_list.pop()
    
    elif command =="P":
        left_list.append(input_str[2])
        
    
    
print("".join(left_list + list(reversed(right_list))))

    
    