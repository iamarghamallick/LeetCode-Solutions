class Bank {
    long[] accounts;
    int n;

    public Bank(long[] balance) {
        accounts = balance;
        n = balance.length;
    }
    
    public boolean transfer(int account1, int account2, long money) {
        if(!accountExist(account1 - 1) || !accountExist(account2 - 1))
            return false;
        if(accounts[account1 - 1] >= money) {
            accounts[account1 - 1] -= money;
            accounts[account2 - 1] += money;
            return true;
        }
        return false;
    }
    
    public boolean deposit(int account, long money) {
        if(!accountExist(account - 1))
            return false;
        accounts[account - 1] += money;
        return true;
    }
    
    public boolean withdraw(int account, long money) {
        if(!accountExist(account - 1))
            return false;
        if(accounts[account - 1] < money)
            return false;
        accounts[account - 1] -= money;
        return true;
    }

    private boolean accountExist(int account) {
        return 0 <= account && account < n;
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * Bank obj = new Bank(balance);
 * boolean param_1 = obj.transfer(account1,account2,money);
 * boolean param_2 = obj.deposit(account,money);
 * boolean param_3 = obj.withdraw(account,money);
 */