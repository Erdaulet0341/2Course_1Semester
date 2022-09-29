import java.util.Scanner;
import java.util.LinkedList;

class c{
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        LinkedList<String> linky = new LinkedList<>();
        for (int i = 0; i<n; i++){
            String l = in.next();
            linky.add(l);
        }
        LinkedList<String> linky2 = new LinkedList<>();
        for (int i = 0; i<n; i++){
            if (i == k){
                for(int j=n-1; j>=k; j--){
                    linky2.addFirst(linky.get(j));
                }
                break;
            }
            else{
                linky2.add(linky.get(i));
            }
        }
        for (int i=0; i<linky2.size(); i++){
            System.out.print(linky2.get(i) + " ");
        }
    }
}
