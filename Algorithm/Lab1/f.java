import java.util.Scanner;

public class f {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int arr[];

        arr = new int[1005];
        arr[0] = 1;
        arr[1] = 2;

        int k = 2;
        int m = 3;
        int cnt = 0;
        while(k<1003){
            for (int i=2; i<m; i++){
                if( m%i == 0){
                    cnt++;
                }
            }
            if (cnt == 0){
                arr[k]=m;
                k++;
            }
            cnt=0;
            m++;
        }   
        System.out.println(arr[n]);    
    }
}
