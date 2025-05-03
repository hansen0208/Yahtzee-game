#include "Dice.h"
#include <iostream>
#include <chrono>
#include <algorithm>

// new class dice to give random dice state
Dice::Dice() : dice(5, 1), hold(5, false) {

    random_device rd;
    gen.seed(rd());

}

//roll the unholded dice to generate new dice state
void Dice::roll() {
    uniform_int_distribution<> dist(1, 6);
    for (int i = 0; i < 5; i++) {
        if (!hold[i]){
            dice[i] = dist(gen);
        }
    }
}

// take user input from main and it toggle the hold state of the index-th dice
void Dice::toggleHold(int index){
    if (index >= 0 && index < 5){
        hold[index] = !hold[index];

    }




}


//to show the dice is held in user interface
bool Dice::isHeld(int index) const{
    
    if (index >= 0 && index < 5){
        return hold[index];
    }else{
        return false;
    }
}


///To access the current state of dice
const vector<int> &Dice::getDice() const {
    return dice;

}



//after reroll, the state of holding should be reset. this function does that.
void Dice::resetHolds() {
    fill(hold.begin(), hold.end(), false);

}



// showcase the dice state
void Dice::printDice() const{
    cout << "Current dice: ";
    for (int i = 0; i < 5; i++){
        cout << dice[i];
        if (hold[i]) {
            cout << "(H)";

        }
    
        if (i < 4) cout << " ";
    }
    
    cout << endl;
}