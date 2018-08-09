import sys

def main():
    input = sys.stdin.readline().strip()
    prev = -1
    maxStep = 0
    for i,ch in enumerate(input):
        if (ch == 'A' or ch == 'E' or 
        ch =='I' or ch == 'O' or ch =='U' or ch=='Y'):
            maxStep = max(abs(i-prev),maxStep)
            prev = i
    maxStep = max(len(input) - prev,maxStep)
    print(maxStep)

if __name__ == ("__main__"):
    main()
