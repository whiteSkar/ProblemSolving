#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

struct Player {
    string name;
    int shotPercentage;
    int height;
    int draftNum;
    int playTime;
};
typedef struct Player player;

bool sortPlayer(const player &player1, const player &player2)
{
    if (player1.shotPercentage == player2.shotPercentage)
        return player1.height > player2.height;

    return player1.shotPercentage > player2.shotPercentage;
}

bool sortPlayerByName(const player *player1, const player *player2)
{
    return player1->name < player2->name;
}

bool sortPlayerByWhoToLeaveFirst(const player *player1, const player *player2)
{
    if (player1->playTime == player2->playTime)
        return player1->draftNum > player2->draftNum;

    return player1->playTime > player2->playTime;
}

bool sortPlayerByWhoToJoinFirst(const player *player1, const player *player2)
{
    if (player1->playTime == player2->playTime)
        return player1->draftNum < player2->draftNum;

    return player1->playTime < player2->playTime;
}

int main()
{
    int numTests = 0;
    ifstream inputFile ("basketball_game.txt");
    ofstream outputFile;
    outputFile.open("output.txt");

    inputFile >> numTests;
    for (int curTest = 0; curTest < numTests; ++curTest)
    {
        int numTotalPlayers;
        int minutes;
        int numActivePlayersPerTeam;

        inputFile >> numTotalPlayers;
        inputFile >> minutes;
        inputFile >> numActivePlayersPerTeam;

        int numPlayersPerTeam = numTotalPlayers / 2;

        vector<player> players;
        for (int i = 0; i < numTotalPlayers; ++i)
        {
            player newPlayer;
            inputFile >> newPlayer.name;
            inputFile >> newPlayer.shotPercentage;
            inputFile >> newPlayer.height;
            newPlayer.playTime = 0;

            players.push_back(newPlayer);
        }

        sort(players.begin(), players.end(), sortPlayer);
        for (unsigned int i = 0; i < players.size(); ++i)
            players[i].draftNum = i + 1;

        vector<player> team1;
        vector<player> team2;
        for (vector<player>::iterator it = players.begin(); it != players.end(); ++it)
        {
            if (it->draftNum % 2 == 0)
                team2.push_back(*it);
            else
                team1.push_back(*it);
        }

        int numTeam1Players = team1.size();
        int numTeam2Players = team2.size();

        vector<player*> team1ActivePlayers;
        vector<player*> team2ActivePlayers;
        for (int i = 0; i < numActivePlayersPerTeam; ++i)
        {
            team1ActivePlayers.push_back(&team1[i]);
            team2ActivePlayers.push_back(&team2[i]);
        }
        
        // functionize to reduce duplicate code
        if (numActivePlayersPerTeam < numTeam1Players)
        {
            vector<player*> team1BenchPlayers;
            for (int i = numActivePlayersPerTeam; i < numTeam1Players; ++i)
            {
                team1BenchPlayers.push_back(&team1[i]);
            }

            for (int curMin = 0; curMin < minutes; ++curMin)
            {
                for (int i = 0; i < numActivePlayersPerTeam; ++i)
                {
                    team1ActivePlayers[i]->playTime++;
                }

                // using heap may be more elegant solution
                sort(team1ActivePlayers.begin(), team1ActivePlayers.end(), sortPlayerByWhoToLeaveFirst);

                player* team1PlayerToLeave = team1ActivePlayers.front();
                team1ActivePlayers.erase(team1ActivePlayers.begin());

                sort(team1BenchPlayers.begin(), team1BenchPlayers.end(), sortPlayerByWhoToJoinFirst);

                player* team1PlayerToJoin = team1BenchPlayers.front();
                team1BenchPlayers.erase(team1BenchPlayers.begin());

                team1ActivePlayers.push_back(team1PlayerToJoin);
                team1BenchPlayers.push_back(team1PlayerToLeave);
            }
        }

        if (numActivePlayersPerTeam < numTeam2Players)
        {
            vector<player*> team2BenchPlayers;
            for (int i = numActivePlayersPerTeam; i < numTeam2Players; ++i)
            {
                team2BenchPlayers.push_back(&team2[i]);
            }

            for (int curMin = 0; curMin < minutes; ++curMin)
            {
                for (int i = 0; i < numActivePlayersPerTeam; ++i)
                {
                    team2ActivePlayers[i]->playTime++;
                }

                sort(team2ActivePlayers.begin(), team2ActivePlayers.end(), sortPlayerByWhoToLeaveFirst);

                player* team2PlayerToLeave = team2ActivePlayers.front();
                team2ActivePlayers.erase(team2ActivePlayers.begin());

                sort(team2BenchPlayers.begin(), team2BenchPlayers.end(), sortPlayerByWhoToJoinFirst);

                player* team2PlayerToJoin = team2BenchPlayers.front();
                team2BenchPlayers.erase(team2BenchPlayers.begin());

                team2ActivePlayers.push_back(team2PlayerToJoin);
                team2BenchPlayers.push_back(team2PlayerToLeave);
            }
        }

        vector<player*> activePlayers;
        for (int i = 0; i < numActivePlayersPerTeam; ++i)
        {
            activePlayers.push_back(team1ActivePlayers[i]);
            activePlayers.push_back(team2ActivePlayers[i]);
        }
        sort(activePlayers.begin(), activePlayers.end(), sortPlayerByName);

        outputFile << "Case #" << curTest + 1 << ":";
        for (unsigned int i = 0; i < activePlayers.size(); ++i)
            outputFile << " " << activePlayers[i]->name;
        outputFile << endl;
    }

    outputFile.close();
    return 0;
}