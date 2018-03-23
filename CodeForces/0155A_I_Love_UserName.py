import sys

def main():
    contest = int(sys.stdin.readline().strip())
    scores = [int(x) for x in sys.stdin.readline().strip().split()]
    minScores = 0
    maxScores = 0
    amazing = 0
    for i in range(0,contest):
        if i == 0:
            minScores = maxScores= scores[i]
        else:
            if scores[i] > maxScores:
               amazing += 1
               maxScores = scores[i]
            elif scores[i] < minScores:
                amazing += 1
                minScores = scores[i]
    print(amazing)

if __name__ == ("__main__"):
    main()
