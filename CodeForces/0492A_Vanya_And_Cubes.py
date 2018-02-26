import sys

def main():
    cubes = int(sys.stdin.readline().strip())
    level = 1
    while cubes >= level*(level+1)/2:
        cubes -= level*(level+1)/2
        level += 1
    print(level-1)


if __name__ ==("__main__"):
    main()
