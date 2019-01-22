import sys

class Game:
    def playCard(self, hands, card):
        for h in hands:
            if h[0] == card[0] or h[1] == card[1]:
                return True
        return False

def main():
    card = sys.stdin.readline()
    hands = sys.stdin.readline().split()
    t = Game()
    print("YES") if t.playCard(hands,card) else print("NO")
    

if __name__ == "__main__":
    main()