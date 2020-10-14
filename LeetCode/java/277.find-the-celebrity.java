public class Solution extends Relation {
    /**
     * @param n a party with n people
     * @return the celebrity's label or -1
     */
    public int findCelebrity(int n) {
        // Write your code here
        
        // 找到一个候选人，他之后的所有人他都不认识。
        int candidate = 0;
        for(int i = 1;i < n; ++i){
            if(knows(candidate,i)){
                candidate = i;
            }
        }
        
        // 验证是否他之前的人他都不认识。
        for(int i = 0;i < candidate;++i){
            if(knows(candidate, i)){
                return -1;
            }
        }
        
        // 验证是否所有人都认识他。
        for(int i = 0; i< n;++i){
            if(candidate != i && !knows(i,candidate)){
                return -1;
            }
        }
        return candidate;
    }
}