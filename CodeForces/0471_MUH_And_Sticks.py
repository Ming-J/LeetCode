import sys
from collections import Counter

class Sticks:
    def __init__(self,sticks):
        self.s = sticks

    def animal(self):
        dic = Counter(self.s)
        if len(dic) == 1:
            return "Elephant"
        elif len(dic) == 2:
            return self.checkAli(dic,"Elephant","Bear")
        elif len(dic) == 3:
            return self.checkAli(dic,"Bear","")
        else:
            return "Alien"

    def checkAli(self,dic,default,alt):
        for key in dic:
            if dic[key] == 4:
                return default
            if dic[key] > 4:
                return alt
        return "Alien"
        
def main():
    st = [int(x) for x in sys.stdin.readline().split()]
    creat = Sticks(st)
    print(creat.animal())

if __name__ == ("__main__"):
    main()
