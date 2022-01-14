import java.util.*;
public class Main {
    static double ans;
    static int n, t;
    static int[] ax = new int[21];
    static int[] ay = new int[21];
    static boolean[] c = new boolean[21];
    static void go(int cnt, int index) {
        if (cnt == n / 2) {
            double x = 0, y = 0;
            for (int i = 0; i < n; i++) {
                if (c[i]) {
                    x -= ax[i];
                    y -= ay[i];
                }
                else {
                    x += ax[i];
                    y += ay[i];
                }
            }
            ans = Math.min(ans, Math.sqrt(x*x + y*y));
            return;
        }
        if (index == n) return;
 
        go(cnt, index + 1);
        c[index] = true;
        go(cnt + 1, index + 1);
        c[index] = false;
    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        t = in.nextInt();
        for (int tc = 1; tc <= t; tc++) {
            n = in.nextInt();
            ans = Double.MAX_VALUE;
            for (int i = 0; i < n; i++){
                ax[i] = in.nextInt();
                ay[i] = in.nextInt();
            }
            go(0, 0);
            System.out.printf("%.6f\n", ans);
        }
        in.close();
    }
}