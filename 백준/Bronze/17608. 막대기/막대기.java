import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        Stack<Integer>stack = new Stack<>();

        while(n-- > 0){
            int temp = input.nextInt();
            while(!stack.isEmpty() && stack.peek()<= temp){
                stack.pop();
            }
            stack.push(temp);
        }

        System.out.println(stack.size());
    }
}

