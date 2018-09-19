import sys


class DieRoll:
    def cal(self,ya, wakko):
        rem = 6 - max(ya,wakko) + 1
        if rem == 6:
            return "1/1"
        elif rem == 5:
            return "5/6"
        elif rem == 4:
            return "2/3"
        elif rem == 3:
            return "1/2"
        elif rem == 2:
            return "1/3"
        elif rem == 1:
            return "1/6"
        else:
            return "0/1"

def main():
    x,y = [int(z) for z in sys.stdin.readline().split()]
    print(DieRoll.cal(DieRoll,x,y))


if __name__ == ("__main__"):
    main()
