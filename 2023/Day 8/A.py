dirs = input()
node = "AAA"
left = {}
right = {}
res = 0

input() # Ignore empty line
while (line := input()) != "exit":
    line = line.split()
    u = line[0]
    l = line[2][1:-1]
    r = line[3][:-1]
    left[u] = l
    right[u] = r

while node != "ZZZ":
    next_dir = dirs[res % len(dirs)]
    res += 1
    if next_dir == "L":
        node = left[node]
    else:
        node = right[node]

print(res)
