import sys

def main():
  m , n = [int(c) for c in sys.stdin.readline().strip().split()]
  area = m * n
  print area / 2


if __name__ == ('__main__'):
  main()
