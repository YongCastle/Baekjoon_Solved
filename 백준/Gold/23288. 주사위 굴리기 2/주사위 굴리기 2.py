import sys

#     ^  >   v  <
dn = [-1, 0, 1, 0]
dm = [0, 1, 0, -1]

class Solver:
    def __init__(self):
        self.N, self.M, self.K = map(int, sys.stdin.readline().split())
        self.map = []
        self.score_map = []
        for i in range(self.N):
            self.map.append(list(map(int, sys.stdin.readline().split())))
            self.score_map.append([-1 for _ in range(self.M)])
        
        #            ^  >  v  <  up down
        self.dice = [2, 3, 5, 4, 1, 6]

    def _check_can_move(self, curr, d) -> bool:
        r, c = curr
        # move
        r = r + dn[d]
        c = c + dm[d]
        return 0<=r and r<=self.N-1 and 0<=c and c<=self.M-1

    def _roll_dice(self, direction) -> int:
        """
            direction : #     ^  >   v  <
                              0  1   2  3
        """
    #   ^  >  v  <  up down
        a, b, c, d, e, f = self.dice
        if direction == 0:
            #            ^  >  v  <  up down
            self.dice = [e, b, f, d, c, a]
        elif direction == 1:
            #            ^  >  v  <  up down
            self.dice = [a, e, c, f, d, b]
        elif direction == 2:
            #            ^  >  v  <  up down
            self.dice = [f, b, e, d, a, c]
        elif direction == 3:
            #            ^  >  v  <  up down
            self.dice = [a, f, c, e, b, d] 

        return self.dice[-1]

    def _decide_direction(self, A, B, d) -> int:
        if A>B:
            # clockwise
            return d+1 if d!=3 else 0
        elif A<B:
            # counterclockwise
            return d-1 if d!=0 else 3
        else:
            return d

    
    def _return_iter_score(self, curr) -> int:
        # Check PreProcessed?
        if self.score_map[curr[0]][curr[1]] != -1:
            return self.score_map[curr[0]][curr[1]]
        else:
            curr_pos_num = self.map[curr[0]][curr[1]]
            checked_grid = [curr]
            stack = [curr]
            self.map[curr[0]][curr[1]] = -1     # visited
            while stack:
                r, c = stack.pop()

                for i in range(4):
                    next = [r+dn[i], c+dm[i]]
                    # Check Out of Range
                    if 0<=next[0] and next[0] <= self.N-1 and \
                        0<=next[1] and next[1] <= self.M-1:
                        if self.map[next[0]][next[1]] == curr_pos_num:
                            stack.append(next)
                            self.map[next[0]][next[1]] = -1     # visited
                            checked_grid.append(next)

        
            # update score Map and reset map
            score = curr_pos_num * len(checked_grid)
            for grid in checked_grid:
                self.map[grid[0]][grid[1]] = curr_pos_num
                self.score_map[grid[0]][grid[1]] = score
                
            return score

    def solve(self) -> int:
        score = 0
        curr = [0,0]
        d = 1

        for _ in range(self.K):
            # Step 1) Can Move?
            if not self._check_can_move(curr, d):
                d = d-2 if d>=2 else d+2
            
            # Step 2) roll the dice
            curr = [curr[0] + dn[d], curr[1] + dm[d]]
            iter_score = self._return_iter_score(curr)     # Return Score!
            d = self._decide_direction(self._roll_dice(d), self.map[curr[0]][curr[1]], d)
            score += iter_score
        
        return score


problem = Solver()
ans = problem.solve()
print(ans)
