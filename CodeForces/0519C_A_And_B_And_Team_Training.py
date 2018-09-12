import sys

'''
A - 3 ppl 1 experienced and two newbie
B - 3 ppl 2 experienced and 1 newbie
mixed of two, find the most number of team possible

n experienced and m newbies 

2 ppl 

'''
class Training:
    def __init__(self,exp,new):
        self.exp = exp
        self.new = new

    def calTeam(self):
        team = 0;
        ex = self.exp
        eb = self.new
        while ex > 0 and eb > 0:
            if ex == 1 and eb == 1:
                break
            elif ex > eb:
                ex -= 2
                eb -= 1
            else:
                eb -= 2
                ex -= 1
            team += 1
        return team
                   
    def calType(self,exp,new):
        team = 0
        minTeam = min(exp//2,new)
        new -= minTeam
        exp -= 2*minTeam
        team += minTeam
        minAnother = min(new//2,exp)
        team += minAnother
        return team
        

def main():
    ex, nb = [int(x) for x in sys.stdin.readline().split()]
    ab = Training(ex,nb)
    print(ab.calTeam())


if __name__ == ("__main__"):
    main()
