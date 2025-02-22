import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        for (int i = 0; i < n; ++i) {
            String word = sc.next();
            String result = tryAbbreviate(word);
            System.out.println(result);
        }
        sc.close();
    }

    private static String tryAbbreviate(String word) {
        if (word == null || word.length() < 10) {
            return word;
        }
        int length = word.length();
        return String.format("%c%d%c", word.charAt(0), length - 2, word.charAt(length - 1));
    }
}