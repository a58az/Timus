import java.io.*;
import java.util.HashMap;

public class TimusClass {
    private static final boolean status = System.getProperty("ONLINE_JUDGE") != null;
    private static final PrintWriter out = new PrintWriter(System.out);
    private static BufferedReader bin;

    public static void main(String[] args) throws Exception {
        bin = status ? new BufferedReader(new InputStreamReader(System.in))
                : new BufferedReader(new FileReader("input.txt"));

        String s = solve();

        System.out.println(s);
        out.close();
    }

    private static String solve() throws IOException {
        int n = Integer.parseInt(bin.readLine());
        final  String reg = "register";
        final  String log = "login";

        HashMap<String, String> registered = new HashMap<>(n);
        HashMap<String, String> logged = new HashMap<>(n);

        StringBuilder sb = new StringBuilder();
        String input, login, type;
        int pos, end;
        for (int i = 0; i < n; i++) {
            input = bin.readLine();
            end = input.indexOf(" ");
            type = input.substring(0, end);
            pos = end + 1;
            end = input.indexOf(" ", pos);
            login = end >= 0 ? input.substring(pos, end) : input.substring(pos);

            switch (type) {
                case reg:
                    if (registered.containsKey(login)) {
                        sb.append("fail: user already exists");
                    } else {
                        registered.put(login, input.substring(end + 1));
                        sb.append("success: new user added");
                    }

                    break;
                case log:
                    if (!registered.containsKey(login)) {
                        sb.append("fail: no such user");
                    } else if (!registered.get(login).equals(input.substring(end + 1))) {
                        sb.append("fail: incorrect password");
                    } else if (logged.containsKey(login)) {
                        sb.append("fail: already logged in");
                    } else {
                        logged.put(login, login);
                        sb.append("success: user logged in");
                    }

                    break;
                default:
                    if (!registered.containsKey(login)) {
                        sb.append("fail: no such user");
                    } else if (!logged.containsKey(login)) {
                        sb.append("fail: already logged out");
                    } else {
                        logged.remove(login);
                        sb.append("success: user logged out");
                    }

                    break;
            }
            sb.append("\n");
        }

        return sb.toString();
    }
}