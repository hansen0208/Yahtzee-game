#include "yahtzee.h"
#include <iostream>
using namespace std;

int main(){
    YahtzeeGame game;
    cout << "=== Yahtzee Game ===\n"

    int difficulty;
    cout << "Select difficulty (1-Easy, 2-Medium, 3-Hard)(By inputing the integer):";
    cin >> difficulty;

    if (difficulty >= 1 && difficulty <= 3){
        game.setDifficulty(static_cast<YahtzeeGame::Difficulty>(difficulty - 1));
    }else{
        cout << "Invalid choice. Using Medium difficulty.\n"
    }

    game.startGame();
    return 0;
}