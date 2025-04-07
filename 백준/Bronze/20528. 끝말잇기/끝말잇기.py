n = int(input())
arr = input().split()

test=1
for i in range(n):
    if arr[i][0] != arr[0][0]:
        test=0

print(test)