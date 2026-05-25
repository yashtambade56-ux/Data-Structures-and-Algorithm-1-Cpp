#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class GameRanking {

private:

    int players;

    vector<vector<int>> matches;

    vector<string> playerNames;

public:

    GameRanking(int p) {

        players = p;

        matches.resize(p + 1);

        playerNames.resize(p + 1);
    }

    // Add Player Name
    void addPlayer(int id, string name) {

        playerNames[id] = name;
    }

    // Winner beats loser
    void addMatch(int winner, int loser) {

        matches[winner].push_back(loser);
    }

    // BFS Ranking
    void showRanking(int topPlayer) {

        vector<bool> visited(players + 1, false);

        queue<int> q;

        visited[topPlayer] = true;

        q.push(topPlayer);

        int rank = 1;

        cout << "\n===== Game Ranking System =====\n";

        while (!q.empty()) {

            int current = q.front();
            q.pop();

            cout << "Rank "
                 << rank
                 << " -> "
                 << playerNames[current]
                 << endl;

            rank++;

            // Visit defeated players
            for (int next : matches[current]) {

                if (!visited[next]) {

                    visited[next] = true;

                    q.push(next);
                }
            }
        }
    }
};

int main() {

    GameRanking game(6);

    // Player Names
    game.addPlayer(1, "Shadow");
    game.addPlayer(2, "Blaze");
    game.addPlayer(3, "Ghost");
    game.addPlayer(4, "Hunter");
    game.addPlayer(5, "Viper");
    game.addPlayer(6, "Reaper");

    // Match Results
    game.addMatch(1, 2);
    game.addMatch(1, 3);

    game.addMatch(2, 4);
    game.addMatch(2, 5);

    game.addMatch(3, 6);

    // Show Ranking
    game.showRanking(1);

    return 0;
}
