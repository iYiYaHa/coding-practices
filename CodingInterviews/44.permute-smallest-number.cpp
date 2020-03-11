#include<iostream>
#include<vector>
#include<string>
#include<numeric>

using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> numStrs;
        for(int num:numbers){numStrs.push_back(std::to_string(num));}
        sort(numStrs.begin(),numStrs.end(),[](string a, string b){return (a+b)<(b+a);});
        for(string i:numStrs) cout<<i<<endl;
        string res = accumulate(numStrs.begin(), numStrs.end(),string(),[](string a,string b){return a+b;});
        return res;
    }
};

int main(){
    Solution s;
    assert(s.PrintMinNumber({123,456,1,8,9}) == "112345689");
}