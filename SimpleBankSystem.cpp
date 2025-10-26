//2043. Simple Bank System C++ Code
class Bank {
public:

vector<long long> balance;
int n;
    Bank(vector<long long>& balance) : balance(balance){
        n = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1<=n && account2<=n && balance[account1-1]>=money){
            balance[account1-1]-=money;
            balance[account2-1]+=money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account<=n){
            balance[account-1]+=money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(account<=n && balance[account-1]>=money){
            balance[account-1]-=money;
            return true;
        }
        return false;
    }
};
