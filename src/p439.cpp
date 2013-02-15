
#include <climits>
#include <iostream>

using namespace std;

int pair_to_idx(int x, int y) {
	return (y * 8) + x;
}

int safe_move_add(int dist[64][64], int fromx, int fromy, int tox, int toy) {
	if (tox >= 0 && tox < 8 && toy >= 0 && toy < 8)
		dist[pair_to_idx(fromx, fromy)][pair_to_idx(tox, toy)] = 1;
}

int main() {
	int dist[64][64];
	for (int from = 0; from < 64; ++from)
		for (int to = 0; to < 64; ++to)
			dist[from][to] = INT_MAX / 2;

	for (int cellx = 0; cellx < 8; ++cellx) {
		for (int celly = 0; celly < 8; ++celly) {
			int cell = pair_to_idx(cellx, celly);
			
			dist[cell][cell] = 0;
		}
	}

	// for each from cell
	for (int fromx = 0; fromx < 8; ++fromx) {
		for (int fromy = 0; fromy < 8; ++fromy) {
			// add edge for each possible knight move
			safe_move_add(dist, fromx, fromy, fromx + 1, fromy + 2);
			safe_move_add(dist, fromx, fromy, fromx - 1, fromy + 2);
			safe_move_add(dist, fromx, fromy, fromx + 1, fromy - 2);
			safe_move_add(dist, fromx, fromy, fromx - 1, fromy - 2);
			safe_move_add(dist, fromx, fromy, fromx + 2, fromy + 1);
			safe_move_add(dist, fromx, fromy, fromx - 2, fromy + 1);
			safe_move_add(dist, fromx, fromy, fromx + 2, fromy - 1);
			safe_move_add(dist, fromx, fromy, fromx - 2, fromy - 1);
		}
	}
	
	// floyd's
	for (int k = 0; k < 64; ++k) {
		for (int i = 0; i < 64; ++i) {
			for (int j = 0; j < 64; ++j) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	
	string from, to;
	while (cin >> from >> to) {
		int fromidx = pair_to_idx(from[0] - 'a', from[1] - '1');
		int toidx = pair_to_idx(to[0] - 'a', to[1] - '1');
		
		cout << "To get from " << from << " to " << to << " takes " << 
			dist[fromidx][toidx] << " knight moves."  << endl;
	}

	return 0;
}
