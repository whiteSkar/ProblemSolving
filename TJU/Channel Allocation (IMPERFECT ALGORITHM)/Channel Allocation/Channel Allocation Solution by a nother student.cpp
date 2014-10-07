#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

int n, m, ans, now;
char x;
string s;
int map[30][30];
int color[30];
bool flag;

bool is_valid(int now, int col)
{
    for (int i = 0; i < now; ++i)
        if (map[now][i] && color[i] == col)
            return false;
    return true;
}

void dfs(int now, int maxcolor)
{
    if (now > n) 
    {
        ans = maxcolor;
        flag = true;
        return;
    }

    for (int i = 0; i < maxcolor; ++i)
    {
        if (is_valid(now, i))
        {
            color[now] = i;
            dfs(now + 1, maxcolor);
        }
    }
}

int main()
{
    //freopen("c.in", "r", stdin);
    //freopen("c.out", "w", stdout);
    while (cin >> n){
        if (n == 0) break;
        memset(map, 0, sizeof(map));
        for (int i = 0; i < n; ++i)
        {
            cin >> s;
            for (int j = 2; j < s.length(); ++j){
                int v = s[j] - 'A';
                map[i][v] = map[v][i] = 1;
            }
        }
        ans = 50;
        flag = false;

        for (int maxcolor = 1; maxcolor < 27; ++maxcolor){
            memset(color, 0, sizeof(color));
            dfs(0, maxcolor);
            if (flag) break;
        }
        
        if (ans == 1) cout << "1 channel needed." << endl;
        if (ans > 1) cout << ans << " channels needed." << endl;


        /*for (int i = 0; i < n; ++i){
            for (int j =0; j < n; ++j) cout << map[i][j] << " ";
            cout << endl;
        }*/
    }

    return 0;

}

