
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	int id;
	int color; // 0=uncolored 1=color1 2=color2
	vector<int> children;
};

bool bfs(int root, vector<Node> & lookup, int nodes, vector<int> & visited, int color) {
	Node & me = lookup[root];
	
	if (me.color != 0 && me.color != color) {
		return false;
	} else {
		me.color = color;
	}

	if (find(visited.begin(), visited.end(), root) != visited.end()) {
		return true;
	}

	visited.push_back(root);

	vector<int> & children = me.children;
	for (int i = 0; i < children.size(); ++i) {
		bool succeed = bfs(children[i], lookup, nodes, visited, color == 1 ? 2 : 1);

		if (!succeed)
			return false;
	}

	return true;
}

int main() {
	while (true) {
		int nodes;
		cin >> nodes;

		if (nodes == 0)
			return 0;

		vector<Node> lookup;
		for (int i = 0; i < nodes; ++i) {
			Node n;
			n.id = i;
			n.color = 0;
			n.children = vector<int>();

			lookup.push_back(n);
		}

		int edges;
		cin >> edges;

		for (int i = 0; i < edges; ++i) {
			int fromid, toid;
			cin >> fromid >> toid;

			lookup[fromid].children.push_back(toid);
			lookup[toid].children.push_back(fromid);
		}

		vector<int> visited;
		bool colorable = bfs(0, lookup, nodes, visited, 1);

		cout << (colorable ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
	}

	return 0;
}
