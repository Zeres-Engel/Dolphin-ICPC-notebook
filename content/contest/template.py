import sys

def input():
    return sys.stdin.readline().strip()

def solve():
    pass

def main():
    test = 1
    test = int(input())
    for _ in range(test):
        solve()

if __name__ == "__main__":
    sys.stdin = open("input.inp","r")
    sys.stdout = open("input.out","w")
    main()