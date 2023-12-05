res = 0
while (i := input()) != "exit":
    k = i.split("|")
    l1 = k[0].split()
    l2 = k[1].split()
    l1 = l1[2:]
    l1 = set(l1)
    l2 = set(l2)
    l3 = l1.intersection(l2)
    if len(l3) > 0:
        res += pow(2, len(l3) - 1)
print(res)
