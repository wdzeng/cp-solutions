with open("input.txt", "r") as IN:
    with open("output.txt", "w") as OUT:
        n = int(IN.readline())
        ans = 1
        for i in range(n):
            avail = 10
            if i < 9:
                avail = avail - 1
            if i == 0:
                avail = avail - 1
            ans = ans * avail
        OUT.write(str(ans))
