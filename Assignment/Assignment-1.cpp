#include <iostream>
#include <vector>
#include <queue>
#include <string>

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
        if (id >= 1 && id <= players) {
            playerNames[id] = name;
        }
    }

    void addMatch(int winner, int loser) {
        if (winner <= players && loser <= players) {
            matches[winner].push_back(loser);
        }
    }

    void showRanking(int topPlayer) {
        vector<bool> visited(players + 1, false);
        
        queue<pair<int, int>> q; 

        visited[topPlayer] = true;
        q.push({topPlayer, -1});

        cout << "\n=========================================\n";
        cout << "       GAME RANKING & MATCH SUMMARY      \n";
        cout << "=========================================\n";

        int rankTier = 1;

        while (!q.empty()) {
            int levelSize = q.size();
            cout << "\n--- Tier " << rankTier << " Players ---\n";

            for (int i = 0; i < levelSize; ++i) {
                auto [current, winner] = q.front();
                q.pop();

                if (winner == -1) {
                    cout << "[Champion] " << playerNames[current] << " You won the game!" << endl;
                } else {
                    cout << "Player: " << playerNames[current] 
                         << " | (Lost to: " << playerNames[winner] << ")" << endl;
                }

                for (int loser : matches[current]) {
                    if (!visited[loser]) {
                        visited[loser] = true;
                        q.push({loser, current});
                    }
                }
            }
            rankTier++;
        }
        cout << "=========================================\n";
    }
};

int main() {
    GameRanking game(6);

    // Registering Player Names
    game.addPlayer(1, "Shadow");
    game.addPlayer(2, "Blaze");
    game.addPlayer(3, "Ghost");
    game.addPlayer(4, "Hunter");
    game.addPlayer(5, "Viper");
    game.addPlayer(6, "Reaper");

    // Match Results (Winner, Loser)
    game.addMatch(1, 2); 
    game.addMatch(1, 3); 

    game.addMatch(2, 4);
    game.addMatch(2, 5); 

    game.addMatch(3, 6); 

    game.showRanking(1);

    return 0;
}
