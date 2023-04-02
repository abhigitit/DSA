/*
Maximum Frequency Stack
group elements with same frequency

*/
class FreqStack {
public:
    vector<vector<int>> group_of_stacks;
    map<int,int> freq;
    int max_cnt = 0;
    FreqStack() {
        group_of_stacks.resize(100000);
    }
    
    void push(int val) {
        freq[val]++;
        max_cnt = max(max_cnt,freq[val]);
        group_of_stacks[freq[val]].push_back(val);
    }
    
    int pop() {
        int size = group_of_stacks[max_cnt].size();
        int res = group_of_stacks[max_cnt][size-1];
        group_of_stacks[max_cnt].pop_back();
        if(size==1)
            max_cnt -= 1;
        freq[res]--;
        return res;
    }
};
