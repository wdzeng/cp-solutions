from sys import stdin
for line in stdin:
    strs = line.split();
    sum = 0
    for s in strs:
        sum += int(s)
    print(sum)