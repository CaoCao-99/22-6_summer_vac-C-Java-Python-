import java.io.*;
import java.util.*;

public class Main {
    static int n;

     static class T{
        int u ,v, w;
        T(int u,int v, int w){
            this.u = u;
            this.v = v;
            this.w = w;
        }

    }

    static ArrayList<Integer>[] input = new ArrayList[52];
    static int [][] cap = new int[52][52];
    static int [][] flow = new int[52][52];
    static int []visit = new int[52];
    static int change(String a){
        if (a.charAt(0) >='a')return a.charAt(0) - 'a' + 26;
        return a.charAt(0) - 'A';
    }


    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        int a,b,c;
        int answer = 0;
        for(int i=0; i<52; i++){
            input[i] = new ArrayList<Integer>();
        }
        for(int i=1; i<=n; i++){
            st = new StringTokenizer(br.readLine());
            String d,e;
            d = st.nextToken();
            a = change(d);
            e = st.nextToken();
            b = change(e);
            c = Integer.parseInt(st.nextToken());
            input[a].add(b);
            input[b].add(a);
            cap[a][b]+=c;
            cap[b][a] +=c;
        }
        while(true){
            Arrays.fill(visit,-1);
            Queue<Integer> q = new LinkedList<>();
            q.add(0);
            while (!q.isEmpty()){
                int here = q.poll();
                if(here == 25)break;
                for(int i=0; i<input[here].size(); i++) {
                    int next = input[here].get(i);
                    if (visit[next] == -1 && cap[here][next] - flow[here][next] > 0) {
                        q.add(next);
                        visit[next] = here;
                    }
                }
            }
            if(visit[25] == -1)break;
            int mini = 999999999;
            for(int i = 25; i!=0; i = visit[i]){
                mini = Math.min(mini, cap[visit[i]][i] - flow[visit[i]][i]);
            }
            for(int i=25;  i!=0; i = visit[i]){
                flow[visit[i]][i] += mini;
                flow[i][visit[i]]-= mini;
            }
            answer += mini;
        }
        System.out.println(answer);

    }
}
