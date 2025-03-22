class SolutionA {
    public double myPow(double x, int n) {
            if((x < 1e-9 && x > -1e-9) && n < 0)
                throw new IllegalArgumentException("Zero base with a negative exponent.");
            int absExp = Math.abs(n);
            double ans = powCore(x,absExp);
            if(n < 0)
                return 1/ans;
            return ans;
    }

    private double powCore(double base, int exp){
        if(exp == 0) 
            return 1;
        if(exp == 1)
            return base;
        double half = powCore(base, exp/2);
        if((exp & 1) != 0){
            return base * half * half;
        }else{
            return half * half;
        }
    }
}

class SolutionB {
    public double myPow(double x, int n) {
            if((x < 1e-9 && x > -1e-9) && n < 0)
                throw new IllegalArgumentException("Zero base with a negative exponent.");
            int absExp = Math.abs(n);
            double ans = powCore(x,absExp);
            if(n < 0)
                return 1/ans;
            return ans;
    }

    private double powCore(double base, int exp){
        double ans = 1;
        while(exp != 0){
            if((exp & 1) != 0){
                ans *= base;
            }
            base *= base;
            exp >>>= 1;
        }
        return ans;
    }
}