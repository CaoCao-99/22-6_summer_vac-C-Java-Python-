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


    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String []ss = br.readLine().split(" ");
        int r = Integer.parseInt(ss[0]);
        int c= Integer.parseInt(ss[1]);
        int [][][] input = new  int[1500][1500][2];
        int [][] banana = new int[1500][1500];
        int [][] apple = new int[1500][1500];
        int [][] sum = new int[1500][1500];
        int [][]dp = new int[1500][1500];
        for(int i =0; i<r; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=0; j<c; j++){
                String a = st.nextToken();
                if(a.charAt(0) == 'A'){
                    input[i][j][0] = Integer.parseInt(a.substring(1));
                }
                else{
                    input[i][j][1] = Integer.parseInt(a.substring(1));
                }
            }
        }
        for(int i=0; i<r; i++){
            for(int j=1; j<c; j++){
                banana[i][c-j-1] = banana[i][c-j] + input[i][c-j][1];
                apple[i][j] = apple[i][j-1] + input[i][j-1][0];
            }
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                sum[i][j] = apple[i][j] + banana[i][j];
            }
        }
        dp[0][0] = sum[0][0];
        for(int i=1; i<r; i++){
            dp[i][0] = dp[i-1][0] + sum[i][0];
        }
        for(int i=1; i<c; i++){
            dp[0][i] = dp[0][i-1] - input[0][i][1];
        }

        for(int i=1; i<r; i++){
            for(int j=1; j<c; j++){
                int right = dp[i][j-1] - input[i][j][1];
                int down = dp[i-1][j] + sum[i][j];
                int r_d = dp[i-1][j-1] + sum[i][j];
                dp[i][j] = Math.max(right,Math.max(down, r_d));
            }
        }
        System.out.println(dp[r-1][c-1]);




    }


}
