import java.awt.desktop.PreferencesEvent;
import java.awt.image.AreaAveragingScaleFilter;
import java.io.*;
import java.nio.CharBuffer;
import java.time.chrono.MinguoEra;
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
    static long []Size;
    static int []Parent;

    static int GetParent(int a){
        if(a == Parent[a])return a;
        return GetParent(Parent[a]);
    }
    static void mergeParent(int a, int b){
        if(Size[a] > Size[b]){
            Parent[b] = a;
            Size[a] += Size[b];
            Size[b] = 1;
        }
        else{
            Parent[a] = b;
            Size[b] += Size[a];
            Size[a] = 1;
        }
    }

    static boolean cmp (P a, P b){
        return a.w > b.w;
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
        Size = new long[n];
        for(int i=0; i<n; i++){
            Parent[i] = i;
            Size[i] = 1;
        }
        long sum =0;
        long answer = 0;
        for(int i=0; i<m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            int c = Integer.parseInt(st.nextToken());
            input[i] = new P(a,b,c);
            sum+=input[i].w;
        }
        Arrays.sort(input, new Comparator<P>() {
            @Override
            public int compare(P s1, P s2) {
                if(s1.w > s2.w)return -1;
                else return 1;
            }
        });

        for(int i=0; i<m; i++){
            int a = GetParent(input[i].y);
            int b = GetParent(input[i].x);
            if(a!=b){
                answer += (((Size[a] * Size[b])%1000000000) * sum) % 1000000000;
                mergeParent(a,b);
            }
            sum -= input[i].w;
        }
        System.out.println(answer%1000000000);
        //bw.write(sb.toString());
    }
}
