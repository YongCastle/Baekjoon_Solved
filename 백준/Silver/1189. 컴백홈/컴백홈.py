import sys

class ComeBackHome:

    def __init__(self):
        # Step 1) Input Data
        self.R, self.C, self.K = map(int, sys.stdin.readline().split())
        self.start = (self.R-1,0)
        self.end = (0, self.C-1)
        self.route = 0
        self.graph = []
        for _ in range(self.R):
            self.graph.append([x for x in sys.stdin.readline()[:-1]])

    def _brute_force(self, curr) -> list:
        
        brute = []
        # Out of Range Handler
        r, c = curr[0], curr[1]
        if r != 0:
            brute.append((r-1,c))
        if r != self.R-1:
            brute.append((r+1,c))
        if c != 0:
            brute.append((r,c-1))
        if c != self.C-1:
            brute.append((r,c+1))

        return brute

    def goBack(self, curr, k: int, graph: list):
        r, c = curr
        tmp, graph[r][c] = graph[r][c], k     # visited

        # Exit
        if curr == self.end:
            if k == 0:
                self.route += 1

        # Go
        if k > 0:
            for next in self._brute_force(curr):
                if graph[next[0]][next[1]] == '.':
                    self.goBack(next, k-1, graph[:][:])
        
        graph[r][c] = tmp


Hansu = ComeBackHome()
Hansu.goBack(Hansu.start, Hansu.K-1, Hansu.graph)
print(Hansu.route)
