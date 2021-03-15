line = input()
str = ""
previsen = False
for i in line:
    if i >= 'a' and i <= 'z':
        if previsen:
            print("error")
            exit(0)
        str += "1"
    else

try:
    eval(line)
except ZeroDivisionError:
    pass
except:
    print("error")
    exit(0)