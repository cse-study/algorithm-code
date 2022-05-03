"""
프로그래머스: 기능개발
https://programmers.co.kr/learn/courses/30/lessons/42586
"""
def solution(progresses, speeds):    
    answer = []
    progresses = [100-p // s for p, s in zip(progresses, speeds)]   # 필요한 날 수 계산.
    front = 0
    for idx in range(len(progresses)):
        if progresses[front] < progresses[idx]: # 더 많은 시간이 필요해 함께 배포할 수 없음
            answer.append(idx - front)
            front = idx
    answer.append(len(progresses) - front)  # 이제 남은 일들은 한꺼번에 배포 가능.
    return answer