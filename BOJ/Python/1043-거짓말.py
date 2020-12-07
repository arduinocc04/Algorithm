peopleCount, partyCount = map(int, input().split())
peopleKnowTruth = [int(i) for i in input().split()[::-1]]
peopleKnowTruthCount = peopleKnowTruth.pop()
parties = []
dict_ = dict()
for k in range(partyCount):
    a = [int(i) for i in input().split()[::-1]]
    del a[-1]
    parties.append(a)
    for p in a:
        if p in dict_:
            dict_[p].append(k)
        else:
            dict_[p] = [k]

mem = [False]*partyCount

def calc(partyIndex):
    global mem
    if mem[partyIndex]:
        return
    mem[partyIndex] = True
    for person in parties[partyIndex]:
        for party in dict_[person]:
            calc(party)

for i in range(len(parties)):
    for person in peopleKnowTruth:
        if person in parties[i]:
            calc(i)

print(mem.count(False))        