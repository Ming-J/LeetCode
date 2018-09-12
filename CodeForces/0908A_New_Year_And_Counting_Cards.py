import sys

'''
n cards
lower case number and digit on other side
a e i o u with 0 2 4 6 8

flip over all card with vow, and odd number, and check if other side is even 

'''

class Game():
    def __init__(self,dealt):
        self.hand = dealt

    def calMinFlip(self):
        count = 0
        for c in self.hand:
            if c in "aeiou13579":
                count += 1
        return count

def main():
    cards = sys.stdin.readline()
    friend = Game(cards)    
    print(friend.calMinFlip())

if __name__ == ('__main__'):
    main()
