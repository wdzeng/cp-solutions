sol = {}
for i in range(64):
    m = i
    val = "4"
    for j in range(3):
        if m & 3 == 0:
            val += " + 4"
        elif m & 3 == 1:
            val += " - 4"
        elif m & 3 == 2:
            val += " * 4"
        else:
            val += " // 4"
        m = m >> 2
    ival = eval(val)
    sol[ival] = val

q = int(input())
for i in range(q):
    n = int(input())
    if n in sol:
        print(sol[n].replace("//", "/") + " = " + str(n))
    else:
        print("no solution")