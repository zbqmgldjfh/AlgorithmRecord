package shine.codetree;

import java.io.*;

public class 가능한수열중최솟값구하기 {

    private static int n;
    private static String res = "";
    private static int[] arr;
    private static BufferedReader br;
    private static BufferedWriter bw;

    public static void main(String[] args) throws IOException  {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        arr = new int[n+1];

        go(1);
    }

    public static void go(int len) throws IOException {
        if(len > n) {
            String temp = "";
            for(int i = 1; i <= n; i++) {
                temp += arr[i];
            }

            bw.write(temp);
            bw.flush();
            bw.close();
            br.close();
            System.exit(0);
            return;
        }

        if(len == 1) {
            for(int i = 4; i <= 6; i++) {
                arr[len] = i;
                go(len + 1);
            }
        } else {
            for(int i = 4; i <= 6; i++) {
                arr[len] = i;
                if(isValidLen(len)) {
                    go(len + 1);
                }
            }

        }
    }

    private static boolean isValidLen(int len) {
        int half = len / 2;

        for(int i = 1; i <= half; i++) {
            int start = len - i + 1;
            int end = len;

            int cnt = 0;
            for(int j = start; j <= end; j++) {
                if(arr[j] == arr[j-i]) {
                    cnt++;
                }
            }

            if(cnt == i) return false;
        }

        return true;
    }
}
