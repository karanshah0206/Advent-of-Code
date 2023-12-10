import math

dirs = input()
nodes = []
left = {}
right = {}
vals = []

input() # Ignore empty line
while (line := input()) != "exit":
    line = line.split()
    u = line[0]
    l = line[2][1:-1]
    r = line[3][:-1]
    left[u] = l
    right[u] = r
    if u[-1] == "A":
        nodes.append(u)

for node in nodes:
    res = 0
    while node[-1] != "Z":
        next_dir = dirs[res % len(dirs)]
        res += 1
        if next_dir == "L":
            node = left[node]
        else:
            node = right[node]
    vals.append(res)

print(math.lcm(*vals)) # Hacky but works
