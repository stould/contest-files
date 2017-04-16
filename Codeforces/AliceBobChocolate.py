n = input()
mem = list(map(int, input().split(" ")))

i = 0
j = len(mem) - 1

alice = 0
bob = 0

if len(mem) == 1:
  alice = alice + 1
  print("%d %d" % (alice, bob))
  exit(0)

while True:
  tmp_i = mem[i]
  tmp_j = mem[j]
  if tmp_i < tmp_j:
    alice = alice + 1    
    mem[j] = mem[j] - mem[i]
    if i + 1 < len(mem):
      i = i + 1
    if i == j:
      bob = bob + 1
      break
  elif tmp_i > tmp_j:
    bob = bob + 1
    mem[i] = mem[i] - mem[j]    
    if j - 1 >= 0:
      j = j - 1
    if i == j:
      alice = alice + 1
      break
  else:
    alice = alice + 1
    bob = bob + 1
    if i  + 1 < len(mem):
      i = i + 1
    if j - 1 >= 0:
      j = j - 1
    if i - j == 1:
      break
    if i == j:
      alice = alice + 1
      break    
print("%d %d" % (alice, bob))
