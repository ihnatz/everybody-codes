input = "xBxAAABCDxCC"

input = open("i3.txt").read().strip()
cost = {"A": 0, "B": 1, "C": 3, "D": 5, "x": 0}
t = 0
for i in range(0, len(input), 3):
    enemies = list(input)[i:i+3]
    print(enemies)
    r = sum([cost[e] for e in enemies])
    empty = enemies.count("x")
    if empty == 0: r += 6
    elif empty == 1: r += 2
    else: pass
    t += r
    print(r)
print(t)

exit(0)
input = open("i2.txt").read().strip()
cost = {"A": 0, "B": 1, "C": 3, "D": 5, "x": 0}
t = 0
for i in range(0, len(input), 2):
    p1 = input[i]
    p2 = input[i + 1]
    t += cost[p1] + cost[p2]
    if p1 != 'x' and p2 != 'x':
        t += 2
print(t)


exit(0)
input = open("i1.txt").read().strip()
cost = {"A": 0, "B": 1, "C": 3}
p1 = sum(cost[c] for c in list(input))
print(p1)
