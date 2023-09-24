import sys

# Step 1) Input
N, S = map(int, sys.stdin.readline().split())
sequence = list(map(int, sys.stdin.readline().split()))
answer = 0

# Step 2) Find
def dfs(start: int, s: int):
    global answer
    # Exit
    if start == N:
        if s == S:
            answer += 1
        return
    else:
        # 추가 X
        dfs(start+1, s)
        # 추가 O
        dfs(start+1, s+sequence[start])


dfs(0, 0)
if S == 0:
    print(answer - 1)
else:
    print(answer)