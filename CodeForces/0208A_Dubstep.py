import sys

def main():
    input = sys.stdin.readline().strip()
    input = input.replace("WUB",' ')
    input = input.strip(' ')
    input = input.replace("  ",' ')
    print(input)

if __name__ == ("__main__"):
    main()
