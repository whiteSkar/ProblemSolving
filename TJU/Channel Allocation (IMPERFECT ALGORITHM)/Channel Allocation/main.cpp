
#include <iostream>

using namespace std;

#define MAX_CAP 26
#define BEGIN_OF_LIST 2

struct repeater {
	int numOfAdjacent;
	int radio;
	char name;
	char adjacentList[MAX_CAP];
};

int main()
{
	int numOfRepeaters = 0;
	int numOfChannels = 1;
	char *line = new char[MAX_CAP];
	struct repeater *repeater_pt;
	struct repeater *repeaterList[MAX_CAP];
	int listOfChannels[10000];
	int numOfTimes = 0;

	for ( int j = 0; j < MAX_CAP; j++ )
	{
		line[j] = '0';
	}

	cin >> numOfRepeaters;

	while ( numOfRepeaters > 0 )
	{
		numOfTimes++;

		for ( int i = 0; i < numOfRepeaters; i++ )
		{
			cin >> line;
			
			repeater_pt = new struct repeater();
			repeater_pt->radio = 1;
			repeater_pt->name = line[0];
			repeater_pt->numOfAdjacent = 0;
			
			int j = BEGIN_OF_LIST;
			int k = 0;
			while ( line[j] != '\0' )
			{
				repeater_pt->adjacentList[k] = line[j];
				repeater_pt->numOfAdjacent++;
				k++;
				j++;
			}

			for ( int j = 0; j < MAX_CAP; j++ )
			{
				line[j] = '0';
			}

			repeaterList[i] = repeater_pt;
		}


		for ( int i = 0; i < numOfRepeaters; i++ )
		{
			for ( int j = i+1; j < numOfRepeaters; j++ )
			{
				if ( repeaterList[i]->radio == repeaterList[j]->radio )
				{
					for ( int k = 0; k < repeaterList[i]->numOfAdjacent; k++ )
					{
						if ( repeaterList[i]->adjacentList[k] == repeaterList[j]->name )
						{
							repeaterList[j]->radio++;
						}
					}
				}
			}
		}

		int max_radio = 1;
		for ( int i = 0; i < numOfRepeaters; i++ )
		{
			if ( repeaterList[i]->radio > max_radio )
			{
				max_radio = repeaterList[i]->radio;
			}
		}
		numOfChannels = max_radio;
		listOfChannels[numOfTimes-1] = numOfChannels;
		numOfChannels = 1;
	
		cin >> numOfRepeaters;
	}

	for ( int i = 0; i < numOfTimes; i++ )
	{
		if ( listOfChannels[i] == 1 )
		{
			cout << listOfChannels[i] << " channel needed." << endl;
		}
		else
		{
			cout << listOfChannels[i] << " channels needed." << endl;
		}
	}

	return 0;
}


/*
#include<iostream>
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


        //for (int i = 0; i < n; ++i){
       //     for (int j =0; j < n; ++j) cout << map[i][j] << " ";
        //    cout << endl;
       // }
    }

    return 0;

}
*/