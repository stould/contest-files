n = list(map(int, input().split(" ")))

numbers = 0

for i in range(0, n[0]):
  if n[1] - 2 >= 0:
    n[1] = n[1] - 2
    numbers = numbers + 1

while n[1] > 0:
  n[1] = n[1] - 1
  if numbers > 0:
    numbers = numbers - 1
print(numbers)
