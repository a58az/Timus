import java.io.*;
import java.util.StringTokenizer;

public class TimusClass {
    static private BufferedReader bin;

    public static void main(String[] args) throws IOException {
        boolean status = System.getProperty("ONLINE_JUDGE") != null;
        bin = status ? new BufferedReader(new InputStreamReader(System.in)) : new BufferedReader(new FileReader("input.txt"));
        StreamTokenizer in = new StreamTokenizer(bin);
        StringTokenizer tok = null;
        PrintWriter out = new PrintWriter(System.out);

        solve();

        out.flush();

    }

    private static void solve() throws IOException {
        int n = Integer.parseInt(bin.readLine());
        int m = 1;

        StringBuilder sb = new StringBuilder();

        for (int i = 1; i < n; i++)
            sb.append('(');


        for (; n >= 1; n--, m++)  {
            sb.append(An(m, n));
            if (n != 1) sb.append(")");
        }

        System.out.println(sb.toString());
    }

    private static String An(int n, int m) {
        StringBuilder answer = new StringBuilder();
        final String sin = "sin(";
        char sign;
        boolean signMinus = true;


        for (int i = 1; i <= n; i++) {
            answer.append(sin);
            answer.append(i);

            if (i == n) continue;
            sign = signMinus ? '-' : '+';
            answer.append(sign);
            signMinus = !signMinus;
        }

        for (int i = 0; i < n; i++) {
            answer.append(")");
        }

        answer.append("+");
        answer.append(m);

        return answer.toString();
    }
}