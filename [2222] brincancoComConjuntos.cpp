// https://www.urionlinejudge.com.br/judge/pt/problems/view/2222

#include <stdio.h>
#include <string.h>
#define MAX 10001
#define MAXN 61

int main()
{
	int n;
	int x,y, op,u,v;
	int grid[MAX][MAXN];

	scanf("%d", &n);

	for(int i=0; i<n; ++i){
		scanf("%d", &x);

		memset(grid, 0, sizeof grid);

		for(int j=1; j<=x; ++j) {
			scanf("%d", &grid[j][0]);

			for(int k=1; k<=grid[j][0]; ++k){
				scanf("%d", &u);
				grid[j][u] = 1;
			}
		}

		scanf("%d", &y);

		for(int j=0; j<y; ++j)
		{
			scanf("%d %d %d", &op, &u, &v);
			
			int counter = 0;

			if(op == 1){
				for(int k=1; k<MAXN; ++k){
					if(grid[u][k] && grid[v][k])
						++counter;
				}
			} else {
				for(int k=1; k<MAXN; ++k){
					if(grid[u][k] || grid[v][k])
						++counter;
				}
			}

			printf("%d\n", counter);
		}
	}
}
