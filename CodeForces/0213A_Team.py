import sys

class problem:
    def __init__(self):
        self.count = 0

    def answerAble(self, a , b , c):
        if ( a is 1 and b is 1 ):
            self.count += 1
        elif ( a is 1 and c is 1 ):
            self.count += 1
        elif ( b is 1 and c is 1 ):
            self.count += 1

    def getCount(self):
        return self.count
    
def main():
    n = sys.stdin.readline()
    n = int(n)
    k = problem()
    for _ in range(n):
        # print sys.stdin.readline().strip().split()
        a, b, c = [int (x) for x in sys.stdin.readline().strip().split()]
        k.answerAble( a, b, c)
    print k.getCount()

if __name__ == ("__main__"):
    main()
