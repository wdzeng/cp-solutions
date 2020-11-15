from itertools import permutations
ans = set()
dig = [int(x) for x in input().split()]
p = permutations(dig)
for digits in list(p):
    for i in range(1, 64):
        op0 = i & 3
        op1 = i >> 2 & 3
        op2 = i >> 4 & 3
        op = {
            0: '', 1: '+', 2: '*', 3: '-'
        }
        expr = str(digits[0])
        expr += op[op0]
        expr += str(digits[1])
        expr += op[op1]
        expr += str(digits[2])
        expr += op[op2]
        expr += str(digits[3])
        res = int(eval(expr))
        if res >= 0:
            ans.add(res)

print(len(ans))
