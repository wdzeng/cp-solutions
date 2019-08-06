carray = [None] * 5001
carray[0] = 1

x = int(input())
if x == 0:
    print(1)
    exit(0)

sum = 1
for i in range(1, x+1):
    sum = sum * (2*i-1) * (2*i) // (i+1) // i
    carray[i] = sum

ans = 0
for i in range(0, x+1):
    ans += carray[i] * carray[x-i]
print(ans)
