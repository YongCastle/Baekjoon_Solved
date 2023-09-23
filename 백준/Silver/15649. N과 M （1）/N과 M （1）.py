import sys

N, M = map(int, sys.stdin.readline().split())

def dfs(seq: list[int]):
    # Exit
    if len(seq) == M:
        print(*seq)
        return

    for x in range(1, N+1):
        if x not in seq:
            seq.append(x)
            dfs(seq)
            seq.pop()

dfs([])