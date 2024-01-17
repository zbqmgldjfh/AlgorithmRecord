package shine.codetree;

import java.io.*;

public class 아름다운수 {

    private static int N;
    private static int cnt = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        N = Integer.parseInt(br.readLine().trim());

        go(0);

        bw.write(String.valueOf(cnt));
        bw.flush();
        bw.close();
        br.close();
    }

    public static void go(int len) {
        if(len == N) {
            cnt += 1;
            return;
        } else if(len > N) {
            return;
        }

        for(int i = 1; i <= 4; i++) {
            go(len + i);
        }
    }
}
