import java.awt.desktop.PreferencesEvent;
import java.awt.image.AreaAveragingScaleFilter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.time.chrono.ThaiBuddhistEra;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Vector;
public class Main {
    static String fir;
    static String sec;
    static char [][] answer = new char[17001][17001];
    static int [][] dp = new int[17001][17001];

    public static void print(int n, int m){
        if(n == 0 && m == 0){
            return;
        }
        else if(n == 0 && m >0){
            print(n,m-1);
            System.out.println("a " + sec.charAt(m));
        }
        else if(n > 0 && m==0){
            print(n-1,m);
            System.out.println("d " + fir.charAt(n));
        }
        else{
            if(answer[n][m] == 'a'){
                print(n - 1,m);
                System.out.println("a " + sec.charAt(n));
            }
            else if( answer[n][m] == 'c'){
                print(n-1, m-1);
                System.out.println("c "+ fir.charAt(n));
            }
            else if(answer[n][m] == 'm'){
                print(n-1, m-1);
                System.out.println("m " + sec.charAt(m));
            }
            else{
               print(n, m-1);
               System.out.println("d " + fir.charAt(n));
            }
        }
    }



    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        fir = sc.nextLine();
        sec = sc.nextLine();
        fir = '#' + fir;
        sec = '#' + sec;
        for(int i=0; i<fir.length(); i++){
            dp[0][i] = i;
            answer[0][i] = 'a';
        }
        for(int j=0; j<sec.length(); j++){
            dp[j][0] = j;
            answer[j][0]  =  'd';
        }
        for(int i=1; i<fir.length(); i++){
            //int idx = i%2;
            for(int j=1; j<sec.length(); j++){
                if(fir.charAt(i) == sec.charAt(j)){
                    dp[i][j] = dp[i-1][j-1];
                    answer[i][j] = 'c';
                }
                else{
                    dp[i][j] = Math.min(dp[i-1][j-1],Math.min( dp[i][j-1], dp[i-1][j]))+1;

                    if(dp[i][j] == dp[i-1][j-1]+1){
                        answer[i][j] = 'm';
                    }
                    else if( dp[i][j] == dp[i-1][j] +1){
                        answer[i][j] = 'a';
                    }
                    else{
                        answer[i][j] = 'd';
                    }
                }
            }
        }
        print(fir.length()-1, sec.length()-1);
    }


}
