import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        int ans = 0;
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        for (int i = 0; i < n; ++i) {
            int[] tmp = new int[3];
            int ele = 0;
            for (int j = 0; j < 3; ++j) {
                ele += Integer.parseInt(sc.next());
            }
            ans += (ele >= 2 ? 1 : 0);
        }
        System.out.println(ans);
    }
}