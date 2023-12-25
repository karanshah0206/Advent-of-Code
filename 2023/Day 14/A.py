res = 0
grid = []

def move_north(i, j):
    if i <= 0:
        return
    if grid[i - 1][j] == ".":
        grid[i][j] = "."
        grid[i - 1][j] = "O"
        move_north(i - 1, j)

while (line := input()) != "exit":
    row = []
    for char in line:
        row.append(char)
    grid.append(row)

for i, row in enumerate(grid):
    for j, col in enumerate(row):
        if col == "O":
            move_north(i, j)

for i, row in enumerate(grid):
    for j, col in enumerate(row):
        if col == "O":
            res += len(grid) - i

print(res)
