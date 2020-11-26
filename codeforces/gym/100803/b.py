s = input()
n = int(input())
good = eval(s)

bad = 0
oper = "plus"
for i in range(len(s)):
    if i % 2 == 0:
        if oper == "plus":
            bad += (ord(s[i]) - ord('0'))
        else:
            bad *= (ord(s[i]) - ord('0'))
    else:
        if s[i] == '*': 
            oper="mul"
        else:
            oper="plus"
if good==n and bad==n:
    print("U")
elif good==n:
    print("M")
elif bad==n:
    print("L")
else :
    print("I")