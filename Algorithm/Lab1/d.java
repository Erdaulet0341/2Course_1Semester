import java.util.Scanner;
import java.util.Stack;

public class d{

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        String s = in.next();
        Stack<Character> st = new Stack<>();

        for (int i=0; i<s.length(); i++){
            char c = s.charAt(i);
            if(st.empty()){
                st.add(c);
            }
            else{
                if (st.peek() == c){
                    st.pop();
                }
                else{
                    st.add(c);
                }
            }
        }
        if (st.empty()){
            System.out.println("Yes");
        }
        else{
            System.out.println("No");
        }
    }
}