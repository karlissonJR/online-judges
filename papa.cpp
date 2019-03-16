#include <bits/stdc++.h>
#define MAXN 1005
#define w first
#define r second
#define pii pair<int, int>

using namespace std;

bool compare(pii &a, pii &b) {
	return (a.r + a.w) <= (b.r + b.w);
}

int main() {

	int n;
	cin >> n;
	pii box[n];
	int tab[n+1];

	for(int i=0; i<n; ++i) {
		cin >> box[i].w >> box[i].r;
		box[i].r -= box[i].w;
	}

	tab[0] = 0;
	for(int i=1; i<=n; ++i)
		tab[i] = (1 << 30);

	sort(box, box+n, compare);

	int answer = 0;
	for(int i=0; i<n; ++i) {
		for(int j= answer + 1; j > 0; --j) {

			if(box[i].r >= tab[j - 1] && tab[j - 1] + box[i].w < tab[j]) {
				tab[j] = tab[j - 1] + box[i].w;

				if(j > answer)
					answer = j;
			}
		}
	}

	cout << answer << endl;

	return 0;
}