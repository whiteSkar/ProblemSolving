#include <math.h>
#include <string.h>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

typedef pair<string, bool> candidate;
typedef pair<int, int> candidateId;

void tokenizeString(const string &str, vector<string>& tokens, const string &delimiters);
bool candidateIdCompare(const candidateId &c1, const candidateId &c2);
bool isStringEmptyOrWhitespace(string str);

const int CANDIDATE_MAX_COUNT = 20;
const int BALLOT_MAX_COUNT = 1000;

candidate candidates[CANDIDATE_MAX_COUNT];
vector<int> ballots[BALLOT_MAX_COUNT];

bool isCandidateAlive(int candidateId)
{
	return candidates[candidateId].second;
};

void popUntilAliveCandidate(vector<int> &candidateIds)
{
	while (!candidateIds.empty())
	{
		int candidateId = candidateIds.front();
		if (isCandidateAlive(candidateId))
			break;
		candidateIds.erase(candidateIds.begin());
	}
};

void initializeAliveCandidateBallots(candidateId *curBallots, int aliveCandidateCount)
{
	int id = 0;
	for (int i = 0; i < aliveCandidateCount; ++i)
	{
		while (!isCandidateAlive(id))
		{
			id++;
		}

		curBallots[i] = candidateId(id++, 0);
	}
};

candidateId *getCandidateId(int id, candidateId *curBallots, int aliveCandidateCount)
{
	for (int i = 0; i < aliveCandidateCount; ++i)
		if (curBallots[i].first == id)
			return curBallots + i;
};

int main()
{
	//ifstream inputFile("input.txt");	// change to cin
	//ofstream outputFile("output.txt");

	string input;
	getline(cin, input);
	int numTest = atoi(input.c_str());

	getline(cin, input);	// first blank line

	for (int k = 1; k <= numTest; k++)
	{
		memset(candidates, 0, sizeof(candidate) * CANDIDATE_MAX_COUNT);
		for (int i = 0; i < BALLOT_MAX_COUNT; ++i)
			ballots[i].clear();

		while (getline(cin, input))
		{
			if (!isStringEmptyOrWhitespace(input))
				break;
		}

		int candidateCount = atoi(input.c_str());
		
		for (int i = 0; i < candidateCount; ++i)
		{
			getline(cin, input);
			candidates[i] = candidate(input, true);
		}

		int ballotCount = 0;
		while (getline(cin, input))
		{
			if (isStringEmptyOrWhitespace(input))
				break;

			vector<string> ids;
			tokenizeString(input, ids, " ");

			for (auto it = ids.begin(); it != ids.end(); it++)
				ballots[ballotCount].push_back(atoi((*it).c_str()) - 1);

			ballotCount++;
		}

		vector<int> winnerIds;
		int aliveCandidateCount = candidateCount;

		if (ballotCount == 0)
		{
			for (int i = 0; i < aliveCandidateCount; ++i)
				winnerIds.push_back(i);
		}

		while (ballotCount > 0)
		{
			candidateId *curBallots = new candidateId[aliveCandidateCount];
			initializeAliveCandidateBallots(curBallots, aliveCandidateCount);

			for (int i = 0; i < ballotCount; ++i)
			{
				getCandidateId(ballots[i].front(), curBallots, aliveCandidateCount)->second++;
			}

			sort(curBallots, curBallots + aliveCandidateCount, candidateIdCompare);

			float voteRatio = (float)curBallots[aliveCandidateCount-1].second / ballotCount;
			if (voteRatio > 50)
			{
				winnerIds.push_back(curBallots[aliveCandidateCount-1].first);
				break;
			}
			else
			{
				bool isVoteRatioAllTheSame = true;
				for (int i = 1; i < aliveCandidateCount; ++i)
				{
					if (curBallots[0].second != curBallots[i].second)
					{
						isVoteRatioAllTheSame = false;
						break;
					}
				}

				if (isVoteRatioAllTheSame)
				{
					for (int i = 0; i < aliveCandidateCount; ++i)
					{
						winnerIds.push_back(curBallots[i].first);
					}
					break;
				}
				else
				{
					int numVotes = curBallots[0].second;
					int newlyDeadCandidateCount = 0;
					for (int i = 0; i < aliveCandidateCount; ++i)
					{
						if (curBallots[i].second == numVotes)
						{
							int deadId = curBallots[i].first;
							candidates[deadId].second = false;
							newlyDeadCandidateCount++;
						}
						else
						{
							break;
						}
					}

					aliveCandidateCount -= newlyDeadCandidateCount;
					for (int i = 0; i < ballotCount; ++i)
					{
						popUntilAliveCandidate(ballots[i]);
					}
				}
			}
		}

		for (auto it = winnerIds.begin(); it != winnerIds.end(); ++it)
		{
			cout << candidates[(*it)].first << endl;
		}

		if (k < numTest)
			cout << endl;
	}

	//inputFile.close();
	//outputFile.close();

	return 0;
}

void tokenizeString(const string &str, vector<string>& tokens, const string &delimiters = " ")
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos = str.find_first_of(delimiters, lastPos);

    while (pos != string::npos || lastPos != string::npos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

bool candidateIdCompare(const candidateId &c1, const candidateId &c2)
{
	return c1.second < c2.second;
}

bool isStringEmptyOrWhitespace(string str)
{
	if (str.empty() || str.find_first_not_of(' ') == std::string::npos)
		return true;
	return false;
}