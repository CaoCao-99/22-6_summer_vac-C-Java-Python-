import java.awt.desktop.PreferencesEvent;
import java.awt.image.AreaAveragingScaleFilter;
import java.time.chrono.ThaiBuddhistEra;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Vector;
public class Main {
    static int [][] input = new int[64][64];
    static void draw(int y, int x, int size){
        if(size == 1){
            System.out.print(input[y][x]);
            return;
        }
        Boolean isone = true;
        Boolean iszero = true;
        for(int i =0; i<size; i++){
            for(int j=0; j<size; j++){
                if(input[y+i][x+j] == 1)iszero = false;
                if(input[y+i][x+j] == 0)isone = false;
            }
        }
        if(iszero){System.out.print(0);
            return;}

        if(isone){System.out.print(1);
        return;}

        System.out.print('(');
        int resize = size /2;
        draw(y,x, resize);
        draw(y, x+resize, resize);
        draw(y+ resize, x, resize);
        draw(y+resize, x+resize, resize);
        System.out.print(')');


    }



    public static void main(String args[]) {
        StringBuilder sb = new StringBuilder();
        sb.setLength(0);
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        //Arrays.fill(answer,' ');
        for(int i=0; i<n; i++){
            String str  = sc.next();
            for(int j=0; j<n; j++){
                input[i][j] = str.charAt(j)-'0';
            }
        }
       draw(0,0, n);

    }

}