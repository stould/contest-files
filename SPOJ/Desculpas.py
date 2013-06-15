test = 1
while True:
    c, f = map(int, input().split(''))
    guarda = {}
    for i in range(f):
        tmp = input().split('')
        guarda[i] = [int(tmp[0]), int(tmp[1])]
    
