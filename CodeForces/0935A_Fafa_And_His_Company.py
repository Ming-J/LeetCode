import sys


class Fafa:
    def __init__(self, e):
        self.emp = e

    def printing(self):
        ways = 0
        for i in range(1, self.emp):
            if (self.emp - i) % i == 0:
                ways += 1
        return ways


def main():
    input = int(sys.stdin.readline())
    X = Fafa(input)
    print(X.printing())


if __name__ == "__main__":
    main()
