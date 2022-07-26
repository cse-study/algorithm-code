seq = list(map(int, input().split()))

check = "Good"
for i in range(len(seq)-1):
    if seq[i] > seq[i+1]:
        check = "Bad"

print(check)
