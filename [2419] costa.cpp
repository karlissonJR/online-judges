// https://www.urionlinejudge.com.br/judge/pt/problems/view/2419
// http://olimpiada.ic.unicamp.br/pratique/programacao/nivel1/2012f2p1_costa

#include <stdio.h>
#define MAX 1001

int x,y;
char grid[MAX][MAX];
int id[][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

bool isValide(int u, int v){
	return (u>=0 && v>=0 && u<x && v<y);
}

int isCoast(int u, int v)
{
	for(int i=0; i<4; ++i) {
		int x = u + id[i][0];
		int y = v + id[i][1];

		if(!isValide(x,y) || grid[x][y] == '.')
			return 1;
	}

	return 0;
}

int main()
{
	int answer = 0;
	scanf("%d %d", &x, &y);

	for(int i=0; i<x; ++i)
		scanf("%s", grid[i]);

	for(int i=0; i<x; ++i){
		for(int j=0; j<y; ++j){
			if(grid[i][j] == '#')
				answer += isCoast(i,j);
		}
	}

	printf("%d\n", answer);
}
