#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cctype>
#include <algorithm>

using namespace std;

/*
    Приветствие +
    Загадать слово +
        Составить слова в вектора +
        Перемешать словаа в векторе +
        Выбрать случайное слово +
        Скрыть слово +
    Спросить букву +
    Проверить букву в слове +
        Если догадка верна +
            открыть букву +
        Иначе если буква уже спрашивалась
            спросить букву
        Иначе
            Увеличить количество ошибок
            Добавить букву в словарь
            спросить букву
    Проверить на выгирыш +
        Если слово угалано
            победа
        иначе
            проигрыш
*/

const int MAX_WRONGS = 8;

int greeting() {
    cout << "Welcome to HANGMAN";
    return 0;
}

string words() {
    vector<string> words;
    words.push_back("GUESS");
    words.push_back("HANGMAN");
    words.push_back("DIFFICULT");
    words.push_back("ANSWER");

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
    }
    else {
        cout << "You lose\n";
    }
    cout << "The hidden word is: " << word;
    return 0;
}

int main() {
    string word = words();
    string soFar(word.size(), '-');
    cout << word << "\n";
    cout << soFar << "\n";
    string used = "";
    int worngs = 0;

    while (soFar != word && worngs != MAX_WRONGS) {
        char chararcter = player(used);
        if (check(chararcter, word)) {
            soFar = replace(soFar, word, chararcter);
            
        } else {
            cout << "" << "\n";
            worngs ++;
        }
        used += chararcter;
    }
    winner(word, soFar);
}