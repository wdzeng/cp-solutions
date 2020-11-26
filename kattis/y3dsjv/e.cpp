import math
q = int(input())

def lt(a, b):
    return a[0] * b[1] < b[0] * a[1]

def diff(a, b):
    up = a[0] * b[1] - b[0] * a[1]
    if up < 0:
        up = -up
    down = a[1] * b[1]
    return (up, down)

for i in range(1, q + 1):
    print("%d " % i, end='')
    line = input()
    line = line.split()
    m = int(line[1])
    s = line[2]
    if s == "0":
        print("0/1")
        continue
    c = int(s[2:])
    d = 1
    for _i in range(len(s) - 2):
        d = d * 10
    #print(str(c))
    #print(str(d))

    mindiff = (1e9, 1)
    ans = None
    for y in range(1, m+1):
        b = y * c / d
        bfloor = math.floor(b)
        bdiff = diff((bfloor, y), (c, d))
        if lt(bdiff, mindiff):
            mindiff = bdiff
            ans = [bfloor, y]
        bceil = math.ceil(b)
        bdiff = diff((bceil, y), (c, d))
        if lt(bdiff, mindiff):
            mindiff = bdiff
            ans = [bceil, y]
    g = math.gcd(ans[0], ans[1])
    ans[0] = ans[0] // g
    ans[1] = ans[1] // g
    print("%d/%d" % (ans[0], ans[1]))