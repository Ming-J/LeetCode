import sys

class bit():
    def __init__(self):
        self.var = 0

    def add(self):
        self.var += 1
        
    def sub(self):
        self.var -= 1

    def printing(self):
        print self.var

def main():
    n = int( sys.stdin.readline().strip() )

    program = bit()

    lines = sys.stdin.readlines()
    for line in lines:
        for c in line:
            if c is '+':
                program.add()
                break
            elif c is '-':
                program.sub()
                break

    program.printing()

if __name__ == ('__main__'):
    main()
