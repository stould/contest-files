mem = list(map(int, input().split(" ")))

mem.sort()

tri = (mem[0] + mem[1] > mem[2] or mem[1] + mem[2] > mem[3])
seg = (mem[0] + mem[1] == mem[2] or mem[0] + mem[1] == mem[3] or mem[1] + mem[2] == mem[3])

if tri:
  print("TRIANGLE")
elif seg:
  print("SEGMENT")
else:
  print("IMPOSSIBLE")


