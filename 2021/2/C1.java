import java.util.Scanner;

public class C1 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    String command = "";

    // d, h
    int[] pos = { 0, 0 };

    while (true) {
      command = scanner.next();
      if (command.equals("q"))
        break;
      int value = scanner.nextInt();
      int index = 0;

      if (command.equals("forward"))
        index = 1;
      else if (command.equals("up"))
        value = -value;

      pos[index] += value;
    }

    System.out.println(pos[0] * pos[1]);
  }
}