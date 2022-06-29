import java.util.Arrays;
import java.util.Scanner;

public class math {
    static int cnt = 0;
    static int prime[] = new int[170000];
    static boolean IsPrime[] = new boolean[1000000];
    //Arrays.fill(IsPrime , true);
    public static void getPrime(){
        for(int i=0; i<1000000; i++){
            IsPrime[i] = true;
        }

        for(int i=2;i <=Math.sqrt(1000000); i++){
            if(IsPrime[i] == false)continue;
            for(int j=i*i; j<1000000; j+=i){
                IsPrime[j] = false;
            }
        }

        for(int i=2; i<1000000; i++){
            if(IsPrime[i]){
                prime[cnt] = i;
                cnt++;
            }
        }
    }

    public static void main(String args[]){
        getPrime();
        int N;
        int input[] = new int[100];
        int [][] input_prime= new int[100][170000];
        int sum_prime[] = new int[170000];
        for(int j=0; j<100; j++) {
            for (int i = 0; i < 170000; i++) {
                input_prime[j][i]=0;
            }
        }
        for(int i=0; i<100; i++){
            input[i] = 0;
        }
        //Arrays.fill(input_prime, 0);
        //Arrays.fill(sum_prime, 0);

        Scanner sc = new Scanner(System.in);
        N=sc.nextInt();
        for(int i =0; i<N; i++){
            input[i] = sc.nextInt();
        }

        for(int i =0; i<N; i++){
            for(int j=0; j<cnt; j++){
                while(input[i] % prime[j] == 0){
                    input[i]/=prime[j];
                    input_prime[i][j]++;
                    sum_prime[j]++;
                }
            }
        }
        int answer=1;
        int answer_cnt  =0;
        for(int i=0; i<cnt; i++){
            sum_prime[i] /=N;
        }
        for(int i=0; i<cnt; i++){
            if(sum_prime[i] >=1){
                answer *= Math.pow(prime[i], sum_prime[i]);
            }
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<cnt; j++){
                if(sum_prime[j] - input_prime[i][j] > 0){
                    answer_cnt+=sum_prime[j] - input_prime[i][j];
                }
            }
        }
        System.out.print(answer+" "+ answer_cnt);
    }


}