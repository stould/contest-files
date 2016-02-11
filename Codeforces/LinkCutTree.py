line = input().split(" ")

L = int(line[0])
R = int(line[1]) 
K = int(line[2])

base = 1;
ans = []
seen = False;

while base <= R:
    if base >= L:
        ans.append(str(base))
        seen = True;
    base = base * K

    
if not seen:
    print("-1")
else:
    print(" ".join(ans))
    
