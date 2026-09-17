class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = 0;
        for (int i = 0; i < piles.size(); i++)
        	r = max(piles[i], r);
        if (piles.size() == h)
        	return r;
        
        int l = 0;
        r--;
        while (l < r)
        {
        	int k = (l + r) / 2;
        	int copyH = h;
        	for (const auto& p : piles)
        	{
        		copyH -= p / (k + 1);
        		if (p % (k + 1) != 0)
        			copyH--;
        	}
        	if (copyH >= 0)
        		r = k;
        	else
        		l = k + 1;
        }
        return l + 1;
    }
};