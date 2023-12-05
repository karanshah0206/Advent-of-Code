t = []
while (i := input()) != "exit":
    l = i.split("|")
    l1 = set(l[0].split()[2:])
    l2 = set(l[1].split())
    l3 = l1.intersection(l2)
    t.append(len(l3))
res = 0

count = [1 for _ in range(len(t))]
for index, value in enumerate(t):
    if value > 0:
        for i in range(1, value + 1):
            count[index + i] += count[index]

for value in count:
    res += value

print(res)
