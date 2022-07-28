import java.awt.desktop.PreferencesEvent;
import java.awt.image.AreaAveragingScaleFilter;
import java.io.*;
import java.nio.CharBuffer;
import java.time.chrono.MinguoEra;
import java.time.chrono.ThaiBuddhistEra;
import java.util.*;
public class Main {
    static int n,m,s,t,start,target,cnt=0,scnt=1;
    static ArrayList<ArrayList<Integer>> adj;
    static ArrayList<ArrayList<Integer>> scc;
    static Stack<Integer>st = new Stack<>();
    static int [] sccn, discover, country, answer;

    static int DFS(int x){
        st.push(x);
        discover[x] = cnt++;
        int parent = discover[x];
        for(int i =0; i<adj.get(x).size(); i++){
            int next  = adj.get(x).get(i);
            if(discover[next] == -1){
                parent = Math.min(parent, DFS(next));
            }
            else if(sccn[next] == -1){
                parent = Math.min(parent, discover[next]);
            }
        }
        if(parent == discover[x]){
            while(true) {
                int here = st.peek();
                st.pop();
                sccn[here] = scnt;
                country[scnt]++;
                if(s == here)start = scnt;
                if(t == here)target = scnt;
                if(here == x)break;
            }
            scnt++;
        }
        return parent;
    }

    static void BFS(int start){
        Queue <Integer> q = new LinkedList();
        answer[start] = country[start];
        q.add(start);
        while(!q.isEmpty()){
            int here = q.peek();
            q.remove();
            for(int i=0; i<scc.get(here).size(); i++){
                int next = scc.get(here).get(i);
                if(answer[next] < answer[here] + country[next]){
                    answer[next] = answer[here] + country[next];
                    q.add(next);
                }
            }
        }
    }


    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        s = Integer.parseInt(st.nextToken());
        t = Integer.parseInt(st.nextToken());
        discover = new int[n+1];
        sccn = new int[n+1];
        country = new int[n+1];
        answer = new int[n+1];
        adj = new ArrayList<>();
        scc = new ArrayList<>();
        for(int i =0; i<=n; i++){

            scc.add(new ArrayList<>());

            adj.add(new ArrayList<>());
        }
        int a,b;
        for(int i=1; i<=m; i++){
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            adj.get(a).add(b);
        }
        Arrays.fill(discover, -1);
        Arrays.fill(sccn, -1);
        Arrays.fill(country, 0);
        Arrays.fill(answer, 0);
        //ArrayList<P> input = new ArrayList<>();
        for(int i=1; i<=n; i++){
            if(discover[i] == -1)DFS(i);
        }
        if(start == target){
            System.out.println(country[start]);
            return;
        }
        for(int i=1; i<=n; i++){
            for(int j=0; j<adj.get(i).size(); j++){
                int next = adj.get(i).get(j);
                if(sccn[i] != sccn[next]){
                    scc.get(sccn[i]).add(sccn[next]);
                }
            }
        }
        BFS(start);
        System.out.println(answer[target]);
        return;
    }
}
