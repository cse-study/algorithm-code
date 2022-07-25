gem = list(map(int, input().split()))
star = list(map(int, input().split()))

sum_g = 0
sum_s = 0
check = False

for i in gem:
    sum_g += gem[i]
    if sum_g > sum_s:
        check = True
    sum_s += star[i]

if check == True and sum_g < sum_s:
    print("Yes")
else:
    print("No")