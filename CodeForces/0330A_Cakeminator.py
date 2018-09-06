import sys

class Cake:
    def __init__(self, row, col, ca):
        self.r = row
        self.c = col
        self.cell = ca

    def show(self):
        for i in range(self.r):
            print(self.cell[i])

    def calCell(self):
        countRow = 0
        for x in self.cell:
            if x == "."*self.c:
                countRow += 1
        countColCell = 0
        for i in range(self.c):
            isS = False
            for j in self.cell:
                if j[i] != '.':
                    isS = True
            if isS is False:
                countColCell += (self.r - countRow)
        return countColCell + (countRow*self.c)

def main():
    r,c = [int(x) for x in sys.stdin.readline().split()]
    cake = []
    for x in range(r):
        cake.append(sys.stdin.readline().strip())
    board = Cake(r,c,cake)
    print(board.calCell())
    

if __name__ == ("__main__"):
    main()
