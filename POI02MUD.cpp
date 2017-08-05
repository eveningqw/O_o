# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef unsigned long long ull;

const int N = (int)1e5 + 7;
const int inf = (int)1e9 + 7;

int l, m;
int cnt[N], sz;
ll ans[N], sub[N];
pii id[N];
vector < pii > g[N];

void dfs(int v, int p){
  sub[v] = cnt[v];
  for(pii i : g[v]){
    if(i.first == p){
      continue;
    }
    dfs(i.first, v);
    ans[1] += sub[i.first] * i.second;
    sub[v] += sub[i.first];
  }
}

void calc(int v, int p){
  for(pii i : g[v]){
    if(i.first == p){
      continue;
    }
    ans[i.first] = ans[v] + (sub[1] - sub[i.first]) * i.second - sub[i.first] * i.second;
    calc(i.first, v);
  }
}

int main(){
  scanf("%d %d", &l, &m);
  cnt[++sz] = m;
  for(int i = 1; i <= l; ++i){
    int f;
    scanf("%d", &f);
    int prv = 1;
    for(int j = 1; j <= f; ++j){
      int x, y;
      scanf("%d %d", &x, &y);
      g[sz + 1].push_back(make_pair(prv, x));
      g[prv].push_back(make_pair(sz + 1, x));
      id[++sz] = make_pair(i, j);
      cnt[sz] = y;
      prv = sz;
    }
  }
  dfs(1, 1);
  calc(1, 1);
  int mn = min_element(ans + 1, ans + 1 + sz) - ans;
  printf("%lld\n", ans[mn]);
  printf("%d %d\n", id[mn].first, id[mn].second);
  return 0;
}
