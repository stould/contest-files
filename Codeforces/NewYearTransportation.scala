import java.util.Scanner;

object Main extends App {
  var input = new Scanner(System.in)

  var N = input.nextInt()
  var T = input.nextInt()

  var X = new Array[Int](N + 1)

  for (i <- 1 to (N - 1)) {
    X(i) = input.nextInt()
  }

  var pos = 1
  var reach = false

  while (pos <= T) {
    if (pos == T) {
      reach = true
      pos = N + 1;
    } else {
      pos = pos + X(pos)
    }
  }

  if (reach) {
    println("YES")
  } else {
    println("NO")
  }
}
