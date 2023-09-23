import sys

class CleanBot:

    def __init__(self):
        # Input
        N, M = map(int, sys.stdin.readline().split())
        r, c, d = map(int, sys.stdin.readline().split())
        grid = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

        # Record
        self.N, self.M = N, M
        self.curr, self.see = [r, c], d     # 0,1,2,3 --> N,E,S,W
        self.grid = grid

        # clean_iter
        self.clean_iter = 0

    def _clean(self):
        self.grid[self.curr[0]][self.curr[1]] = 2
        self.clean_iter += 1

    def _search_Dust(self):
        r, c = self.curr[0], self.curr[1]
        
        rp1, rm1 = r+1, r-1
        cp1, cm1 = c+1, c-1

        # Check Wall Case and ignore
        if r == 0:
            rm1 = r+1
        if r == self.N-1:
            rp1 = r-1
        if c == 0:
            cm1 = c+1
        if c == self.M-1:
            cp1 = c-1
        
        return self.grid[rp1][c] * self.grid[rm1][c] \
            * self.grid[r][cp1] * self.grid[r][cm1]

    def _isBackWall(self):
        r, c = self.curr[0], self.curr[1]
        if self.see == 0:
            if self.curr[0] == self.N-1:
                return 1
        elif self.see == 1:
            if self.curr[1] == 0:
                return 1
        elif self.see == 2:
            if self.curr[0] == 0:
                return 1
        elif self.see == 3:
            if self.curr[1] == self.M-1:
                return 1

        if self.see == 0:
            if self.grid[r+1][c] == 1:
                return 1
        elif self.see == 1:
            if self.grid[r][c-1] == 1:
                return 1
        elif self.see == 2:
            if self.grid[r-1][c] == 1:
                return 1
        elif self.see == 3:
            if self.grid[r][c+1] == 1:
                return 1

        return 0
    
    def _moveback(self):
        # Already Check Wall Case
        [r, c] = self.curr

        if self.see == 0:
            self.curr = [r+1, c]
        elif self.see == 1:
            self.curr = [r, c-1]
        elif self.see == 2:
            self.curr = [r-1, c]
        elif self.see == 3:
            self.curr = [r, c+1]

    def _turnLeft(self):
        if self.see == 0:
            self.see = 3
        else:
            self.see = self.see - 1

    def _checkForward(self):

        [r, c] = self.curr

        # Check Range
        if self.see == 0:
            if r == 0:
                return 0
            if self.grid[r-1][c] == 0:
                return 1
        elif self.see == 1:
            if c == self.M-1:
                return 0
            if self.grid[r][c+1] == 0:
                return 1
        elif self.see == 2:
            if r == self.N-1:
                return 0   
            if self.grid[r+1][c] == 0:
                return 1   
        elif self.see == 3:
            if c == 0:
                return 0
            if self.grid[r][c-1] == 0:
                return 1
   
    def _moveForward(self):
        [r, c] = self.curr
        if self.see == 0:
            self.curr = [r-1, c]
        elif self.see == 1:
            self.curr = [r, c+1]
        elif self.see == 2:
            self.curr = [r+1, c]
        elif self.see == 3:
            self.curr = [r, c-1]
    
    def start(self):

        while True:
            # Step 1)
            if self.grid[self.curr[0]][self.curr[1]] == 0:
                self._clean()
            
            # Step 2)
            if self._search_Dust() != 0:
                if not self._isBackWall():
                    self._moveback()
                else:
                    return self.clean_iter
            # Step 3)
            else:
                self._turnLeft()
                if self._checkForward():
                    self._moveForward()
                  

bot = CleanBot()
iter = bot.start()

print(iter)