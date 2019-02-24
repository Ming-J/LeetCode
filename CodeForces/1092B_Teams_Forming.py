import sys

"""
input n student and their skills
output min number of problem need to be sloved 
2 3 5 5 10 14
"""


def teams(skills):
    skills = sorted(skills)
    output2 = 0
    for i in range(0, len(skills), 2):
        dif = skills[i+1] - skills[i]
        output2 += dif
    print(output2)
    pass


def main():
    n = int(sys.stdin.readline())
    arr = map(int, sys.stdin.readline().split())
    teams(arr)


if __name__ == "__main__":
    main()
