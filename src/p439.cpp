
#include <algorithm>
#include <iostream>

#define A_LARGE_NUMBER 9139123
#define MAX_DEPTH 7

using namespace std;

int manlyMod(int x) {
	return x;
}

void wtf(int best[8][8], int x, int y, int depth) {
	if (depth >= MAX_DEPTH)
		return;
		
	if (x < 0 || y < 0 || x > 7 || y > 7)
		return;
		
	best[x][y] = min(best[x][y], depth);
	
	wtf(best, manlyMod(x + 1), manlyMod(y + 2), depth + 1);
	wtf(best, manlyMod(x + 1), manlyMod(y - 2), depth + 1);
	wtf(best, manlyMod(x + 2), manlyMod(y + 1), depth + 1);
	wtf(best, manlyMod(x + 2), manlyMod(y - 1), depth + 1);
	wtf(best, manlyMod(x - 1), manlyMod(y + 2), depth + 1);
	wtf(best, manlyMod(x - 1), manlyMod(y - 2), depth + 1);
	wtf(best, manlyMod(x - 2), manlyMod(y + 1), depth + 1);
	wtf(best, manlyMod(x - 2), manlyMod(y - 1), depth + 1);
}

// NOTE: FUCK THIS PROBLEM
int main() {
	int best[8][8];
	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			best[i][j] = A_LARGE_NUMBER;
			
	wtf(best, 0, 0, 0);
	
	for (int row = 7; row >= 0; --row)
		for (int col = 0; col < 8; ++col)
			cout << best[row][col] << (col == 7 ? "\n" : " ");
			
	string from, to;	
	while (cin >> from >> to) {
		int fromx = from[0] - 'a';
		int fromy = from[1] - '0';
		int tox = to[0] - 'a';
		int toy = to[1] - '0';
		/*
		bool toIsBottomLeft = true;
		if (fromx <= tox && fromy <= toy)
			toIsBottomLeft = false;
			
		int bottomLeftx, bottomLefty, topRightx, topRighty;
		if (toIsBottomLeft) {
			bottomLeftx = tox;
			bottomLefty = toy;
			topRightx = fromx;
			topRighty = fromy;
		} else {
			bottomLeftx = fromx;
			bottomLefty = fromy;
			topRightx = tox;
			topRighty = toy;
		}
		
		int dx = topRightx - bottomLeftx;
		int dy = topRighty - bottomLefty;
		*/
		
		int dx = fromx - tox;
		int dy = fromy - toy;
		
		if (dx < 0)
			dx *= -1;
			
		if (dy < 0)
			dy *= -1;
		
		cout << "To get from " << from << " to " << to << " takes " << best[dx][dy] << " knight moves." << endl;
	}
	
	return 0;
}
