def hits(nails, target = None):
    current_min = target or min(nails)
    return sum(abs(n - current_min) for n in nails)

def optimal_hits(nails):
    nails.sort()
    t = nails[len(nails) // 2]
    return hits(nails, t)


input = open("i1.txt").readlines()
nails = [int(n) for n in input]
print(hits(nails))

input = open("i2.txt").readlines()
nails = [int(n) for n in input]
print(hits(nails))

input = open("i3.txt").readlines()
nails = [int(n) for n in input]
print(optimal_hits(nails))

