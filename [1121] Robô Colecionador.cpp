#include <stdio.h>
#include <stdlib.h>

#define MAX 101
int n,m,o;
char grid[MAX][MAX];

typedef struct sense{
	char c;
	int i,j;
	struct sense* esq;
	struct sense* dir;
} sense;

bool isValide(int u, int v){
	return u>=0 && v>=0 && u<n && v<m && grid[u][v] != '#' ? true : false;
}

int main()
{
	sense N, S, L, O, *ptr = (sense*) malloc(sizeof(sense));
	N.c = 'N'; N.esq = &O; N.dir = &L; N.i=-1, N.j=0;
	S.c = 'S'; S.esq = &L; S.dir = &O; S.i=1, S.j=0;
	L.c = 'L'; L.esq = &N; L.dir = &S; L.i=0, L.j=1;
	O.c = 'O'; O.esq = &S; O.dir = &N; O.i=0, O.j=-1;

	char c, str[50010];

	while(scanf("%d %d %d", &n,&m,&o) && n+m+o)
	{
		getchar();
		int u,v,ans = 0;

		for(int i=0; i<n; ++i) //entrada do grid
			scanf("%s", grid[i]);

		for(int i=0; i<n; ++i){ //pega a posição inicial do robô
			for(int j=0; j<m; ++j){
				if(grid[i][j] >= 'L' && grid[i][j] <= 'S')
				{
					c = grid[i][j];
					u = i, v = j;
					break;
				}
			}
		}

		if(c == 'N') ptr = &N;
		else if(c == 'S') ptr = &S;
		else if(c == 'L') ptr = &L;
		else ptr = &O;

		scanf("%s", str);

		for(int i=0; str[i] != '\0'; ++i)
		{
			if(str[i] == 'D')
				ptr = ptr->dir;
			else if (str[i] == 'E')
				ptr = ptr->esq;
			else {
				int x = u+ptr->i;
				int y = v+ptr->j;

				if(isValide(x,y))
					u = x, v = y;
			}

			if(grid[u][v] == '*'){
				grid[u][v] = '.';
				++ans;
			}
		}

		printf("%d\n", ans);
		ptr = NULL;
	}
	return 0;
}