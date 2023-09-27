import sys
sys.setrecursionlimit(10**5) 

class Farmer():

    def __init__(self):
        self.M, self.N, self.K = map(int, sys.stdin.readline().split())
        self.farm = [[0 for _ in range(self.N)] for __ in range(self.M)]
        self.earthworm = 0
        self.vegetables = []
        
        for _ in range(self.K):
            r, c = map(int, sys.stdin.readline().split())
            self.vegetables.append([r,c])
            self.farm[r][c] = 1
        
    
    def _find_vegetable(self, cell):
        r, c = cell[0], cell[1]

        vegetable_cells = []
        if r != 0:
            if self.farm[r-1][c] == 1:
                vegetable_cells.append([r-1, c])

        if r != self.M-1:
            if self.farm[r+1][c] == 1:
                vegetable_cells.append([r+1, c])

        if c != 0:
            if self.farm[r][c-1] == 1:
                vegetable_cells.append([r, c-1])

        if c != self.N-1:
            if self.farm[r][c+1] == 1:
                vegetable_cells.append([r, c+1])

        return vegetable_cells


    def dfs(self, cell):
        r, c = cell[0], cell[1]

        #Excetpion Exit
        if self.farm[r][c] != 1:
            return
        
        self.farm[r][c] = 3 #visited
        
        for next in self._find_vegetable(cell):
            self.dfs(next)

    def put_earthworm(self):
        
        for r,c in self.vegetables:
            if self.farm[r][c] == 1:
                self.dfs([r,c])
                self.earthworm += 1


if __name__ == "__main__":
    T = int(input())

    answers = []

    for _ in range(T):
        manager = Farmer()
        manager.put_earthworm()
        answers.append(manager.earthworm)

    for i in range(T):
        print(answers[i])
