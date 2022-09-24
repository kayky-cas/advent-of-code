import java.util.Scanner;

public class C2 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    String command = "";

    // a, h, d
    int[] pos = { 0, 0, 0 };

    while (true) {
      command = scanner.next();
      if (command.equals("q"))
        break;
      int value = scanner.nextInt();
      int index = 0;

      if (command.equals("forward")) {
        index = 1;
        pos[2] += value * pos[0];
      }

      else if (command.equals("up"))
        value = -value;

      pos[index] += value;
    }

    System.out.println(pos[2] * pos[1]);
  }
}