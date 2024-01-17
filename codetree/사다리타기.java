package shine.codetree;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class 사다리타기 {

    private static int N;
    private static int M;
    private static List<Ladder> ladderList;
    private static List<Ladder> ladderStore;
    private static int[] res;
    private static int cnt = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine().trim());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        ladderList = new ArrayList<>(M);
        ladderStore = new ArrayList<>(M);

        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine().trim());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            ladderList.add(new Ladder(a, b));
        }
        Collections.sort(ladderList);

        res = new int[N + 1];
        for(int i = 1; i <= N; i++) {
            res[i] = determine(i, ladderList);
        }

        go(0);

        bw.write(String.valueOf(cnt));
        bw.flush();
        bw.close();
        br.close();
    }

    public static void go(int index) {
        if(index >= M) {
            int[] temp = new int[N + 1];

            for(int i = 1; i <= N; i++) {
                temp[i] = determine(i, ladderStore);
            }

            for(int i = 1; i <= N; i++) {
                if(temp[i] != res[i]) return;
            }

            cnt = Math.min(cnt, ladderStore.size());
            return;
        }

        ladderStore.add(ladderList.get(index));
        go(index + 1);
        ladderStore.remove(ladderStore.size() - 1);
        go(index + 1);
    }

    public static int determine(int startNumber, List<Ladder> ladders) {
        int num = startNumber;

        for(Ladder ladder : ladders) {
            if(ladder.start == num) {
                num++;
            } else if(ladder.end == num) {
                num--;
            }
        }
        return num;
    }

    public static class Ladder implements Comparable<Ladder> {

        public int start;
        public int end;
        public int height;

        public Ladder(int start, int height) {
            this.start = start;
            this.height = height;
            this.end = start + 1;
        }

        @Override
        public int compareTo(Ladder o) {
            return this.height - o.height;
        }
    }
}
