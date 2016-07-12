def main():
    while(True):
        N = input()  
        if(N == 'END'):
            break

        original = int(N)

        if(N == '0'):
            print('-1')
            continue
        if(N == '9'):
            print(-19)
            continue
     
        val = 0
        for s in N:
            if(s == '-'):
                continue
            val += int(s)
        val += 1
        ans = 0
        N = list(N)
        idx = len(N) - 2
        while(idx >= 0 and (N[idx + 1] == '9' or N[idx + 1] == '8')):
            idx -= 1
        ans = 0
        if(N[0] == '-'):
            nidx = len(N) - 1
            while(nidx >= 0 and N[nidx] == '9'):
                nidx -= 1
            if(nidx == 0):
                N = '-1' + ''.join(N)[1:]
                N = int(''.join(N))
            else:
                N = int(''.join(N))
                N -= 1            
            print(N)
            continue
        elif(idx == -1):
            nidx = len(N) - 1
            while(nidx >= 0 and N[nidx] == '9'):
                nidx -= 1
            if(nidx == -1):
                ans = int('-1' + ''.join(N))
            else:
                nlist = list(N)
                nlist[nidx] = chr(ord(nlist[nidx]) + 1)
                ans = int('-' + ''.join(nlist))
        elif(idx >= 0 and idx < len(N)):
            while(N[idx] == '0' or N[idx + 1] == '8'):
                idx -= 1

            nlist = list(N)
            nlist[idx] = chr(ord(nlist[idx]) - 1)
            nlist[idx + 1] = chr(ord(nlist[idx + 1]) + 2)
            ans = max(ans, int(''.join(nlist)) if int(''.join(nlist)) < original else ans)
            
        
        ans2 = chr(ord(N[0]) - 1)
        
        aux = val
        val -= int(ans2)
        while(val >= 9):
            ans2 += '9'
            val -= 9
        if(val > 0):
            ans2 += chr(ord('0') + val)
        while(len(ans2) < len(N) - 1):
            ans2 += '0'
        ans = max(ans, int(ans2) if int(ans2) < original else ans)

        ans3 = ''
        while(aux >= 9):
            ans3 += '9'
            aux -= 9
        if(aux > 0):
            ans3 += chr(ord('0') + aux)
        
        while(len(ans3) < len(N) - 1):
            ans3 += '0'
        
        ans = max(ans, int(ans3) if int(ans3) < original else ans)
        
        print(ans)
   
main()
