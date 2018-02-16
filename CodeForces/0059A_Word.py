import sys

def main():
    st = sys.stdin.readline().strip()
    low = 0
    for ch in st:
        if ch>='a' and ch <= 'z':
            low += 1
    upp = len(st) - low
    if low >= upp:
        print(st.lower())
    else:
        print(st.upper())


if __name__ == ("__main__"):
    main()
