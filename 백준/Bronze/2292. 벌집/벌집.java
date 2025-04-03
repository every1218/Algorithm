import javax.swing.*;
import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();

        if(n==1){System.out.println(1); return;}

        long num=1;
        int temp=6;
        int cnt=1;
        while(num<n){
            num +=temp;
            temp+=6;
            cnt++;
        }

        System.out.println(cnt);

    }
}


