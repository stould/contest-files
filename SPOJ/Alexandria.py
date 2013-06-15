n = int(input())

for x in range(n):
  tmp = str(input())
  number = int(tmp[:tmp.index('!')])
  ct = tmp[:tmp.index('!')]
  
  print("%d %d\n" % (number, len(ct)))