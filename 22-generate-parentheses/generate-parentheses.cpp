class Solution {
public:
    void gen(vector<string>& pars, int n, string par = "", int open = 0) {
        if(n == 0 && open == 0) {
            pars.push_back(par);
            return;
        }
        if(n > 0)
            gen(pars, n - 1, par + '(', open + 1);
        if(open > 0)
            gen(pars, n, par + ')', open - 1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> pars;
        gen(pars, n);
        return pars;
    }
};