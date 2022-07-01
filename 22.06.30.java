import java.awt.image.AreaAveragingScaleFilter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Vector;
public class math {
    public static class data{
    int left;
    int right;
}
    static data [] input1 = new data[10001];



    static int [] low= new int[10001];
    static int [] high = new int[10001];
    static int [] answer = new int [10001];
    static int [] node = new int [10001];
    static int N=0, nodeIdx = 1;
    static int root = 0;
//전위 순회
    public static void DFS(int parent, int cnt){
        //좌측 자식 체크
        if(input1[parent].left !=-1){
            DFS(input1[parent].left, cnt+1);
        }
        low[cnt] = Math.min(low[cnt], nodeIdx);
        high[cnt] = Math.max(high[cnt], nodeIdx);
        answer[cnt] = high[cnt] - low[cnt] + 1;
        nodeIdx++;// 노드 추가해주기
        //우측 자식 체크
        if(input1[parent].right !=-1){
            DFS(input1[parent].right, cnt+1);
        }

    }

    public static void main(String args[]){
        for(int i=1; i<=N; i++){
            input1[i] = new data();
        }
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        Arrays.fill(low, 10001);
        int a,b,c;
        for(int i=0; i<N; i++){
            a=sc.nextInt();
            b=sc.nextInt();
            c=sc.nextInt();
            node[a]++;
            if(b!=-1){
                node[b]++;
            }
            if(c!=-1){
                node[c]++;
            }
            input1[a].left = b;
            input1[a].right = c;
        }

        for(int i=1; i<=N; i++){
            if(node[i] == 1){
                root = i;
                break;
            }
        }
        DFS(root, 1);
        int answer_cnt = 0;
        int answer_length = 1;

        for(int i=1; i<=N; i++){
            if(answer_length < answer[i]){
                answer_length = answer[i];
                answer_cnt = i;
            }
        }

        System.out.println(answer_cnt +" " + answer_length);
    }


}