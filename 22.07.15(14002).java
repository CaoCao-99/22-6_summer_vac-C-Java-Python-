import java.awt.desktop.PreferencesEvent;
import java.awt.image.AreaAveragingScaleFilter;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.time.chrono.ThaiBuddhistEra;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;
public class Main {
    static int check = 0;
    static int answer = 0;
    static int [] input = new int[1000];
    static int [] parent = new int [1000];
    static void printAns(int p){
        check++;
        if(check == answer){
            System.out.printf("%d ", input[p]);
            return;
        }
        printAns(parent[p]);
        System.out.printf("%d ", input[p]);
    }


    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String s =  br.readLine();
        StringTokenizer st = new StringTokenizer(s);

        int []dp = new int[1000];
        for(int i=0; i<n; i++){
            dp[i] = 1;
            input[i] = Integer.parseInt(st.nextToken());
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i > j && input[i] > input[j] && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
        }

        int idx = 0;
        for(int i=0; i< n; i++){
            if(answer < dp[i]){
                answer = dp[i];
                idx = i;
            }
        }
        System.out.println(answer);
        printAns(idx);
    }


}
