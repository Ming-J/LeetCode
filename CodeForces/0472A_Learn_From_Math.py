import sys

class Prime():
    def __init__(self):
        self.arr = set([1,2])
        self.arrMax = 2

def checkPrime(a):
        return a > 1 and all( a % i for i in range(2,int(a**0.5) +1))
                
    
def main():
    val = int(sys.stdin.readline().strip())
    front = 2
    tail = val - 2
    while( tail > front ):
        if checkPrime(front) is False and checkPrime(tail) is False:
            print(str(front)+" "+str(tail))
            return
        else:
            front += 1
            tail -= 1
    
if __name__ == ("__main__"):
    main()
