import java.util.Scanner;
import java.util.LinkedList;

class c{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        LinkedList<Integer> linky = new LinkedList<>();
        for (int i = 0; i<n; i++){
            int l = in.nextInt();
            linky.add(l);
        }
        int k = in.nextInt();
        int g = in.nextInt();
        linky.add(g, k);
        for (int i=0; i<linky.size(); i++){
            System.out.print(linky.get(i) + " ");
        }
    }
}