import sys

'''
 Elections for N Candidates
 m cities
 
 first stage : 

'''

class Candidates:
    def __init__(self,n):
        self.votes = [0] * n

    def winner(self,i):
        self.votes[i] += 1

    def won(self):
        return self.votes.index(max(self.votes))+1
        
    def show(self):
        for c in self.votes:
            print(" {} ".format(c))
def main():
    n, m = [int(x) for x in sys.stdin.readline().split()]
    ca = Candidates(n)
    votes = []
    for i in range(m):
        row = [int(x) for x in sys.stdin.readline().split()]
        winner = row.index(max(row))
        ca.winner(winner)
        votes.append(row)
    print(ca.won())


if __name__ == ("__main__"):
    main()
