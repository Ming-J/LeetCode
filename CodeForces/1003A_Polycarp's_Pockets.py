import sys

class Pocket:
    def __init__(self):
        self.arr = {}
    
    def input(self,inputs):
        for x in inputs:
            if x in self.arr:
                self.arr[x] += 1
            else:
                self.arr[x] = 1

    def cal(self):
        np = 0
        for val in self.arr:
            np = max(np,self.arr[val])
        return np

def main():
    n = int(sys.stdin.readline())
    inputs = [int(x) for x in sys.stdin.readline().split()]
    t = Pocket()
    t.input(inputs)
    print(t.cal())

if __name__ == "__main__":
    main()