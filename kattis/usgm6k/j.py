M = int(1e9) + 7

def modinv(a):
    return pow(a, M - 2, M)

n = int(input())
for i in range(1, 100000):
    n = n * modinv(i)
    n = n % M
    if n == 1:
        print(i)
        exit(0)

raise "QQ"
