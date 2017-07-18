# include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef unsigned long long ull;

const int N = int(5e5) + 5;
const int inf = (int)1e9 + 9;

int n, m, k;
int a[1005], b[1005];
int d[1005][1005][12];

void add(int &x, int y){
  x += y;
  if(x > inf){
    x -= inf;
  }
  if(x < 0){
    x += inf;
  }
}

int main(){
  freopen("team.in", "r", stdin);
  freopen("team.out", "w", stdout);
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
  }
  for(int i = 1; i <= m; ++i){
    scanf("%d", b + i);
  }
  d[1][1][0] = 1;
  for(int i = 1; i <= n + 1; ++i){
    for(int j = 1; j <= m + 1; ++j){
      for(int s = 0; s <= k; ++s){
        if(j + 1 <= m + 1){
          // skip the jth cow
          add(d[i][j + 1][s], d[i][j][s]);
        }
        if(i + 1 <= n + 1){
          // skip the ith cow
          add(d[i + 1][j][s], d[i][j][s]);
        }
        if(i + 1 <= n + 1 && j + 1 <= m + 1){
          // d[i][j][s] will get overadded to d[i + 1][j + 1][s] so remove it
          add(d[i + 1][j + 1][s], -d[i][j][s]);
        }
        if(i <= n && j <= m && a[i] > b[j]){
          // take the ith and jth cow
          add(d[i + 1][j + 1][s + 1], d[i][j][s]);
        }
      }
    }
  }
  printf("%d\n", d[n + 1][m + 1][k]);
  return 0;
}
