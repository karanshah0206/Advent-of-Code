res = 0

def check(pattern, groups):
    pattern = list(filter(None, pattern.split(".")))
    if len(pattern) != len(groups):
        return False
    for i, p in enumerate(pattern):
        if len(p) != int(groups[i]):
            return False
    return True

def modify(pattern, num):
    pl = list(pattern)
    c = 0
    for i, v in enumerate(pl):
        if v == "?":
            if num & (1 << c):
                pl[i] = "#"
            else:
                pl[i] = "."
            c += 1
    return "".join(pl)

while (line := input()) != "exit":
    line = line.split()
    pattern = line[0]
    groups = line[1].split(",")
    for i in range(pow(2, pattern.count("?"))):
        if check(modify(pattern, i), groups):
            res += 1

print(res)
