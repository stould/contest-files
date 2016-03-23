instance = 1

fat = list(range(1, 1000001))

mx = 1

while True:
  n = str(input())
  if len(n) == 0:
    break
  n = int(n)
  if n > mx:
    for i in range(mx, n+1):
      fat[i] = fat[i - 1] * i
      if i % 5 == 0:
        fat[i] = fat[i] / 10
    mx = n
    print("Instancia %d\n%d\n" % (instance, int(fat[n]%10)))    
  instance += 1
