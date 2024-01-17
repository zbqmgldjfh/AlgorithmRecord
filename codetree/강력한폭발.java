package shine.codetree;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class 강력한폭발 {

    private static int N;
    private static int res = 0;
    private static int[][] MAP;
    private static int[][] score;
    private static List<Position> bombPositions = new ArrayList<>();
    private static List<Integer> bombNumbers = new ArrayList<>();
    private static int[] dx = new int[]{0, 1, 0, -1};
    private static int[] dy = new int[]{1, 0, -1, 0};
    private static int[] ddx = new int[]{1, 1, -1, -1};
    private static int[] ddy = new int[]{1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine().trim());
        MAP = new int[N][N];
        StringTokenizer st;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine().trim());

            for (int j = 0; j < N; j++) {
                MAP[i][j] = Integer.parseInt(st.nextToken());
                if (MAP[i][j] == 1) {
                    bombPositions.add(new Position(i, j));
                }
            }
        }

        chooseNumbers(0);

        bw.write(String.valueOf(res));
        bw.flush();
        bw.close();
        br.close();
    }

    private static void chooseNumbers(int cnt) {
        if (cnt >= bombPositions.size()) {
            score = new int[N][N];

            for (int i = 0; i < bombPositions.size(); i++) {
                Position po = bombPositions.get(i);
                Integer bombNumber = bombNumbers.get(i);
                mark(po, bombNumber);
            }

            int temp = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (score[i][j] != 0) temp += 1;
                }
            }

            res = Math.max(res, temp);
        } else {
            for (int i = 1; i <= 3; i++) {
                bombNumbers.add(i);
                chooseNumbers(cnt + 1);
                bombNumbers.remove(bombNumbers.size() - 1);
            }
        }
    }

    private static void mark(Position position, Integer number) {
        score[position.x][position.y] += 1;
        if (number == 1) {
            for (int diff = -2; diff <= 2; diff++) {
                if (diff == 0) continue;
                int nx = position.x + diff;

                if (nx < 0 || nx >= N) continue;
                score[nx][position.y] += 1;
            }
        } else if (number == 2) {
            for (int i = 0; i < 4; i++) {
                int nx = position.x + dx[i];
                int ny = position.y + dy[i];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                score[nx][ny] += 1;
            }
        } else if (number == 3) {
            for (int i = 0; i < 4; i++) {
                int nx = position.x + ddx[i];
                int ny = position.y + ddy[i];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                score[nx][ny] += 1;
            }
        }
    }

    static class Position {
        public int x;
        public int y;

        public Position(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
