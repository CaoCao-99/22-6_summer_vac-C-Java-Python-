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
    static int n,m,c;

    static int [][][][]dp = new int[51][51][51][51];
    static int [][] orak = new int[51][51];
    public static int solve(int y, int x, int count, int num){
        if(y<1 || x < 1|| count < 0)return 0;
        if(dp[y][x][count][num] != -1) return  dp[y][x][count][num];
        dp[y][x][count][num] = 0;
        if(orak[y][x] == 0){
            dp[y][x][count][num] = solve(y-1,x,count,num)%1000007 + solve(y,x-1, count,num)%1000007;
        }
        else if(orak[y][x] == num) {
            for (int i = 0; i < num; i++) {
                dp[y][x][count][num] += solve(y - 1, x, count - 1, i) % 1000007 + solve(y, x - 1, count - 1, i) % 1000007;
            }
        }
        return dp[y][x][count][num] %1000007;
    }


    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = sc.nextInt();
        m = sc.nextInt();
        c = sc.nextInt();
        for(int i=0; i<51; i++){
            for(int j=0; j<51; j++){
                orak[i][j]= 0;
            }
        }
        int a,b;
        for(int i=1; i<=c; i++){
            a=sc.nextInt();
            b=sc.nextInt();
            orak[a][b] = i;
        }
        for(int i=0; i<51; i++){
            for(int j=0; j<51; j++){
                for(int x=0; x<51; x++){
                    for(int y=0; y<51; y++){
                        dp[i][j][x][y]=-1;
                    }
                }
            }
        }
        if(orak[1][1] ==0){
            dp[1][1][0][0] = 1;
        }
        else{
            dp[1][1][1][orak[1][1]] = 1;
        }
        for(int i=0; i<=c; i++){
            int answer = 0;
            for(int j=0; j<=c; j++){
                answer += solve(n,m,i,j) %1000007;
            }
            System.out.print(answer%1000007 + " ");
        }
    }


}
