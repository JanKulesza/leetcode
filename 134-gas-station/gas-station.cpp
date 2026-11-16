class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startIdx = 0;
        int tank = 0;
        for(int i = 0; i < gas.size(); i++) {
            if(tank < 0) {
                tank = 0;
                startIdx = i;
            }
            tank += gas[i] - cost[i];
        }
        
        for(int i = 0; i <= startIdx; i++) {
            if(tank < 0)
                return -1;
            tank += gas[i] - cost[i];
        }
        return startIdx;
    }
};