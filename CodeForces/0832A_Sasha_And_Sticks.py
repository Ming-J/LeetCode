import sys

class game:
    def __init__(self):
        self.sasha = 0
        self.lena = 0

    def win(self,stick,remove):
        if (stick//remove)%2 == 0:
            return False
        else:
            return True

def main():
    s, t = [int(x) for x in sys.stdin.readline().split()]
    g = game()
    if g.win(s,t):
        print("YES")
    else:
        print("NO")

if __name__ == ("__main__"):
    main()
