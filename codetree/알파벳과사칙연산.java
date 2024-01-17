package shine.codetree;

import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

public class 알파벳과사칙연산 {

    private static char[] chars;
    private static int res = -2147000000;
    private static Map<Character, Integer> MAP = new HashMap<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String str = br.readLine().trim();
        chars = str.toCharArray();

        go(0);

        bw.write(String.valueOf(res));
        bw.flush();
        bw.close();
        br.close();
    }

    private static void go(int index) {
        if (index >= chars.length) {
            for (char c : chars) {
                if(c >= 'a' && c <= 'f')
                    System.out.print(MAP.get(c));
                else
                    System.out.print(c);
            }
            System.out.println();

            Stack<Character> st = new Stack<>();

            int temp = MAP.get(chars[0]);
            for (int i = 1; i < chars.length; i++) {
                if (chars[i] >= 'a' && chars[i] <= 'f') {
                    int backNum = MAP.get(chars[i]);

                    char operator = st.pop();
                    if (operator == '+') {
                        temp += backNum;
                    } else if (operator == '-') {
                        temp -= backNum;
                    } else if (operator == '*') {
                        temp *= backNum;
                    } else if (operator == '/') {
                        temp /= backNum;
                    }
                } else {
                    st.push(chars[i]);
                }
            }
            res = Math.max(res, temp);
            return;
        }

        char c = chars[index];
        if (c >= 'a' && c <= 'f') {
            if(MAP.containsKey(c)) {
                go(index + 1);
            } else {
                for (int i = 1; i <= 4; i++) {
                    MAP.put(c, i);
                    go(index + 1);
                    MAP.remove(c);
                }
            }

        } else {
            go(index + 1);
        }
    }

}
