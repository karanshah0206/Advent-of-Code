res = 0
grid = []
snapshots = []
positions = []
cycles = 1000000000

def get_positions(reverse=False):
    global positions
    for i, row in enumerate(grid):
        for j, col in enumerate(row):
            if col == "O":
                positions.append((i, j))
    if reverse:
        positions = list(reversed(positions))

def move_north(row, col):
    if row > 0 and grid[row - 1][col] == ".":
        grid[row - 1][col] = "O"
        grid[row][col] = "."
        move_north(row - 1, col)

def move_south(row, col):
    if row < len(grid) - 1 and grid[row + 1][col] == ".":
        grid[row + 1][col] = "O"
        grid[row][col] = "."
        move_south(row + 1, col)

def move_east(row, col):
    if col < len(grid[0]) - 1 and grid[row][col + 1] == ".":
        grid[row][col + 1] = "O"
        grid[row][col] = "."
        move_east(row, col + 1)

def move_west(row, col):
    if col > 0 and grid[row][col - 1] == ".":
        grid[row][col - 1] = "O"
        grid[row][col] = "."
        move_west(row, col - 1)

while (line := input()) != "exit":
    row = []
    for char in line:
        row.append(char)
    grid.append(row)

get_positions()
snapshots.append(positions)

for _ in range(cycles):
    positions = []
    get_positions()
    for position in positions:
        move_north(*position)
    positions = []
    get_positions()
    for position in positions:
        move_west(*position)
    positions = []
    get_positions(True)
    for position in positions:
        move_south(*position)
    positions = []
    get_positions(True)
    for position in positions:
        move_east(*position)
    if positions in snapshots:
        break
    snapshots.append(positions)

offset = snapshots.index(positions)
cycles -= offset
cycle_length = len(snapshots) - offset
index = (cycles % cycle_length) + offset

for i, j in snapshots[index]:
    res += len(grid) - i

print(res)
