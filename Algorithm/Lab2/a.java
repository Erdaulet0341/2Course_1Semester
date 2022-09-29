import java.util.Scanner;
import java.lang.Math;
import java.util.LinkedList;

public class a{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        LinkedList<Integer> linky = new LinkedList<>();
        for (int i=0; i<n; i++){
            int k = in.nextInt();
            linky.addLast(k);
        }
        int c = in.nextInt();
        int index=0, min=10000000, l;
        for (int i=0; i<n; i++){
            l = Math.abs(linky.get(i)-c);
            if(l<min){
                min = l;
                index = i;
            }
        }
        System.out.println(index);
    }
} 