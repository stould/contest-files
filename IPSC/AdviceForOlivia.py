import sys

sys.stdin = open("a2.in", "r")
#sys.stdout = open("a1.out", "w")
    
T = int(input())

notes = [1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000]

for _ in range(T):
    input()
    ans = [ 0 for x in range(13) ]

    E, C = map(int, input().split(" "))

    money = E * 100 + C

    for i in range(len(notes) - 1, -1, -1):
        while money >= notes[i]:
            money -= notes[i]
            ans[i] += 1
    
    for i in range(13):
        sys.stdout.write("%s " % (str(ans[i])))
    print()
