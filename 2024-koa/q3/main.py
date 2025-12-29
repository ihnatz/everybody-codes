input = open("i3.txt").read()
from collections import deque

grid = [list('.'+r+'.') for r in input.strip().split("\n")]
empty_row = ['.'] * len(grid[0])
grid = [empty_row] + grid + [empty_row]
R = len(grid)
C = len(grid[0])


def fill_zone(start):
    sr, sc = start
    zone = set()
    q = deque([(sr, sc)])
    ch = grid[sr][sc]

    while q:
        r, c = q.popleft()
        if (r, c) in zone: continue
        zone.add((r, c))
        for dr in (-1, 0, 1):
            for dc in (-1, 0, 1):
                if dr == dc == 0: continue
                nr, nc = r + dr, c + dc
                if not (0 <= nr < R and 0 <= nc < C): continue
                if grid[nr][nc] != ch:
                    continue
                if (nr, nc) not in zone:
                    q.append((nr, nc))
    return zone


def eat_borders(grid, starts):
    q = deque(starts)
    borders = set()
    visited = set()
    while q:
        r, c = q.popleft()
        if (r, c) in visited: continue
        visited.add((r, c))
        for dr in (-1, 0, 1):
            for dc in (-1, 0, 1):
                if dr == dc == 0: continue
                nr, nc = r + dr, c + dc
                if not (0 <= nr < R and 0 <= nc < C): continue
                if grid[nr][nc] == '#':
                    borders.add((nr, nc))
                    continue
                if (nr, nc) not in visited:
                    q.append((nr, nc))
    return borders

visited = set()
zones = []
start = (0, 0)
while True:
    zone = fill_zone(start)
    visited = visited | zone
    zones.append(zone)

    start = None
    for r in range(R):
        for c in range(C):
            if (r, c) not in visited:
                start = (r, c)
                break

    if not start: break

starts = []
for zone in zones:
    r, c = sorted(list(zone))[0]
    if grid[r][c] == '.': starts.append((r, c))

print(starts)
prev = sum(l.count("#") for l in grid)
t = prev
i = 1
while True:
    borders = eat_borders(grid, starts)
    for (r, c) in borders:
        grid[r][c] = f"{i:x}"

    i += 1
    for r in range(R):
        for c in range(C):
            print(grid[r][c], end="")
        print()
    print()

    t += prev - len(borders)
    new_prev = sum(l.count("#") for l in grid)
    if new_prev == prev: break
    print(i, prev - len(borders))
    prev = new_prev

print(t)


exit(0)

for r in range(R):
    for c in range(C):
        print(grid[r][c], end="")
    print()
print()






exit(0)

def eat_borders(grid, starts):
    q = deque(starts)
    borders = set()
    visited = set()
    while q:
        r, c = q.popleft()
        if (r, c) in visited: continue
        visited.add((r, c))
        for (dr, dc) in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
            nr, nc = r + dr, c + dc
            if not (0 <= nr < R and 0 <= nc < C): continue
            if grid[nr][nc] == '#':
                borders.add((nr, nc))
                continue
            if (nr, nc) not in visited:
                q.append((nr, nc))
    return borders

prev = sum(l.count("#") for l in grid)
t = prev
i = 1

def find_island():
    def find_start():
        for r in range(R):
            for c in range(C):
                if grid[r][c] == "#":
                    return (r, c)
    outside = set()
    q = deque([(0, 0)])
    while q:
        r, c = q.popleft()
        if (r, c) in outside: continue
        outside.add((r, c))
        for (dr, dc) in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
            nr, nc = r + dr, c + dc
            if not (0 <= nr < R and 0 <= nc < C): continue
            if grid[nr][nc] == '#':
                continue
            if (nr, nc) not in outside:
                q.append((nr, nc))

    print(len(outside))
    q = deque([find_start()])
    inside = set()
    while q:
        r, c = q.popleft()
        if (r, c) in inside: continue
        inside.add((r, c))
        for (dr, dc) in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
            nr, nc = r + dr, c + dc
            if not (0 <= nr < R and 0 <= nc < C): continue
            if grid[nr][nc] == '.':
                continue
            if (nr, nc) not in inside:
                q.append((nr, nc))
    for r in range(R):
        for c in range(C):
            if (r, c) not in inside and (r, c) not in outside:
                return (r, c)

starts = [(0, 0)]
island = find_island()
if island:
    starts.append(island)
print(starts)


while True:
    borders = eat_borders(grid, starts)
    for (r, c) in borders:
        grid[r][c] = f"{i:x}"

    i += 1
    for r in range(R):
        for c in range(C):
            print(grid[r][c], end="")
        print()
    print()

    t += prev - len(borders)
    new_prev = sum(l.count("#") for l in grid)
    if new_prev == prev: break
    print(i, prev - len(borders))
    prev = new_prev

print(t)

