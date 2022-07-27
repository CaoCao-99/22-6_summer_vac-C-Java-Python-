import java.awt.desktop.PreferencesEvent;
import java.awt.image.AreaAveragingScaleFilter;
import java.io.*;
import java.nio.CharBuffer;
import java.time.chrono.ThaiBuddhistEra;
import java.util.*;

class P{
    public int y,x,w;
    P(int y,int x, int w){
        this.y = y;
        this.x = x;
        this.w = w;
    }
}


public class Main {
    static int n,m;
    static int []Size;
    static int []Parent;

    static int DFS(int y, int x, int idx){
        Queue <P> q = new LinkedList<>();
        q.add(new P(y,x));
        visit[y][x] = true;
        group[y][x] = idx;
        int cnt =1;
        while(!q.isEmpty()) {
            int h_x = q.peek().x;
            int h_y = q.peek().y;
            q.remove();
            for (int i = 0; i < 4; i++) {
                int n_x = h_x + dx[i];
                int n_y = h_y + dy[i];
                if (n_x < 0 || n_x >= m || n_y < 0 || n_y >= n || visit[n_y][n_x] == true || board[n_y][n_x] != 0)continue;
                visit[n_y][n_x] = true;
                q.add(new P(n_y, n_x));
                group[n_y][n_x] = idx;
                cnt++;
            }}
            return cnt;
        }

    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        //ArrayList<P> input = new ArrayList<>();
        P [] input = new P[m];
        Parent = new int[n];
        Size = new int[n];
        System.out.println(sb);
        //bw.write(sb.toString());
    }
    static void find(int y, int x){
        if(board[y][x] == 0){
            sb.append("0");
            return;
        }
        HashSet<Integer> set  = new HashSet<>();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx <0 || nx >=m || ny<0 || ny >=n)continue;
            set.add(group[ny][nx]);
        }
        int cnt = 1;
        for(int e : set){
            cnt += groupCount.get(e);
        }
        cnt %= 10;
        sb.append(cnt);
    }
}
