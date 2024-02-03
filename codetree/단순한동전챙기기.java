package shine.codetree;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class 단순한동전챙기기 {

    private static int n;
    private static int res = Integer.MAX_VALUE;
    private static char[][] MAP;
    private static int startX = 0;
    private static int startY = 0;
    private static int endX = 0;
    private static int endY = 0;
    private static List<Pair> numberPosition = new ArrayList<>();
    private static LinkedList<Pair> arr = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        n = Integer.parseInt(br.readLine().trim());
        MAP = new char[n][n];

        for (int i = 0; i < n; i++) {
            char[] chars = br.readLine().toCharArray();
            for (int j = 0; j < n; j++) {
                MAP[i][j] = chars[j];

                if (MAP[i][j] == 'S') {
                    startX = i;
                    startY = j;
                } else if (MAP[i][j] == 'E') {
                    endX = i;
                    endY = j;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (Character.isDigit(MAP[i][j])) {
                    numberPosition.add(new Pair(i, j, MAP[i][j] - '0'));
                }
            }
        }

        Collections.sort(numberPosition);

        findPath(0, 0);

        if (res == Integer.MAX_VALUE) {
            bw.write("-1");
        } else {
            bw.write(String.valueOf(res));
        }
        bw.flush();
        bw.close();
        br.close();
    }

    private static void findPath(int idx, int cnt) {
        if (cnt == 3) {
            res = Math.min(res, calc());
            return;
        }
        if (idx == numberPosition.size() || cnt > 3) {
            return;
        }

        arr.add(numberPosition.get(idx));
        findPath(idx + 1, cnt + 1);
        arr.removeLast();

        findPath(idx + 1, cnt);
    }

    public static int calc() {
        int numMoves = dist(startX, startY, arr.get(0).x, arr.get(0).y);

        for (int i = 0; i < 2; i++) {
            numMoves += dist(arr.get(i).x, arr.get(i).y, arr.get(i + 1).x, arr.get(i + 1).y);
        }
        numMoves += dist(arr.get(2).x, arr.get(2).y, endX, endY);

        return numMoves;
    }

    public static int dist(int startX, int startY, int endX, int endY) {
        return Math.abs(startX - endX) + Math.abs(startY - endY);
    }

    static class Pair implements Comparable<Pair> {
        int x;
        int y;
        int value;

        public Pair(int x, int y, int value) {
            this.x = x;
            this.y = y;
            this.value = value;
        }

        @Override
        public int compareTo(Pair o) {
            return this.value - o.value;
        }
    }
}


