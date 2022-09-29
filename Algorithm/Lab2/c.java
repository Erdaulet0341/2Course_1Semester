import java.util.Scanner;
import java.util.LinkedList;

class c{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        LinkedList<Integer> linky = new LinkedList<>();
        for (int i = 0; i<n; i++){
            int k = in.nextInt();
            linky.add(k);
        }
        for (int i=0; i<n; i++){
            if (i%2==0){
                System.out.print(linky.get(i) + " ");
            }
        }
    }
}