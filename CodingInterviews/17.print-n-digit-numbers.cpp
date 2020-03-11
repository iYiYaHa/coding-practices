#include<iostream>
#include<string>

using namespace std;

class SolutionA{
public:
    void printToMaxOfDigits(int n){
        if(n <= 0)
            throw invalid_argument("N must be a non-negative number.");
        string s(n, '0');
        while(incrementNumber(s)){
            printNumber(s);
        }
    }
private:
    bool incrementNumber(string &s){
        int carry = 1;
        for(int i = s.size()-1; i>=0; --i){
            int sum = carry + s[i] - '0';
            if(sum >= 10){
                if(i==0){// Overflow
                    return false;
                }else{
                    sum -= 10;
                    carry = 1;
                    s[i] = sum + '0';
                }

            }else{
                s[i] = sum + '0';
                carry = 0;
            }
        }
        return true;
    }

    void printNumber(const string &s){
        bool isBeginningZero = true;
        for(int i = 0;i < s.size();++i){
            if(isBeginningZero && s[i] != '0'){
                isBeginningZero = false;
            }
            if(!isBeginningZero)
                cout<<s[i];
        }
        if(isBeginningZero)
            cout<<'0';
        cout<<endl;
    }
};

class SolutionB{
public:
    void printToMaxOfDigits(int n){
        if(n <= 0)
            throw invalid_argument("N must be a non-negative number.");
        string s(n, '0');
        
        for(int i = 0;i < 10;++i){
            s[0] = '0' + i; 
            printNumberRecursively(s, 0);
        }
    }
private:

    void printNumberRecursively(string &s, int index){
        if(index == s.size() - 1){
            printNumber(s);
        }else{
            for(int i = 0;i < 10;++i){
                s[index + 1] = '0' + i;
                printNumberRecursively(s, index + 1);
            }
        }

    }

    void printNumber(const string &s){
        bool isBeginningZero = true;
        for(int i = 0;i < s.size();++i){
            if(isBeginningZero && s[i] != '0'){
                isBeginningZero = false;
            }
            if(!isBeginningZero)
                cout<<s[i];
        }
        if(isBeginningZero)
            cout<<'0';
        cout<<endl;
    }
};

int main(){
    SolutionB s;
    
    for(int i = 1;i<10;++i){
        s.printToMaxOfDigits(i);
        cin.get();
    }
    return 0;
}