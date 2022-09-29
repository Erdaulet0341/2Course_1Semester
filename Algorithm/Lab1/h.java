import java.util.Scanner;

public class h {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        if (n == 0 || n == 1){
            System.out.println("NO");
            System.exit(0);
        }
        else if(n==2){
            System.out.println("YES");
            System.exit(0);
        }
        else{
            for (int i = 2; i<n; i++){
                if (n%i==0){
                    System.out.println("NO");
                    System.exit(0);
                }
            }
        }
        System.out.println("YES");
    }
}
