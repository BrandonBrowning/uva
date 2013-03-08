
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solution_add(vector<int> & solution, int item) {
	if (find(solution.begin(), solution.end(), item) == solution.end())
		solution.push_back(item);
}

void post_traverse(vector< vector<int> > & depends, int root, vector<int> & solution) {
	if (depends[root].size() == 0) {
		cerr << "\tpost traverse adding " << root << endl;
		solution_add(solution, root);
	} else {
		for (int i = 0; i < depends[root].size(); ++i) {
			cerr << "\tpost traverse recurse from " << root << " to " << depends[root][i] << endl;
			post_traverse(depends, depends[root][i], solution);
		}
		cerr << "\tpost traverse back to adding " << root << endl;
		solution_add(solution, root);
	}
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0)
			return 0;

		bool * is_root = new bool[n];
		for (int i = 0; i < n; ++i)
			is_root[i] = true;

		vector< vector<int> > depends(n);

		for (int i = 0; i < m; ++i) {
			int from, to;
			cin >> from >> to;
			--from; --to;

			is_root[to] = false;
			depends[from].push_back(to);
		}

		vector<int> roots;
		for (int i = 0; i < n; ++i)
			if (is_root[i]) {
				roots.push_back(i);
				cerr << "\troot " << i << endl;
		}

		vector<int> solution;
		for (int i = 0; i < roots.size(); ++i) {
			post_traverse(depends, roots[i], solution);
			cerr << "\tpost traversing " << roots[i] << endl;
		}

		// HAHAHAHAHAHAHAHAAA
		reverse(solution.begin(), solution.end());

		for (int i = 0; i < n; ++i)
			cout << (solution[i] + 1) << (i == n - 1 ? "" : " ");
		cout << endl;
	}

	return 0;
}