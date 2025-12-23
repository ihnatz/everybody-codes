input = """
WORDS:THE,OWE,MES,ROD,RODEO

HELWORLT
ENIGWDXL
TRODEOAL
"""
input = open("i3.txt").read()

def D():
    import pdb;
    pdb.set_trace()

raw_words, raw_sentance = input.split("\n\n")
words = raw_words.split(":")[1].split(",")
all_words = set()
for word in words:
    all_words.add(word)
    all_words.add(word[::-1])

lines = raw_sentance.strip().splitlines()
unique_lengths = set(len(word) for word in all_words)

known = set()
for lno, word in enumerate(lines):
    for size in unique_lengths:
        for i in range(0, len(word) + max(unique_lengths) + 1):
            if i + size >= len(word):
                rem = (i + size) % len(word)
                subword = word[i:] + word[:rem]
                idxs = set(range(i, len(word))) | set(range(rem)) 
            else:
                subword = word[i:i+size]
                idxs = set(range(i, i+size))
            if subword in all_words:
                known |= set((lno, idx) for idx in idxs)

vertical_words = len(lines[0])

for cno in range(vertical_words):
    word = "".join(line[cno] for line in lines)
    for size in unique_lengths:
        for i in range(0, len(word) - size + 1):
                subword = word[i:i+size]
                if subword in all_words:
                    for idx in range(i, i + size):
                        known.add((idx, cno))



# for (lno, line) in enumerate(lines):
#     for (idx, ch) in enumerate(line):
#         if (lno, idx) in known:
#             print(ch.upper(), end='')
#         else:
#             print(ch.lower(), end='')
#     print()


print(len(known))





















exit(0)

input = """
WORDS:THE,OWE,MES,ROD,HER,QAQ

AWAKEN THE POWE ADORNED WITH THE FLAMES BRIGHT IRE
THE FLAME SHIELDED THE HEART OF THE KINGS
POWE PO WER P OWE R
THERE IS THE END
QAQAQ
"""
input = open("i2.txt").read()
raw_words, raw_sentance = input.split("\n\n")
words = raw_words.split(":")[1].split(",")
all_words = set()
for word in words:
    all_words.add(word)
    all_words.add(word[::-1])

lines = raw_sentance.strip().splitlines()
unique_lengths = set(len(word) for word in all_words)

t = 0
for line in lines:
    sentance_words = line.split(" ")
    st = set()
    for word in sentance_words:
        for size in unique_lengths:
            for i in range(0, len(word) - size + 1):
                    subword = word[i:i+size]
                    if subword in all_words:
                        for idx in range(i, i + size):
                            st.add(idx)
    print(line, st)
    t += len(st)
print(t)


exit(0)
input = """
WORDS:THE,OWE,MES,ROD,HER

AWAKEN THE POWER ADORNED WITH THE FLAMES BRIGHT IRE
"""
input = open("i1.txt").read()
raw_words, raw_sentance = input.split("\n\n")
words = set(raw_words.split(":")[1].split(","))
sentance_words = raw_sentance.strip().split(" ")
unique_lengths = set(len(word) for word in words)

t = 0
for word in sentance_words:
    for size in unique_lengths:
       for i in range(0, len(word) - size + 1):
            subword = word[i:i+size]
            if subword in words:
                t += 1
print(t)
