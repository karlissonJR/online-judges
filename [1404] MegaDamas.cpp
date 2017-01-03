#include <stdio.h>
#include <string.h>
#define MAX 22

int res, n,m, grid[MAX][MAX], dis[MAX][MAX];
int id[][2] = {{-1,-1}, {-1,1}, {1,-1}, {1,1}};

bool valido(int i, int j) {
	return i>=0 && j>=0 && i<n && j<m ? true : false;
}

void dfs(int u, int v, int peso)
{
	for(int i=0; i<4; ++i)
	{
		int x = u+id[i][0], y = v+id[i][1];

		if(valido(x,y) && grid[x][y] == 2) {

			int tx = x + id[i][0];
			int ty = y + id[i][1];

			if(valido(tx, ty) && !grid[tx][ty] && !dis[x][y]) {
				dis[x][y] = 1;	//marca a peça como capturada
				dfs(tx, ty, peso+1);
				if(res < peso+1) res = peso+1;
				dis[x][y] = 0; //coloca a peça capturada no tabuleiro (backtracking)
			}
		}
	}

}

int main()
{
	int v[110];
	char c;

	while(scanf("%d %d", &n, &m) && (n+m))
	{
		bool flag = true;
		int x, index = 0;

		memset(grid, 0, sizeof grid);

		while(true){
			scanf("%d%c",&x,&c);
			v[index++] = x;

			if(c == '\n')
				break;
		}
		int temp = 0;

		for(int i=0; i<n; ++i) {
			for(int j=0; j<m && temp < index; ++j) {
				if(i%2 && j<m-1)
					grid[i][++j] = v[temp++];
				else if(!(i%2))
					grid[i][j++] = v[temp++];
			}
		}

		int ans = 0;

		for(int i=0; i<n; ++i) {
			for(int j=0; j<m; ++j) {
				if(grid[i][j] == 1)
				{
					memset(dis, 0, sizeof dis);
					dis[i][j] = res = 0;
					grid[i][j] = 0;
					dfs(i,j, 0);
					grid[i][j] = 1;
					if(ans < res) ans = res;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
