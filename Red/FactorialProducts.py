def main():
    N = int(input())
    for _ in range(N):
        a, b, c = map(int, input().split())
        A = [ int(i) for i in input().split() ]
        B = [ int(i) for i in input().split() ]
        C = [ int(i) for i in input().split() ]

        fa = 0
        fb = 0
        fc = 0
        for x in A:
            fa += x**4
        for x in B:
            fb += x**4
        for x in C:
            fc += x**4

        print('Case #%d:' % (_ + 1), end=' ')
        ans = [ (fa, 'A'), (fb, 'B'), (fc, 'C') ]
        ans = sorted(ans)
        if(ans[2][0] == ans[1][0]):
            print('TIE')
        else:
            print(ans[2][1])
            
main()
