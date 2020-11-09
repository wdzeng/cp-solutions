with open("input.txt", "r") as IN:
    with open("output.txt", "w") as OUT:
        n = int(IN.readline())
        if n % 3 > 0:
            OUT.write(str(0))
            exit()
        ans = 0
        n = n // 3
        if n % 2 == 1:
            ans = ans - 2
        else:
            ans = ans - 1
        ans = ans + 2 ** (n * 2 - 1)
        n = (n + 1) // 2
        ans = ans + 2 ** (2 * n - 1)
        OUT.write(str(ans))