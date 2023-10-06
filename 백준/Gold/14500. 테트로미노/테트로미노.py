import sys
#     ^   >  v  <
dn = [-1, 0, 1, 0]
dm = [0, 1, 0, -1]

class Solver():
    def __init__(self):
        self.max_score = -1
        self.N, self.M = map(int, sys.stdin.readline().split())
        self.graph = []
        self.visited_graph = []
        for i in range(self.N):
            self.graph.append(list(map(int, sys.stdin.readline().split())))    
            self.visited_graph.append(list(0 for x in range(self.M)))

    def _is_out_of_range(self, curr) -> bool:
        key = (0 <= curr[0] < self.N and 0 <= curr[1] < self.M)
        return not key
    
    def search(self, curr):
        """"
        Time Complexity:
            DFS  : 
            'ㅗ' : O(12) - Worst case 
        """
        def _dfs(curr, k, score, path):
            
            r, c = curr
            self.visited_graph[r][c] = 1
            score.append(self.graph[r][c])
            path.append(curr)
            if k == 0:
                #if path[0] == [2,2]:
                #    print(score, path)
                #    for i in range(self.N):
                #        print(self.visited_graph[i])
                self.visited_graph[r][c] = 0
                if sum(score) > self.max_score:
                    self.max_score = sum(score)
                return
            
            for d in range(4):
                rn, cn = r+dn[d], c+dm[d]
                if not self._is_out_of_range([rn, cn]) and \
                    self.visited_graph[rn][cn] == 0:
                    _dfs([rn, cn], k-1, score[:], path[:])
            self.visited_graph[r][c] = 0

        r, c = curr
        self.visited_graph[r][c] = 1
        score, path = [self.graph[r][c]], [curr]   # - Debug Usage
        # Step 1) Only ^ or > or v (pruning)
        for d in [0, 1, 2]:
            rn, cn = r+dn[d], c+dm[d]
            if not self._is_out_of_range([rn, cn]):
                _dfs([rn, cn], 2, score[:], path[:])
        self.visited_graph[r][c] = 0

        # -------------------- 'ㅗ' shape------------------------
        candidate = []
        for d in range(4):
            rn, cn = r+dn[d], c+dm[d]
            if not self._is_out_of_range([rn,cn]):
                candidate.append(self.graph[rn][cn])

        tmp_score = -1
        if len(candidate) == 4:
            tmp_score = self.graph[r][c] + (sum(candidate) - min(candidate))
        elif len(candidate) == 3:
            tmp_score = self.graph[r][c] + sum(candidate)

        if tmp_score > self.max_score:
            self.max_score = tmp_score
        return

    def solve(self):
        """
        Time Complexitiy :
            Loop   : O(n^2)
            Search : O()
            ==> total : O()
        """
        for i in range(self.N):
            for j in range(self.M):
                self.search([i, j])

        return self.max_score

if __name__ == "__main__":
    problem = Solver()
    ans = problem.solve()

    print(ans)