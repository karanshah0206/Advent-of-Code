grid = []

# 0 up, 1 left, 2 down, 3 right
dirs_r = [-1, 0, 1, 0]
dirs_c = [0, -1, 0, 1]

while (line := input()) != "exit":
    row = []
    for char in line:
        row.append(char)
    grid.append(row)

def is_valid(r, c):
    return not (r < 0 or c < 0 or r >= len(grid) or c >= len(grid[0]))

path = []
heads = [(0, 0, 3)]

while len(heads) > 0:
    current = heads.pop()
    current_char = grid[current[0]][current[1]]

    if current in path:
        continue

    path.append(current)

    if current_char == "." or (current[2] in { 1, 3 } and current_char == "-") or (current[2] in { 0, 2 } and current_char == "|"):
        new_head = (current[0] + dirs_r[current[2]], current[1] + dirs_c[current[2]], current[2])
        if new_head[0] >= 0 and new_head[0] < len(grid) and new_head[1] >= 0 and new_head[1] < len(grid[0]):
            heads.append(new_head)
    elif current_char == "-":
        if current[1] > 0:
            heads.append((current[0], current[1] - 1, 1))
        if current[1] < len(grid[0]) - 1:
            heads.append((current[0], current[1] + 1, 3))
    elif current_char == "|":
        if current[0] > 0:
            heads.append((current[0] - 1, current[1], 0))
        if current[0] < len(grid) - 1:
            heads.append((current[0] + 1, current[1], 2))
    elif current_char == "/":
        if current[2] == 0:
            new_head = (current[0], current[1] + 1, 3)
            if is_valid(new_head[0], new_head[1]):
                heads.append(new_head)
        elif current[2] == 1:
            new_head = (current[0] + 1, current[1], 2)
            if is_valid(new_head[0], new_head[1]):
                heads.append(new_head)
        elif current[2] == 2:
            new_head = (current[0], current[1] - 1, 1)
            if is_valid(new_head[0], new_head[1]):
                heads.append(new_head)
        else:
            new_head = (current[0] - 1, current[1], 0)
            if is_valid(new_head[0], new_head[1]):
                heads.append(new_head)
    else:
        if current[2] == 0:
            new_head = (current[0], current[1] - 1, 1)
            if is_valid(new_head[0], new_head[1]):
                heads.append(new_head)
        elif current[2] == 1:
            new_head = (current[0] - 1, current[1], 0)
            if is_valid(new_head[0], new_head[1]):
                heads.append(new_head)
        elif current[2] == 2:
            new_head = (current[0], current[1] + 1, 3)
            if is_valid(new_head[0], new_head[1]):
                heads.append(new_head)
        else:
            new_head = (current[0] + 1, current[1], 2)
            if is_valid(new_head[0], new_head[1]):
                heads.append(new_head)

places = set()

for place in path:
    places.add((place[0], place[1]))

print(len(places))
