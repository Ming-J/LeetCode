import sys
'''
 n cards 
'''
class Game:
    """
    """
    def __init__(self, a):
        self.arr = a
    def cal(self):
        odd = 1
        lo = 0
        hi = len(self.arr) - 1
        ser = 0
        dim = 0
        while lo <= hi:
            if odd % 2 == 1 :
                ser += self.arr[lo] if self.arr[lo] > self.arr[hi] else self.arr[hi]
            else:
                dim += self.arr[lo] if self.arr[lo] > self.arr[hi] else self.arr[hi]
            if self.arr[lo] > self.arr[hi]:
                lo += 1
            else:
                hi -= 1
            odd += 1
        print("{0} {1}".format(ser,dim))

def main():
    n = int(sys.stdin.readline())
    arr = [int(x) for x in sys.stdin.readline().split()]
    temp = Game(arr)
    temp.cal()

if __name__ == ("__main__"):
    main()
