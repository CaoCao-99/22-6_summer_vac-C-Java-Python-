import java.awt.desktop.PreferencesEvent;
import java.awt.image.AreaAveragingScaleFilter;
import java.time.chrono.ThaiBuddhistEra;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Vector;
public class Main {
    static int m, n =0;
    static int [] input = new int[300];
    static boolean check(int answer){
        int count = 1;
        int c = answer;
        for(int i=0; i<n; i++){
            c-= input[i];
            if(c<0){
                c = answer - input[i];
                count++;
            }
        }
        return count <=m;
    }



    public static void main(String args[]) {
        StringBuilder sb = new StringBuilder();
        sb.setLength(0);
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        int sum = 0;
        int low = 0;
        int high = 0;
        //Arrays.fill(answer,' ');
        for(int i=0; i<n; i++){
            input[i] = sc.nextInt();
            if(low < input[i])low =input[i];
            sum+=input[i];
        }
        int mid = 0;
        high = sum;
        int answer  =0;
        while(low <= high){
            mid = (low + high)/2;
            if(check(mid)){
                high = mid -1;
                answer  = mid;
            }
            else{
                low = mid + 1;
            }
        }
        System.out.println(answer);
        mid  = answer;
        int count  = 0;
        for(int i = 0 ; i < n; i++){
            mid -= input[i];
            if(mid < 0){
                mid = answer - input[i];
                System.out.print(count + " ");
                count= 0;
                m--;
            }
            count++;
            if(n -  i == m){
                System.out.print(count+ " ");
                m--;
                for(int j=0; j<m; j++){
                    System.out.print(1+" ");
                }
            }
        }

    }

}