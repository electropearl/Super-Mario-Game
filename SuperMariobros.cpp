#include <iostream>
#include <string>
using namespace std;

struct player {
    
    string playerName;  //Who is the player
    int lives;
    int coins;
    
    int level;  //Where is the player
    int x_position;
    int y_position;
    
    bool special; //Is the player special - if so what items
    bool big;
    string special_items[6];
    
} ;

// Initilize the struct variables
void initilaize_variables (player& character, string myName){
    character.playerName = myName;
    character.lives = 3;
    character.coins = 0;
    
    character.level = 0;
    character.x_position = 0;
    character.y_position = 0;
    
    character.special = false;
    character.big = false;
    character.special_items[0] = "Hammer";
    character.special_items[1] = "Red Mushroom";
    character.special_items[2] = "Green Mushroom";
    character.special_items[3] = "Cape";
    character.special_items[4] = "Star";
    character.special_items[5] = "Green Spotted Orange 1-Up Mushroom";

}

// increment coins
void incrementCoins(player& character){
    int coins;
    cout << "Enter Number of Coins Collected: ";
    cin >> coins;
    cout << endl;
    cout << endl;
    character.coins = coins;
}

// gains characters lives
void gainLife (player& character){
    int life = 1;
    int enemies;

    cout << "How many enemies have you killed in a row: ";
    cin >> enemies;
    cout << endl;

    if(character.coins >= 100 && enemies > 7 ){
        character.lives = character.lives + (life * 2);
        cout << "2 lives gained..." << endl;
        cout << endl;
    }
    else if(character.coins > 100 || enemies > 7 ){
        character.lives = character.lives + life;
        cout << "1 life gained..." << endl;
        cout << endl;
    }
    else
    {
        cout << "No lives gained..." << endl;
        cout << endl;
    }
}

//lose life 
void loseLives(player& character){
    int life = 1;
    int hit, pit, time;
    cout << "Time level was finshed: ";
    cin >> time;
    cout << endl;
    cout << "Did you fall in a bottomless pit (type '1' for true, '0' for false): ";
    cin >> pit;
    cout << endl;
    cout << "Number of times hit by an enemy: ";
    cin >> hit;
    cout << endl;
    cout << endl;

    if (time == 0 && pit == 1){
        character.lives = character.lives - life - life - hit;
        cout << "You lost life!" << endl;
        cout << endl;
    }
    else if (time == 0 || pit == 1){
        character.lives = character.lives - life - hit;
        cout << "You lost life!" << endl;
        cout << endl;
    }
    else {
        cout << "No life lost!" << endl;
        cout << endl;
    }

}

//update life
bool updateLife (player& character){
    int restart;
    if(character.lives == 0){
        cout << endl;
        cout << "-----------GAME OVER-----------!" << endl;
        cout << endl;
       return true;
    }
    else{
        return false;
    }
    
}

// Restart the character
void restart (player& character){
    character.lives = 3;
    character.coins = 0;
    character.special = false;
    character.big = false;
}

//Print character
void printCharacter(player& character) {

    // Print State
    cout << "\t Name: \t\t\t" << character.playerName << "\n";
    cout << "\t Lives: \t\t" << character.lives << "\n";
    cout << "\t Coins: \t\t" << character.coins << "\n";
    
    // Print Position
    cout << "\t Level: \t\t" << character.level << "\n";
    cout << "\t X Position: \t\t" << character.x_position << "\n";
    cout << "\t Y Position: \t\t" << character.y_position << "\n";
    
    // Print Special Items
    cout << "\t Character big?: \t" << character.special << "\n";
    cout << "\t Character special?: \t" << character.big << "\n";
    for (int i = 0; i < 6; i++)
     cout << "\t Special_Item[" << i << "]: \t" << character.special_items[i] << "\n";
}

int main () {
    player Mario;
    player Luigi;
    int replay;
    initilaize_variables(Mario, "Mario");
    initilaize_variables(Luigi, "Luigi");

    incrementCoins(Mario);
    gainLife(Mario);
    loseLives(Mario);
    updateLife(Mario);
    
    printCharacter(Mario);
    cout << endl;
    if (updateLife(Mario) == true){
        cout << "Would you like to restart(Enter '1' for yes or '0' for no)? ";
        cin >> replay;
        cout << endl;
        cout << endl;
        if(replay == 1){
            restart(Mario);
            printCharacter(Mario);
        }
        else{
            cout << "Thanks for playing!"<< endl;
            cout << endl;
        }
    }

    
    return 0;
}
