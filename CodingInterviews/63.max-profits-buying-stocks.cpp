#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=0)return 0;
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int price:prices){
            if(price<minPrice) minPrice = price;
            maxProfit = max(maxProfit,price-minPrice);
        }
        return maxProfit;
    }
};

int main(){
    Solution s;
    vector<int> prices = {};
    prices = {7,6,4,3,1};
    assert(s.maxProfit(prices) == 0);
    prices = {7,1,5,3,6,4};
    assert(s.maxProfit(prices) == 5);
    return 0;
}