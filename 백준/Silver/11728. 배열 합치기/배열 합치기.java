import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;
import java.lang.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int [] a = new int[1000005]; Arrays.fill(a,Integer.MAX_VALUE);
        int [] b = new int[1000005]; Arrays.fill(b,Integer.MAX_VALUE);
        int [] c = new int[2000005];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            a[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < m; i++){
            b[i] = Integer.parseInt(st.nextToken());
        }

        int a_num = 0;
        int b_num = 0;
        int c_num = 0;

        while(c_num < n+m){
            if(a[a_num] <= b[b_num]){
                c[c_num] = a[a_num];
                a_num++;
                c_num++;
            }else if(a[a_num] > b[b_num]){
                c[c_num] = b[b_num];
                b_num++;
                c_num++;
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n+m; i++){
            sb.append(c[i]).append(" ");
        }

        System.out.print(sb.toString());
    }
}