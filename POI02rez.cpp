#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;

const int N = int(2e5) + 5;
const int inf = (int)1e9 + 7;

int n;
int d[N];
vector < int > to[N];

int main(){
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int l, r;
    scanf("%d %d", &l, &r);
    to[l].push_back(r);
  }
  for(int i = 0; i < N; ++i){
    if(i){
      d[i] = max(d[i - 1], d[i]);
    }
    for(int j : to[i]){
      d[j] = max(d[j], d[i] + (j - i));
    }
  }
  printf("%d\n", d[N - 1]);
  return 0;
}
