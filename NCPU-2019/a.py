m=int(input())

def judge(n):
    s=1
    i=2
    while(s%n!=0):
        s=s*i
        i+=1
    return i-1

for i in range(m):
    n=int(input())
    print(judge(n))
