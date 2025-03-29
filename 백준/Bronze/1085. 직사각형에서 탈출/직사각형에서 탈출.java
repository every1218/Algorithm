import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int x = input.nextInt();
        int y = input.nextInt();
        int w = input.nextInt();
        int h = input.nextInt();

        int ans =  Math.min(Math.min(x, y), Math.min(w - x, h - y));;

        System.out.println(ans);
    }
}

