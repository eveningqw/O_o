# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef unsigned long long ull;

const int N = int(1e5) + 5;
const int inf = (int)1e9 + 7;

int n;
int s[N], u[N];
int cnt[N], mx;
ll ans;
vector < int > g[N], primes;

void calc_size(int v, int p){
  s[v] = 1;
  for(int i : g[v]){
    if(i == p || u[i]){
      continue;
    }
    calc_size(i, v);
    s[v] += s[i];
  }
}

int find_root(int v, int p, int tot){
  for(int i : g[v]){
    if(i == p || u[i]){
      continue;
    }
    if(s[i] > tot / 2){
      return find_root(i, v, tot);
    }
  }
  return v;
}

void add(int v, int p, int h, int val){
  cnt[h] += val;
  mx = max(mx, h);
  for(int i : g[v]){
    if(i == p || u[i]){
      continue;
    }
    add(i, v, h + 1, val);
  }
}

void calc(int v, int h, ll &e){
  for(int i : primes){
    if(i >= h){
      e += cnt[i - h];
    } else{
      break;
    }
  }
}

void calc(int v, int p, int h, ll &e){
  calc(v, h, e);
  for(int i : g[v]){
    if(i == p || u[i]){
      continue;
    }
    calc(i, v, h + 1, e);
  }
}

ll solve(int v){
  ll tot = 0;
  mx = 0;
  for(int i : g[v]){
    if(u[i]){
      continue;
    }
    add(i, v, 1, 1);
  }
  cnt[0]++;
  calc(1, 0, tot);
  for(int i : g[v]){
    if(u[i]){
      continue;
    }
    add(i, v, 1, -1);
    calc(i, v, 1, tot);
    add(i, v, 1, 1);
  }
  cnt[0]--;
  for(int i : g[v]){
    if(u[i]){
      continue;
    }
    add(i, v, 1, -1);
  }
  return tot;
}

void centroid(int v){
  calc_size(v, v);
  int root = find_root(v, v, s[v]);
  ans += solve(root);
  u[root] = 1;
  for(int i : g[root]){
    if(!u[i]){
      centroid(i);
    }
  }
}

int main(){
  scanf("%d", &n);
  for(int i = 1; i < n; ++i){
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  vector < int > pr(n + 1, 1);
  pr[0] = pr[1] = 0;
  for(int i = 2; i <= n; ++i){
    if(pr[i]){
      primes.push_back(i);
      for(int j = i + i; j <= n; j += i){
        pr[j] = 0;
      }
    }
  }
  reverse(primes.begin(), primes.end());
  centroid(1);
  printf("%.12f", (ans * 1.0) / (n * (n - 1.0)));
  return 0;
}
