package shine.codetree;

import java.io.*;
import java.util.StringTokenizer;

public class 방향에맞춰최대로움직이기 {

    private static int n;
    private static int res;
    private static int[][] MAP;
    private static int[][] directions;
    private static int[] dx = {0, -1, -1, 0, 1, 1, 1, 0, -1};
    private static int[] dy = {0, 0, 1, 1, 1, 0, -1, -1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine().trim());

        MAP = new int[n][n];
        directions = new int[n][n];

        StringTokenizer st;
        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine().trim());
            for(int j = 0; j < n; j++) {
                MAP[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine().trim());
            for(int j = 0; j < n; j++) {
                directions[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        st = new StringTokenizer(br.readLine().trim());
        int startX = Integer.parseInt(st.nextToken()) - 1;
        int startY = Integer.parseInt(st.nextToken()) - 1;

        go(startX, startY, 0);

        bw.write(String.valueOf(res));
        bw.flush();
        bw.close();
        br.close();
    }

    private static void go(int x, int y, int cnt) {
        int nowDir = directions[x][y];
        int nowValue = MAP[x][y];
        res = Math.max(res, cnt);

        int nx = x + dx[nowDir];
        int ny = y + dy[nowDir];
        while(possibleWay(nx, ny)) {
            int nextValue = MAP[nx][ny];

            if(nextValue > nowValue) {
                go(nx, ny, cnt+1);
            }

            nx += dx[nowDir];
            ny += dy[nowDir];
        }
    }

    private static boolean possibleWay(int x, int y) {
        if(x < 0 || y < 0 || x >= n || y >= n) return false;
        return true;
    }
}
