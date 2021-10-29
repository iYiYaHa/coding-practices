/**
 * Problem: print the direction of the line made by folding.
 * If you fold one paper from the right to the left and unfold,
 * there will be a line in the middle of the original paper whose direction is up.
 * Try to print the lines made by folding if a paper is folded n times.
 * <p>
 * A kink mark is the line made by folding.
 */

import java.util.Arrays;

public class FoldPaper {

    public static void printKinkMarks(int n) {
        if (n < 0) {
            throw new IllegalArgumentException("You can't fold a paper negative times.");
        }
        int[] lineDirects = new int[(int) Math.pow(2, n) - 1];
        findKinkMark(1, (int) Math.pow(2, n) - 1, DirectionEnum.UP, lineDirects);
        System.out.println(Arrays.toString(lineDirects));
    }

    private static void findKinkMark(int beg, int end, DirectionEnum paperSide, int[] lineDirects) {
        if (beg > end) {
            return;
        }
        int mid = (beg + end) / 2;
        findKinkMark(beg, mid - 1, DirectionEnum.UP, lineDirects);
        lineDirects[mid - 1] = paperSide.code;
        findKinkMark(mid + 1, end, DirectionEnum.DOWN, lineDirects);
    }

    private enum DirectionEnum {
        UP(1),
        DOWN(-1);
        int code;

        DirectionEnum(int code) {
            this.code = code;
        }
    }

    public static void main(String[] args) {
        printKinkMarks(Integer.valueOf(args[0]));
    }
}
