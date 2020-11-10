#include <iostream>
#include <vector>
using namespace std;

int goal;

struct player {
    string name;
    int score;

    void read() {
        cout << "Name: ";
        cin >> name;
        system("clear");

    }
    void  game() {
        srand(time(NULL));
        vector<int> rand_shagai(4, 0);
        // rand 4 too 
        for (int i = 0; i < 4; i++) {
            rand_shagai[rand() % 4]++;
        }
        // check mori
        if (rand_shagai[0] * rand_shagai[1] * rand_shagai[2] * rand_shagai[3] == 1)
            score += 4;
        else {
            score += rand_shagai[3];
        }
    }

};

int main () {
    int n;
    vector<player> player_list;

    cout << "Number of players: ";
    cin >> n;

    player_list.resize(n);
    for (int i = 0; i < n; i++) {
        player_list[i].read();
    }

    cout << "GOAL: "; 
    cin >> goal;
    int tmp = 0;
    while(goal > tmp){
        for (int i = 0; i < n; i++) {
            player_list[i].game();
            if (player_list[i].score == goal){
                cout << player_list[i].name << ' ' << player_list[i].score << endl;
                cout << "yalchlaa mal mine" << endl;
                tmp = goal;
                break;
            }
        }
    }

    return 0;
}