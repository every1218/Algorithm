import javax.swing.*;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int cnt=0;

        while(n-- > 0){
            Stack<Character> stack = new Stack<>();
            String str = input.next();

            for(int i = 0; i < str.length(); i++){
                if(stack.isEmpty() || str.charAt(i) != stack.peek())
                    stack.push(str.charAt(i));
                else if(stack.peek() == str.charAt(i)){
                    stack.pop();
                }
            }

            if(stack.isEmpty()){
                cnt++;
            }
        }

        System.out.println(cnt);
    }
}

