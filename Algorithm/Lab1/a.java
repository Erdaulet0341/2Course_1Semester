import java.util.Scanner;
import java.util.ArrayDeque;


public class a{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        ArrayDeque<Integer> deq = new ArrayDeque<>();
        int n = in.nextInt();
        for (int i=0; i<n; i++){
            int m = in.nextInt();
            for (int j = m; j>0; j++){
                deq.addLast(j);
                for (int k = 0; k<j; k++){
                    int temp = deq.pollLast();
                    deq.addFirst(temp);
                    
                }
            }
            System.out.println(deq);
        }
    }
}
