class Solution {
private:
    int minTransfersDFS(vector<int>& debt, int start) {
        while (start < debt.size() && debt[start] == 0) {
            ++start;
        }
        if (start + 1 >= debt.size()) {
            return 0;
        }
        int minTrans = INT_MAX;
        for (int i = start + 1; i < debt.size(); ++i) {
            if (debt[start] * debt[i] < 0) { // one owes money and the other is owed money
                debt[i] += debt[start];
                minTrans = min(minTrans, 1 + minTransfersDFS(debt, start + 1));
                debt[i] -= debt[start]; // backtrack
            }
        }
        return minTrans;
    }
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> balance;
        for (auto& transaction : transactions) {
            balance[transaction[0]] -= transaction[2];
            balance[transaction[1]] += transaction[2];
        }
        vector<int> debt;
        for (auto& bal : balance) {
            if (bal.second != 0) {
                debt.push_back(bal.second);
            }
        }
        return minTransfersDFS(debt, 0);
    }
};
