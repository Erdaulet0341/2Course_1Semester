import java.util.Scanner;

public class g {
    boolean chec_prime(int n){
        int cnt = 0;
        for (int i = 2; i<n; i++){
            if (n%i==0){
                cnt++;
            }
        }
        if (cnt == 0){
            return true;
        }
        else{
            return false;
        }
    } 

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
        
        int newArr[];
        newArr = new int[1005];

        g ch = new g();
        int cn = 0;
        
        for (int i=0; i<1005; i++){
            if(ch.chec_prime(i)){
                newArr[cn] = arr[i];
                cn++;
            }
        }    

        System.out.println(newArr[n+1]);
    }
}
