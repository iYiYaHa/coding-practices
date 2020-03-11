#include<iostream>

using namespace std;

class Solution{
public:
    double Power(double base, int exponent){
        if( (base > -1e-10 && base < 1e-10) && exponent < 0)
            throw invalid_argument("Zero with a negative exponent.");

        unsigned int absExp = static_cast<unsigned int>(exponent);
        if(exponent < 0)
            absExp = static_cast<unsigned int>(-exponent);
        double res = PowerUnsignedRecursive(base, absExp);
        if(exponent < 0)
            return 1 / res;
        return res;
    }
private:
    double PowerUnsigned(double base, unsigned int exponent){
        double ans = 1;
        while(exponent){
            if(exponent&1){
                ans*=base;
            }
            base *= base;
            exponent >>= 1;
        }
        return ans;
    }
    double PowerUnsignedRecursive(double base, unsigned int exponent){
        if(exponent == 0)
            return 1;
        else if(exponent & 1)
            return base * PowerUnsignedRecursive(base, exponent-1);
        else{
            double halfPower = PowerUnsignedRecursive(base, exponent>>1);
            return halfPower * halfPower;
        }
    }
};

int main(){
    Solution s;
    cout<<s.Power(3.14,2)<<endl;
    cout<<s.Power(-3,2)<<endl;
    cout<<s.Power(3,-2)<<endl;
    cout<<s.Power(5,0)<<endl;
    cout<<s.Power(0,1)<<endl;
    cout<<s.Power(0,0)<<endl;
    cout<<s.Power(0,-3)<<endl;
}