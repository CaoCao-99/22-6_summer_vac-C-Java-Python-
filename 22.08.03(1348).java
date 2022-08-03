import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static int c_cnt = 0, p_cnt = 0;

    static class A{
        int y,x;
        A(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
    static int []dy = {-1,1,0,0};
    static int []dx = {0,0,-1,1};
    static ArrayList<Integer>[] V = new ArrayList[101];
    static char [][] input = new char[50][50];
    static boolean [] check = new boolean[100];
    static int [][] dist = new int [100][100];
    static int [][] car = new int[100][2];
    static int [][] visit = new int[50][50];
    static int [] used = new int[100];
    static int [][]park = new int[100][2];
    static int change(String a){
        if (a.charAt(0) >='a')return a.charAt(0) - 'a' + 26;
        return a.charAt(0) - 'A';
    }
    static void BFS(int car_num){
        for(int i=0; i<50; i++){
            Arrays.fill(visit[i], -1);
        }
        Queue <A> q = new LinkedList();
        q.add(new A(car[car_num][0], car[car_num][1]));
        visit[car[car_num][0]][car[car_num][1]] = 0;
        while(!q.isEmpty()){
            int h_y = q.peek().y;
            int h_x = q.peek().x;
            q.poll();
            for(int i=0; i<4; i++){
                int ny = h_y +dy[i];
                int nx = h_x +dx[i];
                if(ny<0 || nx<0|| ny>=n || nx>=m || visit[ny][nx]!=-1 || input[ny][nx] == 'X')continue;
                visit[ny][nx] = visit[h_y][h_x] +1;
                q.add(new A(ny,nx));
            }
        }
        for(int i=0; i<p_cnt; i++){
            if(visit[park[i][0]][park[i][1]] == -1){
                dist[car_num][i] = 999999999;
            }
            else{
                dist[car_num][i] = visit[park[i][0]][park[i][1]];
                V[car_num].add(i);
            }
        }
    }
    static boolean DFS(int car_num, int time){
        for(int i=0; i<V[car_num].size(); i++){
            int next = V[car_num].get(i);
            if(check[next] == true || dist[car_num][next] > time)continue;
            check[next] = true;
            if(used[next] == -1 || DFS(used[next], time)){
                used[next] = car_num;
                return true;
            }
        }
        return false;
    }

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        for(int i=0; i<100;i++){
            V[i]=new ArrayList();
        }
        for(int i=0; i<n; i++){
            String s = br.readLine();
            for(int j=0; j<m; j++){
                input[i][j] = s.charAt(j);
                if(input[i][j] == 'C'){
                    car[c_cnt][0] = i;
                    car[c_cnt][1] = j;
                    c_cnt++;
                }
                if(input[i][j] == 'P'){
                    park[p_cnt][0] = i;
                    park[p_cnt][1] = j;
                    p_cnt++;
                }
            }
        }
        if(c_cnt > p_cnt){
            System.out.println(-1);
            return;
        }
        if(c_cnt == 0){
            System.out.println(0);
            return;
        }
        for(int i=0; i<c_cnt; i++){
            BFS(i);
        }
        int s=0, e = 101 * 101, ret = 0, mid =0, answer = -1;
        while(s<=e){
            mid = (s+e)/2;
            ret = 0;
            Arrays.fill(used, -1);

            for(int i=0; i<c_cnt; i++){
                Arrays.fill(check, false);
                if(DFS(i, mid)){
                    ret++;
                }
            }
            if(ret == c_cnt){
                answer = mid;
                e = mid -1;
            }
            else{
                s = mid +1;
            }
        }
        System.out.println(answer);

    }
}
