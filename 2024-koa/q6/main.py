input = open("i3.txt").readlines()

FRUIT = "@"
class Node:
    def __init__(self, label, fruit = False):
        self.label = label
        self.children = []
        self.fruit = fruit

    def add_child(self, label):
        if self.fruit: raise Exception("can't add a child to a fruit")
        self.children.append(label)

    def terminate(self):
        self.fruit = True

class Tree:
    def __init__(self):
        self.known = {}

    def get(self, name):
        if name in self.known:
            return self.known[name]
        node = Node(name)
        self.known[name] = node
        return node

    def shortest(self):
        levels = [[] for _ in range(len(self.known))]
        visited = set()
        q = [('RR', 0)]
        while q:
            current, level = q.pop(0)
            if current in visited: continue
            visited.add(current)
            node = self.get(current)
            if node.fruit:
                levels[level].append(node.label)
            for label in node.children:
                q.append((label, level + 1))

        for level in levels:
            if len(level) == 1:
                return level[0]
        raise Exception("can't find level with 1 fruit")

    def path(self, goal):
        q = [('RR', ['RR'])]
        while q:
            current, path = q.pop(0)
            if current == goal:
                return path
            node = self.get(current)
            for label in node.children:
                q.append((label, path + [label]))

t = Tree()
for line in input:
    parent_label, children = line.strip().split(":")
    parent = t.get(parent_label)
    for child in children.split(","):
        if child == FRUIT:
            parent.terminate()
        else:
            parent.add_child(child)

#print("".join(t.shortest()))
print()
print("".join([p[0] for p in t.path(t.shortest())]) + "@")


