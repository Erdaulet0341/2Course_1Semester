import java.util.Scanner;
import java.util.Stack;

public class c{

    static boolean check(Stack<Character> st1, Stack<Character> st2){
        boolean flag = true;
        if (st1.size() != st2.size()){
            flag = false;
            return flag;
        }
        while(st1.empty() == false){
            if (st1.peek() == st2.peek()){
                st1.pop();
                st2.pop();
            }
            else{
                flag = false;
                return flag;
            }
        }
        return flag;
    }

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        String s1 = in.next();
        String s2 = in.next();

        Stack<Character> equal = new Stack<>();
        Stack<Character> equal1 = new Stack<>();
        
        for (int i = 0;  i<s1.length(); i++){
            char c = s1.charAt(i);
            if (c != '#'){
                equal.add(c);
            }
            else{
                equal.pop();
            }
        }

        for (int i = 0; i<s2.length(); i++){
            char c = s2.charAt(i);
            if (c != '#'){
                equal1.add(c);
            }
            else{
                equal1.pop();
            }
        }

        if (check(equal, equal1)){
            System.out.println("Yes");
        }
        else{
            System.out.println("No");
        }

    }
}