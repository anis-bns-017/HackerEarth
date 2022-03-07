/*

 ALLAH IS ALMIGHTY              ******BISMILLAHIR RAHMANIR RAHIM.******              ALLAH IS ALMIGHTY
                                    ```````````````````````````````
                                        AUTHOR: ANISUR RAHAMAN
                                            BSMRSTU(SHIICT)
                                                ID:017


                            ............LET's START OUR JOURNEY.............

*/
#include <bits/stdc++.h>

#define I_O ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//~~~~~~~~~~~~ Sort Form Of Long~~~~~~~~~~~//
#define ll long long lls
#define lls int64_t
#define ld long double
#define db double
#define ull unsigned long long int

//~~~~~~~~~~~~~~Pair~~~~~~~~~~~~~~~~~~//
#define pii pair<lls,lls>
#define pll pair<ll,ll>
#define pdd pair<db,db>
#define psi pair<string,lls>
#define vi vector<lls>
#define vl vector<ll>
#define vd vector<db>
#define vs vector<string>
#define vb vector<bool>
#define vpi vector<pii>
#define vpl vector<pll>
#define vpd vector<pdd>
#define vpsi vector<psi>
#define vvi vector<vector<lls>>

//~~~~~~~~~~~~~~Vector~~~~~~~~~~~~~~~~~//
#define pb push_back
#define pf push_front
#define MP make_pair
#define in insert
#define ff first
#define ss second
#define al(v) v.begin(),v.end()
#define alr(v) v.rbegin(), v.rend()
#define srt(v) sort(al(v))
#define srtr(v) sort(al(v), greater<lls>());
#define len(x) ((ll)(x).length())
#define sz(x) ((ll)(x).size())
#define rev(v) reverse(al(v))
#define btcnt(n) __builtin_popcount(n)
#define acl(v, n) accumulate(al(v), n)
#define eb emplace_back
#define Lrt(s, c) rotate(s.begin(), s.begin() + c, s.end())
#define Rrt(s, c) rotate(s.begin(), s.begin() + s.size() - c, s.end())
#define lb(v, kk) lower_bound(al(v), kk) - v.begin()
#define ub(v, kk) upper_bound(al(v), kk) - v.begin()
#define tpu(str) transform(al(str), str.begin(), ::toupper)
#define tpl(str) transform(al(str), str.begin(), ::tolower)
#define cignr cin.ignore(numeric_limits<streamsize>::max(), '\n');
#define mxv(v) *max_element(al(v))
#define mnv(v) *min_element(al(v))

const int MOD = 1e9 + 7;
const long long INF = 2e18;
const int mxn = 2e9 + 9;
const int mxd = 2e5 + 5;
const int mxa = 2e6 + 5;

//~~~~~~~~~~~~~~~~~~Function~~~~~~~~~~~~~~~~~~~~//
 

//~~~~~~~~~~~~~~~Loops and Short~~~~~~~~~~~~~~~~//

#define PI acos(-1)
#define Cn continue
#define Br break
#define off return 0
#define N '\n'
#define WT(somthing) auto az = something; cout << az << N;
#define WTS(something) cout << something << N;
#define fopen freopen("input.txt", "r", stdin);
#define rep(i, n) for(lls i = 0; (lls)i < n; i++)
#define repn(i, a, b) for(lls i = (lls)(a); i < (lls)(b); i++)
#define repr(i, a, b) for(lls i = (lls)(a) - 1; i >= (lls)(b); i--)
#define test_case() lls T; T = 1; while(T--)

using namespace std;

// Stores the accessible directions
int dx[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[] = { 1, 1, 0, -1, -1, -1, 0, 1 };

// ===================================~~~~~~ SOLUTION STARTS HERE ~~~~~~=================================== //

//lls a, b, c, d, e, res = 0, ans = 0, prod = 1, n, m, cnt = 0, k, l, r, s, t, x, y, f, i, j, p;
#define mx 1000001

lls arr[mx];
pii tree[mx * 4];

void init(lls node, lls b, lls e)
{
   if (b == e) {
      if (arr[b] & 1) tree[node] = {1, 0};
      else tree[node] = {0, 1};
      return;
   }
   
   lls Left = node * 2;
   lls Right = node * 2 + 1;
   lls mid = (b + e) / 2;
   init(Left, b, mid);
   init(Right, mid + 1, e);
   tree[node].ff = tree[Left].ff + tree[Right].ff;
   tree[node].ss = tree[Left].ss + tree[Right].ss;
}


void update(lls node, lls b, lls e, lls i, lls newvalue)
{
   if (b == e) {
      if (arr[b] & 1) tree[node] = {0, 1};
      else tree[node] = {1, 0};

      arr[b] = newvalue;
      return;
   }

   lls Left = node * 2;
   lls Right = node * 2 + 1;
   lls mid = (b + e) / 2;
   if (i <= mid) update(Left, b, mid, i, newvalue);
   else update(Right, mid + 1, e, i, newvalue);

   tree[node].ff = tree[Left].ff + tree[Right].ff;
   tree[node].ss = tree[Left].ss + tree[Right].ss;
}

lls getEven(lls node, lls b, lls e, lls i, lls j)
{
   if (i > e || j < b)
      return 0;
   if (b >= i && e <= j)
      return tree[node].ss;
   lls Left = node * 2;
   lls Right = node * 2 + 1;
   lls mid = (b + e) / 2;
   lls p1 = getEven(Left, b, mid, i, j);
   lls p2 = getEven(Right, mid + 1, e, i, j);
   return p1 + p2;
}

lls getOdd(lls node, lls b, lls e, lls i, lls j)
{
   if (i > e || j < b)
      return 0;
   if (b >= i && e <= j)
      return tree[node].ff;
   lls Left = node * 2;
   lls Right = node * 2 + 1;
   lls mid = (b + e) / 2;
   lls p1 = getOdd(Left, b, mid, i, j);
   lls p2 = getOdd(Right, mid + 1, e, i, j);
   return p1 + p2;
}

void Run_Case() 
{
   lls n, k;
   cin >> n;
   for (lls i = 1; i <= n; i++) cin >> arr[i];
   init(1, 1, n);

   lls q, l, r, idx, x;
   cin >> k;
   for (int i = 0; i < k; i++) {
      cin >> q;
      if (q == 0) {
         cin >> idx >> x;
         if (arr[idx] % 2 == x % 2) continue;
         else update(1, 1, n, idx, x);
      } else if (q == 1) {
         cin >> l >> r;
         cout << getEven(1, 1, n, l, r) << N;
      } else {
         cin >> l >> r;
         cout << getOdd(1, 1, n, l, r) << N;
      }
   }
}

int main()
{
   I_O
   int c = 1;
   test_case()
   {
     Run_Case();
   }
   off;
}
