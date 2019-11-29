// UVa 459 - Graph Connectivity

#include <iostream>
#include <string.h>
#include <string>
using namespace std;

bool yet['Z' + 1];
bool lnk['Z' + 1]['Z' + 1];
char n;

void dfs(char c) {
	yet[c] = false;
	for (int j = 'A'; j <= n; j++)
		if (yet[j] && lnk[c][j])
			dfs(j);
}

int main() {
	int cases;
	cin >> cases;
	string line;
	getline(cin, line);
	getline(cin, line);
	for (; cases; cases--) {
		getline(cin, line);

		memset(lnk, false, sizeof(lnk));
		memset(yet, true, sizeof(yet));
		n = line[0];
		while (getline(cin, line) && line.size() > 0) {
			lnk[line[0]][line[1]] = true;
			lnk[line[1]][line[0]] = true;
		}
		int sol = 0;
		for (char c = 'A'; c <= n; c++) {
			if (yet[c]) {
				sol++;
				dfs(c);
			}
		}
		cout << sol << endl;
		if (cases > 1)
			cout << endl;
	}
	return 0;
}