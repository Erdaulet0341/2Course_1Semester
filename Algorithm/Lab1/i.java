import java.util.Scanner;
import java.util.ArrayDeque;

public class i {
    static boolean f( ArrayDeque<Character> deqq){
        if (deqq.contains('S') == false || deqq.contains('K') == false){
            return false;
        }
        return true;
    }
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        ArrayDeque<Character> deq = new ArrayDeque<>();
        String s = in.next();
        for (int i = 0; i<n; i++){
            char c = s.charAt(i);
            deq.add(c);
            
        } 
        boolean d = true;
        while(d){
            char c = deq.pollFirst();
            if (c=='K'){
                deq.remove('S');
                deq.add(c);
            }
            else {
                deq.remove('K');
                deq.add(c);
            }
            d = f(deq);
        }
        if (deq.contains('K')){
            System.out.println("KATSURAGI");
        }
        else{
            System.out.println("SAKAYANAGI");
        }
    }
}
