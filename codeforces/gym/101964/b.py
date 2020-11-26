tokens = input().split()
(a, b, c, n) = tokens
a = int(a)
b = int(b)
c = int(c)
n = int(n)

s = 0
if a == b and b == c:
    s = 1
elif a == b:
    s = 2
elif b == c:
    s = 2
elif c == a:
    s = 2
else:
    s = 3

ans = n * (n-1) * (n-2) // 6  - n * ((n-1) // 2) * ((n-1)//2 - 1) // 2
if s == 3:
    ans = ans * 6
elif s == 2:
    ans = ans * 3

ans = ans % (1 << 64)
print(ans)