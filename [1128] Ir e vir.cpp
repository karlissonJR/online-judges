#include <bits/stdc++.h>
#define MAX 2002
using namespace std;
 
int n,m,u,v,p;
 
vector<int> Gn[MAX];
vector<int> Gt[MAX];
vector<int>::iterator it;
bool vis[MAX];
 
void reset() {
    for(int i=1; i<=n; ++i)
        vis[i]=false;
}
 
int dfs(vector<int> *g)
{
    int cont = 1;
    queue<int> pilha;
    pilha.push(1);
    vis[1]=true;
    while(!pilha.empty()){
    int u = pilha.front();
    pilha.pop();
    
        for(it=g[u].begin(); it!=g[u].end(); ++it)
        {
             if(!vis[*it]){
                 vis[*it] = true;
                 pilha.push(*it);
                 ++cont;
             }
        }
    }
    return cont;
}
 
int main()
{
    while(scanf("%d %d", &n, &m) && (n+m))
    {
        for(int i=0; i<m; ++i)
        {
            scanf("%d %d %d", &u, &v, &p);
            if(p-1) {
                Gn[u].push_back(v);
                Gn[v].push_back(u);
                Gt[v].push_back(u);
                Gt[u].push_back(v);
            } else {
                Gn[u].push_back(v);
                Gt[v].push_back(u);
            }
        }
 
        reset();
        int temp = dfs(Gn);
        reset();
        int cont = dfs(Gt);
 
        printf("%d\n", (temp == n && cont == n) );
 
        for(int i=1; i<=n; ++i){
            Gn[i].clear();
            Gt[i].clear();
        }
 
    }
    return 0;
}
