import sys

def main():
    input = sys.stdin.readline().strip()
    #input = " CodeForces"
    output = ""
    for i in input:
      if i.upper() not in ("A", "O", "Y", "E", "U", "I"):
          output = output + "." + i.lower()
    print output

if (__name__ == "__main__"):
    main()
