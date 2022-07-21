import java.awt.desktop.PreferencesEvent;
import java.awt.image.AreaAveragingScaleFilter;
import java.io.*;
import java.time.chrono.ThaiBuddhistEra;
import java.util.*;


public class Main {
    public static class Target {
        public int y,x;
        public Target(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
    static Target[] target = new Target[100000];
    static void swap(Target a, Target b){
        int c  = a.x;
        int d = a.y;
        a.x=b.x;
        a.y = b.y;
        b.x = c;
        b.y = d;
    }
    static int CCW(Target a, Target b, Target c){
        return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
    }

    static double dist(Target a, Target b){
        return Math.sqrt( (a.x - b.x)*(a.x - b.x) + (a.y - b.y)* (a.y - b.y));
    }

    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int a,b;
        int c = Integer.parseInt(st.nextToken());
        ArrayList<Target> targets =  new ArrayList<>();
        for(int i=1; i<=c; i++){
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            targets.add(new Target(a ,b));
        }
        ArrayList<Target> list = new ArrayList<>(convexHull(targets));
        bw.write(rotatingCalipers(list) + "\n");
        br.close();
        bw.flush();
        bw.close();
    }
    static double rotatingCalipers(ArrayList<Target> CH){
        double answer =0;
        int j=1;
        for(int i=0; i<CH.size(); i++){
            int i_next = (1+i)%CH.size();
            for(; ;){
                int j_next  =(1+j)%CH.size();
                int bx = CH.get(i_next).x - CH.get(i).x;
                int by = CH.get(i_next).y - CH.get(i).y;
                int cx = CH.get(j_next).x - CH.get(j).x;
                int cy = CH.get(j_next).y - CH.get(j).y;

                long ccw = CCW(new Target(0, 0), new Target(by,bx), new Target(cy, cx));
                if(ccw > 0){
                    j = j_next;
                }
                else{
                    break;
                }
            }
            if(dist(CH.get(i), CH.get(j)) > answer){
                answer = dist(CH.get(i), CH.get(j));
            }
        }
        return answer;
    }
    static Target root = new Target(Integer.MAX_VALUE, Integer.MAX_VALUE);
    static Stack<Target> convexHull(ArrayList<Target> target){
        for(int i=0; i<target.size(); i++){
            if(root.y > target.get(i).y){
                root = target.get(i);
            }
            else if(root.y == target.get(i).y && root.x > target.get(i).x){
                root = target.get(i);
            }
        }
        target.sort(new Comparator<Target>() {
            @Override
            public int compare(Target o1, Target o2) {
                int ccw = CCW(root, o1, o2);
                if(ccw > 0){
                    return -1;
                }
                else if(ccw < 0 )return 1;
                else {
                    double distance1 = dist(root, o1);
                    double distance2 = dist(root, o2);

                    return Double.compare(distance1, distance2);
            }
        }});
        Stack<Target> stack = new Stack<>();
        stack.add(root);
        stack.add(target.get(1));
        for(int i=2; i<target.size(); i++){
            while(stack.size()>1 && CCW(stack.get(stack.size()-2),stack.get(stack.size()-1),target.get(i)) <= 0){
                stack.pop();
            }
            stack.push(target.get(i));
        }
        return stack;
    }


}
