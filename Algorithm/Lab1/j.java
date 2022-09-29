import java.util.ArrayDeque;
import java.util.Scanner;

public class j{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        ArrayDeque<Integer> deq = new ArrayDeque<>();
    
        int f = 0;
        
        while(f != 1){
            char c = in.next().charAt(0);
            if (c == '-' || c == '+'){
                int n = in.nextInt();
                if (c == '+'){
                    deq.addFirst(n);
                }
                else if (c == '-'){
                    deq.addLast(n);
                }
            }
            else{
                if (c == '*'){
                    if (deq.size() == 1){
                        int g3 = deq.poll();
                        System.out.println(g3 + g3);
                    }
                    else if (deq.isEmpty()){
                        System.out.println("error");
                    }
                    else{
                        int g1 = deq.pollFirst();
                        int g2 = deq.pollLast();
                        System.out.println(g1 + g2);
                    }
                }
                else{
                    f = 1;
                }
            }
        }
    }
}
