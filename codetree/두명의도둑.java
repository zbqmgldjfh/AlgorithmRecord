package shine.codetree;

import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.StringTokenizer;

public class 두명의도둑 {

    private static int N, M, C;
    private static int endIdx;
    private static int res;
    private static int[][] MAP;
    private static boolean[][] visited;
    private static List<Integer> idxs = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine().trim());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        MAP = new int[N][N];
        visited = new boolean[N][N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine().trim());
            for (int j = 0; j < N; j++) {
                MAP[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        endIdx = (N * N) - 1;
        go(0);

        bw.write(String.valueOf(res));
        bw.flush();
        bw.close();
        br.close();
    }

    public static void go(int idx) {
        if (idxs.size() >= 2) {
            int position1 = idxs.get(0);
            int position2 = idxs.get(1);

            int x = position1 / N;
            int y = position1 % N;

            List<Integer> values1 = chooseValues(x, y);

            x = position2 / N;
            y = position2 % N;
            List<Integer> values2 = chooseValues(x, y);

            int tempRes = 0;
            for (int value : values1) {
                tempRes += value * value;
            }
            for (int value : values2) {
                tempRes += value * value;
            }

            res = Math.max(res, tempRes);

            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    visited[i][j] = false;
                }
            }
            return;
        }

        if (idx > endIdx) return;

        idxs.add(idx);
        go(idx + 1);
        idxs.remove(idxs.size() - 1);

        go(idx + 1);
    }

    private static List<Integer> chooseValues(int x, int y) {
        if(visited[x][y]) return new LinkedList<>();

        for (int dy = 0; dy < M; dy++) {
            if (y + dy >= N) break;
            visited[x][y + dy] = true;
        }

        int ans = 0;
        List<Integer> returns = new LinkedList<>();
        for(int i = 0; i < (1 << M); i++) {
            List<Integer> dys = new LinkedList<>();
            for(int j = 0; j < M; j++) {
                if((i & (1 << j)) > 0) {
                    dys.add(j);
                }
            }

            int temp = 0;
            List<Integer> values = new LinkedList<>();
            for(int dy : dys) {
                if (y + dy >= N) break;
                if (temp + MAP[x][y + dy] > C) break;

                temp += MAP[x][y + dy];
                values.add(MAP[x][y + dy]);
            }

            if(temp > ans) {
                ans = temp;
                returns = new ArrayList<>(values);
            }
        }

        return returns;
    }
}
