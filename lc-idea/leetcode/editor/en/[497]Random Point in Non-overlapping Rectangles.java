//You are given an array of non-overlapping axis-aligned rectangles rects where 
//rects[i] = [ai, bi, xi, yi] indicates that (ai, bi) is the bottom-left corner 
//point of the iᵗʰ rectangle and (xi, yi) is the top-right corner point of the iᵗʰ 
//rectangle. Design an algorithm to pick a random integer point inside the space 
//covered by one of the given rectangles. A point on the perimeter of a rectangle 
//is included in the space covered by the rectangle. 
//
// Any integer point inside the space covered by one of the given rectangles 
//should be equally likely to be returned. 
//
// Note that an integer point is a point that has integer coordinates. 
//
// Implement the Solution class: 
//
// 
// Solution(int[][] rects) Initializes the object with the given rectangles 
//rects. 
// int[] pick() Returns a random integer point [u, v] inside the space covered 
//by one of the given rectangles. 
// 
//
// 
// Example 1: 
//
// 
//Input
//["Solution", "pick", "pick", "pick", "pick", "pick"]
//[[[[-2, -2, 1, 1], [2, 2, 4, 6]]], [], [], [], [], []]
//Output
//[null, [1, -2], [1, -1], [-1, -2], [-2, -2], [0, 0]]
//
//Explanation
//Solution solution = new Solution([[-2, -2, 1, 1], [2, 2, 4, 6]]);
//solution.pick(); // return [1, -2]
//solution.pick(); // return [1, -1]
//solution.pick(); // return [-1, -2]
//solution.pick(); // return [-2, -2]
//solution.pick(); // return [0, 0]
// 
//
// 
// Constraints: 
//
// 
// 1 <= rects.length <= 100 
// rects[i].length == 4 
// -10⁹ <= ai < xi <= 10⁹ 
// -10⁹ <= bi < yi <= 10⁹ 
// xi - ai <= 2000 
// yi - bi <= 2000 
// All the rectangles do not overlap. 
// At most 10⁴ calls will be made to pick. 
// 
// Related Topics Math Binary Search Reservoir Sampling Prefix Sum Ordered Set 
//Randomized 👍 359 👎 564


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    private int[][] rects;
    private int[] sections;
    private int totalPoints;
    private Random rand;

    public Solution(int[][] rects) {
        this.rects = rects;

        this.sections = new int[rects.length];
        this.totalPoints = 0;
        for (int i = 0; i < rects.length; ++i) {
            int rectPoints = (rects[i][3] - rects[i][1] + 1) * (rects[i][2] - rects[i][0] + 1);
            totalPoints += rectPoints;
            sections[i] = totalPoints;
        }

        this.rand = new Random();
    }
    
    public int[] pick() {
        int indOfRect = ranadomlyPickRect();
        int[] point = pickPointFromRect(indOfRect);
        return point;
    }

    private int ranadomlyPickRect(){
        int randomSeed = rand.nextInt(totalPoints);
        int left = 0;
        int right = sections.length-1;
        while(left <= right){
            int mid = left + (right - left / 2);
            if(randomSeed <= sections[mid] && (mid <= 0 || randomSeed >= sections[mid-1])){
                return mid;
            }
            else if(randomSeed > sections[mid]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        throw new IllegalArgumentException("Invalid rectangles.");
    }

    private int[] pickPointFromRect(int indOfRect) {
        int[] rect = rects[indOfRect];
        int rowLen = rect[2] - rect[0] + 1;
        int colLen = rect[3] - rect[1] + 1;
        return new int[]{rect[0] + rand.nextInt(rowLen), rect[1] + rand.nextInt(colLen)};
    }
}

class Solution {
    private int[][] rects;
    private List<int[]> sections;
    private int totalPoints;
    private Random rand;

    public Solution(int[][] rects) {
        this.rects = rects;

        this.sections = new ArrayList<>();
        this.totalPoints = 0;
        for (int i = 0; i < rects.length; ++i) {
            int bottomLeftX = rects[i][0];
            int bottomLeftY = rects[i][1];
            int topRightX = rects[i][2];
            int topRightY = rects[i][3];
            int rectPoints = (topRightY - bottomLeftY + 1) * (topRightX - bottomLeftX + 1);
            sections.add(new int[]{totalPoints, totalPoints + rectPoints - 1});
            totalPoints += rectPoints;
        }

        this.rand = new Random();
    }

    public int[] pick() {
        int indOfRect = ranadomlyPickRect();
        int[] point = pickPointFromRect(indOfRect);
        return point;
    }

    private int ranadomlyPickRect(){
        int randomSeed = rand.nextInt(totalPoints);
        int left = 0;
        int right = sections.size()-1;
        while(left <= right){
            int mid = left + (right - left / 2);
            int[] section = sections.get(mid);
            if(randomSeed >= section[0] && randomSeed <= section[1]){
                return mid;
            }
            else if(randomSeed < section[0]){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
//        for(int i = 0; i < sections.size(); ++i){
//            if(randomSeed >= sections.get(i)[0] && randomSeed <= sections.get(i)[1]){
//                return i;
//            }
//        }
        throw new IllegalArgumentException("Invalid rectangles.");
    }

    private int[] pickPointFromRect(int indOfRect) {
        int[] rect = rects[indOfRect];
        int totalPointsInRect = (rect[3] - rect[1] + 1) * (rect[2] - rect[0] + 1);
        int randomSeed = rand.nextInt(totalPointsInRect);
        int offsetX = randomSeed / (rect[3] - rect[1] + 1);
        int offsetY = randomSeed % (rect[3] - rect[1] + 1);
        return new int[]{rect[0] + offsetX, rect[1] + offsetY};
    }
}
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * int[] param_1 = obj.pick();
 */
//leetcode submit region end(Prohibit modification and deletion)
