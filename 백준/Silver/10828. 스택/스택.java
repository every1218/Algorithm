import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Stack<Integer> s = new Stack<>();
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        while (n-- > 0) {
            String str = input.next();
            if(str.equals("push")){
                int num = input.nextInt();
                s.push(num);
            }else if(str.equals("pop")){
                if(s.isEmpty()){
                    System.out.println(-1);
                }else {
                    System.out.println(s.peek());
                    s.pop();
                }
            }else if(str.equals("top")){
                if(s.isEmpty()) System.out.println(-1);
                else  System.out.println(s.peek());
            }else if(str.equals("size")){
                System.out.println(s.size());
            }else if(str.equals("empty")){
                if(s.isEmpty()) System.out.println(1);
                else System.out.println(0);
            }
        }
    }
}

