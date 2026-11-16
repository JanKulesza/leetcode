class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = gas.size();
        int startIdx = 0;
        int currTank = 0;
        int totalTank = 0;
        for(int i = 0; i < n; i++) {
            if(currTank < 0) {
                currTank = 0;
                startIdx = i;
            }
            currTank += gas[i] - cost[i];
            totalTank += gas[i] - cost[i];
        }
        
        return abs(totalTank - currTank) <= currTank ? startIdx : -1;
    }
};