class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int uniquePos = 0;
for (int j = 0; j < mat.size(); j++)
{
    int count = 0, toCheck;
	for (int i = 0; i < mat[j].size(); i++)
		if (mat[j][i] == 1) {
			count++;
			toCheck = i;
		}

	if (count == 1) {
		for (int i = 0; i < mat.size(); i++)
			if (mat[i][toCheck] == 1)
				count++;

		if (count == 2)
			uniquePos++;
	}
}
return uniquePos;
    }
};