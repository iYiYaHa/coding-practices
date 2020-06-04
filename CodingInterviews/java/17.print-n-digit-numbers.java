class Solution {
    public int[] printNumbers(int n) {
        char[] num = new char[n];
        LinkedList<Integer> res = new LinkedList<>();

        resetNum(num);
        while(nextNum(num, n)){
            appendNum(num, res);
        }

        int[] arrRes = new int[res.size()];
        int ind = 0;
        for(Integer cur:res){
            arrRes[ind++] = cur;
        }

        return arrRes;
    }

    private void resetNum(char[] numStr){
        for(int i = 0;i < numStr.length;++i){
            numStr[i] = '0';
        }
    }

    private void appendNum(char[] numStr, LinkedList<Integer> res){
        int num = 0;
        for(int i = 0;i < numStr.length;++i){
            num = num * 10 + (numStr[i]-'0');
        }
        res.add(num);
    }

    private boolean nextNum(char[] numStr, int n){
        boolean isOverflow = false;
        int carry = 1;
        for(int i = numStr.length-1;i>=0;--i){
            int sum = carry+numStr[i]-'0';
            numStr[i] = (char)(sum % 10+'0');
            carry = sum>=10?1:0;
            if(carry == 0)break;
        }
        return carry == 0;
    }
}