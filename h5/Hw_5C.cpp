/**~*~*~*
 PART C - Gas Station
 
 This is a simple guessing game between a computer and a player. First, the computer prompts the player to enter
 his/her name then it generates a random number between 10 and 30. The player has up to five tries to guess the 
 number. After each guess, the program displays messages such as “Congratulations Susan, you’ve guessed the 
 number in 2 tries!”, or “Sorry Susan, the random number was  28!” . Ask the player if s/he wants to play again 
 (Y or y for yes, anything else for no) “Susan, would you like to play again?”.  When the current player decides 
 to stop playing, ask if there is another player, and start all over again. This program also creates an output 
 file named players.txt that contains the players’ names and their game results. Write to the screen a welcome 
 message, explaining what is the purpose of the program, and an end of the program another message that includes 
 the name of the output file.
 
 NAME: Brian Le
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int guess, rand_num, tries, game_num = 0;
    string name;
    char play_again = 'Y';
    char another_player;
    ofstream outfile;

    outfile.open("players.txt");
    cout << "Welcome to my guessing game! You have 5 tries!\n";
    cout << "Please enter your name: ";
    getline(cin, name);
    outfile << name;
    
    while (play_again == 'Y' || play_again == 'y') {
        game_num++;
        tries = 1;
        srand(time(0));
        rand_num = rand() % 21 + 10;

        cout << "\nPlease guess a random number between 10 and 30: ";
        cin >> guess;
    
        while (guess > 30 || guess < 10) {
            tries++;
            cout << guess << " is out of range. Please enter a number in the range 10 to 30: ";
            cin >> guess;
        }

        while (guess != rand_num && tries < 5) {
             if (guess > rand_num) {
                tries++;
                cout << "Too large! Try again: ";
                cin >> guess;
            }
            else {
                tries++;
                cout << "Too small! Try again: ";
                cin >> guess;
            }
        }
        if (tries == 5) {
            outfile << endl << "Game " << game_num << ": " << rand_num << " - not guessed";
            cout << "Sorry, the number was " << rand_num << endl;
        }
        else {
        outfile << endl << "Game " << game_num << ": " << rand_num << " - guessed in " << tries << " tries";
        cout << "Congratulations " << name << ", you've guessed the number in " << tries << " tries!\n";
        }
        cout << name << ", would you like to play again? (Y/N): ";
        cin >> play_again;

        if (play_again == 'N' || play_again == 'n') {
            cout << "Is there another player? (Y/N): ";
            cin >> another_player;
            if (another_player == 'Y' || another_player == 'y') {
                tries = 1;
                play_again = 'Y';
                game_num = 0;
                cout << "Please enter your name: ";
                cin.ignore();
                getline(cin, name);
                outfile << endl << endl << name;
            }
        }
    }
    outfile.close();
    cout << "Please check the output file \"players.txt\"\n";
    return 0;
}
/**~*~*~*~*~*~*~*~*~*
Welcome to my guessing game! You have 5 tries!
Please enter your name: Brian Le

Please guess a random number between 10 and 30: 15
Too small! Try again: 18
Congratulations Brian Le, you've guessed the number in 2 tries!
Brian Le, would you like to play again? (Y/N): y

Please guess a random number between 10 and 30: 19
Too large! Try again: 15
Too small! Try again: 16
Congratulations Brian Le, you've guessed the number in 3 tries!
Brian Le, would you like to play again? (Y/N): y

Please guess a random number between 10 and 30: 0
0 is out of range. Please enter a number in the range 10 to 30: 31
31 is out of range. Please enter a number in the range 10 to 30: 18
Too small! Try again: 20
Too small! Try again: 20
Sorry, the number was 26
Brian Le, would you like to play again? (Y/N): n
Is there another player? (Y/N): y
Please enter your name: Bob

Please guess a random number between 10 and 30: 30
Too large! Try again: 29
Too large! Try again: 24
Too large! Try again: 12
Too small! Try again: 27
Sorry, the number was 21
Bob, would you like to play again? (Y/N): y

Please guess a random number between 10 and 30: 16
Too small! Try again: 18
Too small! Try again: 19
Too small! Try again: 20
Too small! Try again: 25
Sorry, the number was 26
Bob, would you like to play again? (Y/N): n
Is there another player? (Y/N): n
Please check the output file "players.txt"

 */
