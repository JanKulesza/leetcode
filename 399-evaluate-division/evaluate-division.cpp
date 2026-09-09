class Solution {
public:
	double pathValue(unordered_map<string, vector<pair<string, double>>>& edges, string a, string b) {
		if (a == b)
			return 1.0;
		vector<pair<string, double>> stack = { {a,1.0} }; // vertex, curCost
		unordered_set<string> visited;

		while (stack.size() > 0) {
			auto [cur, cost] = stack.back();
			stack.pop_back();
			if (visited.contains(cur)) continue;
			visited.insert(cur);

			for (auto [nextV, costToV] : edges[cur]) {
				if (nextV == b)
					return cost * costToV;
				else if (!visited.contains(nextV))
					stack.emplace_back(nextV, cost * costToV);
			}
		}
		return -1.0;
	};
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		vector<double> res;
		unordered_map<string, vector<pair<string, double>>> edges;
		for (int i = 0; i < equations.size(); i++)
		{
			edges[equations[i][0]].emplace_back(equations[i][1], values[i]);
			edges[equations[i][1]].emplace_back(equations[i][0], 1.0 / values[i]);
		}
		for (const auto q: queries)
		{
			if (edges.contains(q[0]) && edges.contains(q[1]))
				res.push_back(pathValue(edges, q[0], q[1]));
			else res.push_back(-1.0);
		}
		return res;
	}
};