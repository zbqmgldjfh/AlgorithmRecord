package shine.codetree;

import java.util.*;
import java.io.*;

public class 겹치지않게선분고르기 {

    private static int N;
    private static int res = 0;
    private static List<Pair> arr;
    private static List<Integer> idxs = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine().trim());
        arr = new ArrayList<>(N);

        StringTokenizer st;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine().trim());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            arr.add(i, new Pair(start, end));
        }

        go(0);

        bw.write(String.valueOf(res));
        bw.flush();
        bw.close();
        br.close();
    }

    public static void show() {
        for(int idx : idxs) {
            System.out.print(idx + " ");
        }
        System.out.println();
    }

    public static void go(int index) {
        if (index >= N) {
            if(idxs.size() == 0) return;

            Integer index1 = idxs.get(0);
            if(index1 >= N) return;

            List<Pair> pairs = new ArrayList<>();
            for(int idx : idxs) {
                pairs.add(arr.get(idx));
            }
            Collections.sort(pairs);

            int temp = 1;
            int bend = pairs.get(0).end;
            int bstart = pairs.get(0).start;

            for (int i = 1; i < idxs.size(); i++) {
                if (pairs.get(i).start > bend && pairs.get(i).start > bstart) {
                    temp += 1;
                    bend = pairs.get(i).end;
                    bstart = pairs.get(i).start;
                }
            }

            res = Math.max(res, temp);
            return;
        }

        idxs.add(index);
        go(index + 1);

        idxs.remove(idxs.size() - 1);
        go(index + 1);
    }

    public static class Pair implements Comparable<Pair> {
        public int start;
        public int end;

        public Pair(int x, int y) {
            this.start = x;
            this.end = y;
        }

        @Override
        public int compareTo(Pair o) {
            return this.start - o.start;
        }
    }
}
