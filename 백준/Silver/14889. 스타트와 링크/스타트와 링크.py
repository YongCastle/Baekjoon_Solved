import sys

# ------------------------------------ Step 1) Input Data
N = int(sys.stdin.readline())

abilits = []
for _ in range(N): 
    abilits.append(list(map(int,sys.stdin.readline().split())))

# ----------------------------------- Step 2) Make Team : DFS
teams_set = set()
def dfs(prev: list[int], start: int, k: int):
    if k == 0:
        teams_set.add(tuple(prev[:]))
        return
    
    for i in range(start, N):
        prev.append(i)
        dfs(prev, i+1, k-1)
        prev.pop()

dfs([], 1, int(N/2))

# ---------------------------------- Step 3) Compare Ability
record_diff = 10000000

member = set(list(x for x in range(0, N)))
for start in teams_set:
    link = tuple(member - set(start))

    #Calulate team ability
    sum_A = 0
    sum_B = 0
    for i in range(len(start)):
        for j in range(i+1, len(start), 1):
            sum_A += abilits[start[i]][start[j]] + abilits[start[j]][start[i]]
            sum_B += abilits[link[i]][link[j]] + abilits[link[j]][link[i]]


    diff = abs(sum_A - sum_B)

    if record_diff > diff:
        record_diff = diff
    
    if record_diff == 0:
        break

print(record_diff)