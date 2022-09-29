import java.util.Scanner;
import java.util.ArrayDeque;

public class e {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int arr1[];
        arr1 = new int[5];
        int arr2[];
        arr2 = new int[5];
        int k = 0;
        for (int i=0; i<10; i++){
            int n = in.nextInt();
            if(i<5){
                arr1[i]=n;
            }
            else{
                arr2[k]=n;
                k++;
            }
    
        }

        ArrayDeque<Integer> bor = new ArrayDeque<>();
        ArrayDeque<Integer> nur  = new ArrayDeque<>();
        
        for (int i =0; i<5; i++){
            bor.add(arr1[i]);
            nur.add(arr2[i]);
        }
        int cnt = 0;
        int cntn = 0;
        int cntb = 0;
        boolean b = true;
        boolean n = true;
        int bori=0;
        int nuri=0;
        while(b || n){
            
            if (bor.isEmpty()){
                b = false;
                break;
            }
            else if (nur.isEmpty()){
                n = false;
                break;
            }
            else{
                bori = bor.pollFirst();
                nuri = nur.pollFirst();
                if (bori == 0 && nuri == 9){
                    bori = 9;
                    nuri = -1;
                }
                if (nuri == 0 && bori == 9){
                    nuri = 9;
                    bori = -1;
                }
            }
            if (bori>nuri){
                bor.addLast(bori);
                bor.addLast(nuri);
                cntb++;
                cnt++;
            }
            else{
                nur.addLast(bori);
                nur.addLast(nuri);
                cntn++;
                cnt++;
            }
            if (cnt>1000005){
                System.out.println("blin nichya");
                System.exit(0);
            }
            
        }
        if (n == false){
            System.out.println("Boris " + cntb);
        }
        if (b == false){
            System.out.println("Nursik " + cntn);
        }
    }
}
