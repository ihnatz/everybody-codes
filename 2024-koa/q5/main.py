input = open("i3.txt").readlines()
lines = [list(map(int, l.split())) for l in input]
columns = []
for col_id in range(len(lines[0])):
    col = [line[col_id] for line in lines]
    columns.append(col)

max_known = 0
current = 0
round = 1

known = set()


while True:
    state = (
        round % len(columns),
        tuple(["".join(str(val) for val in column) for column in columns])
    )
    if state in known:
        break
    known.add(state)


    clapper = columns[current].pop(0)
    next_column_idx = (current + 1) % len(columns)
    next_column = columns[next_column_idx]

    insert_idx = (clapper - 1) % (len(next_column) * 2)
    if insert_idx > len(next_column):
        insert_idx = len(next_column) * 2 - insert_idx
    columns[next_column_idx].insert(insert_idx, clapper)

    current = next_column_idx
    shout = int("".join([str(column[0]) for column in columns]))

    max_known = max(max_known, shout)
    round += 1

print(max_known)
exit(0)

def compact(l):
    cur = 0
    cou = 0
    dense = []
    for v in l:
        if v != cur:
            if cur:
                dense.append((cur, cou))
            cur, cou = v, 1
        else:
            cou += 1
    return dense

print(compact(max_known[0]))
exit(0)
for k in max_known:
    print(compact(k))
exit(0)
last_all_max = max([max(s) for s in max_known])
total = [last_all_max]
max_known.pop(0)
for s in max_known:
    for t in total:
        if t in s: s.remove(t)
    last_all_max = max(s)
    total.append(last_all_max)
print("".join(map(str, total)))

exit(0)

input = open("i2.txt").readlines()
lines = [list(map(int, l.split())) for l in input]
columns = []
for col_id in range(len(lines[0])):
    col = [line[col_id] for line in lines]
    columns.append(col)

from collections import Counter

c = Counter()
current = 0
round = 1
while True:
    clapper = columns[current].pop(0)
    next_column_idx = (current + 1) % len(columns)
    next_column = columns[next_column_idx]
    insert_idx = clapper % (len(next_column) * 2)
    if insert_idx <= len(next_column) + 1:
        insert_idx -= 1
    else:
        insert_idx -= len(next_column)
    columns[next_column_idx].insert(insert_idx, clapper)
    current = next_column_idx
    shout = int("".join([str(column[0]) for column in columns]))
    c.update([shout])
    if c[shout] == 2024:
        print(round * shout)
        break
    round += 1

exit(0)

input = open("i1.txt").readlines()
lines = [list(map(int, l.split())) for l in input]
columns = []
for col_id in range(len(lines[0])):
    col = [line[col_id] for line in lines]
    columns.append(col)

D = 0
def dp(*args):
    if D:
        print(*args)
def pp():
    maxlen = max(map(len, columns))
    for i in range(maxlen):
        line = [str(column[i]) if i < len(column) else " " for column in columns ]
        dp(" ".join(line))
    dp()


current = 0
for round in range(10):
    clapper = columns[current].pop(0)
    dp("current column", columns[current])
    dp("current clapper", clapper)
    next_column_idx = (current + 1) % len(columns)
    next_column = columns[next_column_idx]
    dp("clapping column", next_column)

    insert_idx = clapper % (len(next_column) * 2)
    if insert_idx <= len(next_column) + 1:
        insert_idx -= 1
    else:
        insert_idx -= len(next_column)
    columns[next_column_idx].insert(insert_idx, clapper)
    print(f"{round + 1}".rjust(2), "".join([str(column[0]) for column in columns]))
    current = next_column_idx
    pp()


