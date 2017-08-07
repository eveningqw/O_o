# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef unsigned long long ull;

const int N = (int)2e5 + 7;
const int inf = (int)1e9 + 7;

int n, t, m, now;
int cost[N], col[N], u[N], wow[N];
int costc[N], inc[N];
vector < int > g[N], rg[N], ord, all;


void dfs(int v){
  u[v] = 1;
  for(int i : g[v]){
    if(!u[i]){
      dfs(i);
    }
  }
  ord.push_back(v);
}

void dfs2(int v){
  col[v] = now;
  for(int i : rg[v]){
    if(!col[i]){
      dfs2(i);
    }
  }
}

int main(){
  scanf("%d %d", &n, &t);
  for(int i = 1; i <= n; ++i){
    cost[i] = inf;
    costc[i] = inf;
  }
  for(int i = 1; i <= t; ++i){
    int x, y;
    scanf("%d %d", &x, &y);
    cost[x] = min(cost[x], y);
  }
  scanf("%d", &m);
  for(int i = 1; i <= m; ++i){
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].push_back(y);
    rg[y].push_back(x);
  }
  for(int i = 1; i <= n; ++i){
    if(!u[i]){
      dfs(i);
    }
  }
  fill(u + 1, u + 1 + n, 0);
  reverse(ord.begin(), ord.end());
  for(int i : ord){
    if(!col[i]){
      ++now;
      dfs2(i);
    }
  }
  for(int i = 1; i <= n; ++i){
    costc[col[i]] = min(costc[col[i]], cost[i]);
  }
  for(int i = 1; i <= n; ++i){
    for(int j : g[i]){
      if(col[i] != col[j]){
        inc[col[j]]++;
      }
    }
  }
  int sum = 0, bad = 0;
  for(int i = 1; i <= now; ++i){
    if(inc[i] == 0){
      if(costc[i] == inf){
        bad = i;
      }
      sum += costc[i];
    }
  }
  if(bad){
    for(int i = 1; i <= n; ++i){
      if(col[i] == bad){
        printf("NIE\n%d\n", i);
        return 0;
      }
    }
  }
  printf("TAK\n%d", sum);
  return 0;
}
