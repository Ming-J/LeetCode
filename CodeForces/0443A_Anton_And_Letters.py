import sys

class Letter:
    def __init__(self, line):
        line = line[1:len(line)-1]
        self.let = set([])
        for c in line:
            if c.islower():
                self.let.add(c)
        print(len(self.let))

def main():
    line = sys.stdin.readline().strip()
    anton = Letter(line)
    
if __name__ == ("__main__"):
    main();
