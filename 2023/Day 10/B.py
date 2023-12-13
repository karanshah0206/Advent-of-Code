import sys
import math

sys.setrecursionlimit(20000)

grid = []
start_row = 0
start_col = 0
longest_path = []

class Node:
    def __init__(self, c, row, col):
        self.c = c
        self.row = row
        self.col = col
        self.neighbours = set()

    def find_neighbours(self):
        row_max = len(grid)
        col_max = len(grid[0])
        row = self.row
        col = self.col
        if self.c in { "F", "S" } and row < row_max - 1 and col < col_max - 1:
            if grid[row + 1][col].c not in { ".", "-", "7", "F" } and grid[row][col + 1].c not in { ".", "|", "L", "F" }:
                self.neighbours.add(grid[row + 1][col])
                self.neighbours.add(grid[row][col + 1])
        if self.c in { "7", "S" } and row < row_max - 1 and col > 0:
            if grid[row + 1][col].c not in { ".", "-", "F", "7" } and grid[row][col - 1].c not in { ".", "|", "J", "7" }:
                self.neighbours.add(grid[row + 1][col])
                self.neighbours.add(grid[row][col - 1])
        if self.c in { "L", "S" } and row > 0 and col < col_max - 1:
            if grid[row - 1][col].c not in { ".", "-", "L", "J" } and grid[row][col + 1].c not in { ".", "|", "L", "F" }:
                self.neighbours.add(grid[row - 1][col])
                self.neighbours.add(grid[row][col + 1])
        if self.c in { "J", "S" } and row > 0 and col > 0:
            if grid[row - 1][col].c not in { ".", "-", "L", "J" } and grid[row][col - 1].c not in { ".", "|", "J", "7" }:
                self.neighbours.add(grid[row - 1][col])
                self.neighbours.add(grid[row][col - 1])
        if self.c in { "|", "S" } and row > 0 and row < row_max - 1:
            if grid[row - 1][col].c not in { ".", "-", "L", "J" } and grid[row + 1][col].c not in { ".", "-", "F", "7" }:
                self.neighbours.add(grid[row + 1][col])
                self.neighbours.add(grid[row - 1][col])
        if self.c in { "-", "S" } and col > 0 and col < col_max - 1:
            if grid[row][col - 1].c not in { ".", "|", "J", "7" } and grid[row][col + 1].c not in { ".", "|", "L", "F" }:
                self.neighbours.add(grid[row][col - 1])
                self.neighbours.add(grid[row][col + 1])

def dfs(node, path_list):
    global longest_path
    path_list.append(node)
    for neighbour in node.neighbours:
        if neighbour.c == "S" and len(path_list) > len(longest_path):
            longest_path = path_list.copy()
        elif neighbour not in path_list:
            dfs(neighbour, path_list)
    path_list.pop()

while (line := input()) != "exit":
    row = []
    for c in line:
        if c == "S":
            start_row = len(grid)
            start_col = len(row)
        row.append(Node(c, len(grid), len(row)))
    grid.append(row)

for row in grid:
    for node in row:
        node.find_neighbours()

dfs(grid[start_row][start_col], [])
res = 0

n1 = longest_path[0]
n2 = longest_path[1]
n3 = longest_path[-1]

if n1.row == n2.row == n3.row:
    n1.c = "-"
elif n1.col == n2.col == n3.col:
    n1.c = "|"
elif n1.col == n2.col and n1.row == n3.row:
    if n1.row > n2.row:
        if n1.col > n3.col:
            n1.c = "J"
        else:
            n1.c = "L"
    else:
        if n1.col > n3.col:
            n1.c = "7"
        else:
            n1.c = "F"
else:
    if n1.row > n3.row:
        if n1.col > n2.col:
            n1.c = "J"
        else:
            n1.c = "L"
    else:   
        if n1.col > n2.col:
            n1.c = "7" 
        else:      
            n1.c = "F"

for row in grid:
    last_seen = ""
    count = 0
    for node in row:
        if node not in longest_path:
            if count % 2 != 0:
                res += 1
        else:
            if node.c in { "-", "S" }:
                continue
            elif last_seen == "L":
                if node.c != "J":
                    count += 1
            elif last_seen == "F":
                if node.c != "7":
                    count += 1
            elif node.c not in { "L", "F" }:
                count += 1
            last_seen = node.c

print (res)
