#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <algorithm>

using namespace std;

const int MAX_WRONGS = 8;

int greeting() {
    cout << "Welcome to HANGMAN. Good luck\n\n";
    return 0;
}

string words() {
    vector<string> words;
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");
    words.push_back("ANSWER");
    words.push_back("ENTER");
    words.push_back("CHAPTER");
    words.push_back("USER");

    srand(time(0));
    random_shuffle(words.begin(), words.end());

    const string WORD = words[0];
    
    return WORD;
}

char player(string used) {
    char player_guess = ' ';
    cout << "Enter a guess: ";
    cin >> player_guess;
    player_guess = toupper(player_guess);
    while (used.find(player_guess) != string::npos) {
        cout << "\nYou have allready guessed " << player_guess;
        cout << "\n\nEnter your guess: ";
        cin >> player_guess;
        player_guess = toupper(player_guess);
    } 
    return player_guess;
}

bool check (char player_guess, string word) {
    bool check;
    if (word.find(player_guess) != string::npos){
        check = true;
    }
    else {
        check = false;
    }
    return check;
}

string replace(string soFar, string word, char guess) {
    for (int i = 0; i < word.length(); ++i) {
        if (word[i] == guess) {
            soFar[i] = guess;
        }
    }
    return soFar;
}

int winner(string word, string soFar) {
    if (word == soFar) {
        cout << "\n\nYou guessed right.\n";
        cout << "You win\n";
    }
    else {
        cout << "\nYou have been hanged!\n";
        cout << "You lose\n";
    }
    cout << "The hidden word is: " << word;
    return 0;
}

int main() {
    string word = words();
    string soFar(word.size(), '-');
    string used = "";
    int wrongs = 0;

    while (soFar != word && wrongs != MAX_WRONGS) {
        cout << "\n\nYou have " << (MAX_WRONGS - wrongs) << " incorrect guesses left\n";
        cout << "\nYou have used the following letters:\n" << used << endl;
        cout << "\nSo far. the word is\n" << soFar << endl;

        char chararcter = player(used);
        if (check(chararcter, word)) {
            soFar = replace(soFar, word, chararcter);
            cout << "That`s right! " << chararcter << " is in the word\n";
        } else {
            cout << "Sorry " << chararcter << " isn`t in the word";
            wrongs ++;
        }
        used += chararcter;
    }
    winner(word, soFar);
}