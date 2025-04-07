n = int(input())

arr = input().split()

test=False

for i in range(n):
    if arr[i][0] == arr[0][0]:
        continue
    else:
        test=True

if not test :
    print(1)
else :
    print(0)