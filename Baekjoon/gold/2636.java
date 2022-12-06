import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int N;
    static int M;
    static int time;
    static int cnt;

    static int[][] MAP;
    static boolean[][] visited;

    static int[] dx = {0, 1, 0, - 1};
    static int[] dy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        StringTokenizer st = new StringTokenizer(str, " ");
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        MAP = new int[N][M];
        visited = new boolean[N][M];
        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            st = new StringTokenizer(line, " ");
            for (int j = 0; j < M; j++) {
                int num = Integer.parseInt(st.nextToken());
                MAP[i][j] = num;
            }
        }

        while (!isAllMelted()) {
            time++;
            Queue<Position> q = new LinkedList<>();
            q.add(new Position(0, 0));
            visited[0][0] = true;

            while (!q.isEmpty()) {
                Position front = q.poll();
                int nowX = front.x;
                int nowY = front.y;

                for (int i = 0; i < 4; i++) {
                    int nextX = nowX + dx[i];
                    int nextY = nowY + dy[i];

                    if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= M) continue;

                    if (MAP[nextX][nextY] == 1) {
                        MAP[nextX][nextY] = 2;
                    }

                    if (!visited[nextX][nextY] && MAP[nextX][nextY] == 0) {
                        visited[nextX][nextY] = true;
                        q.add(new Position(nextX, nextY));
                    }
                }
            }

            melt();
            clear();
        }

        System.out.println(time);
        System.out.println(cnt);
    }

    private static void clear() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                visited[i][j] = false;
            }
        }
    }

    private static void melt() {
        cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (MAP[i][j] == 2) {
                    cnt++;
                    MAP[i][j] = 0;
                }
            }
        }
    }

    public static class Position {
        private int x;
        private int y;

        public Position(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static boolean isAllMelted() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (MAP[i][j] == 1) return false;
            }
        }
        return true;
    }
}
