

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <random>
#include <vector>
using namespace std;
const int KEY = 10; // Шифрование

void encryptWord(string& word) {
    for (char& c : word) {
        c ^= KEY; // операция XOR для шифрование
    }
}

void decryptWord(string& word) {
    for (char& c : word) {
        c ^= KEY; // расшифрование
    }
}
vector<string> readEncryptedWords(const string& filename) {
    vector<string> words;
    ifstream file(filename);

    if (file.is_open()) {
        string word;
        while (getline(file, word)) {
            decryptWord(word); // расшифрование слов
            words.push_back(word);
        }
        file.close();
    }
    else {
        cout << "________________________________________________" << endl;
       cerr << "Error" << filename << endl;
       cout << "________________________________________________" << endl;
    }

    return words;
}
void playHangman(const vector<string>& words) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, words.size() - 1); // Random word index

    int wordIndex = dis(gen);
  string word = words[wordIndex];
 string guessedLetters = "";
    int remainingLives = 6;
    cout << "________________________________________________" << endl;
   cout << "Добро пожаловать в нашу игру!!!";
    cout << "________________________________________________" << endl;
    while (remainingLives > 0 && word.find_first_of("_") != string::npos) {
       cout << "\nWord: ";
        for (char c : word) {
            if (guessedLetters.find(c) != string::npos) {
               cout << c;
            }
            else {
                cout << "_";
            }
        }
        cout << "________________________________________________" << endl;
        cout << "Угаданные буквы: " << guessedLetters << endl;
       cout << "Оставшиеся жизни: " << remainingLives << endl;
       cout << "________________________________________________" << endl;
        char guess;
        cout << "________________________________________________" << endl;
       cout << "Введите свое предположение: ";
       cout << "________________________________________________" << endl;
       cin >> guess;

        guess = tolower(guess); 

        if (guessedLetters.find(guess) != string::npos) {
            cout << "________________________________________________" << endl;
            cout << "Вы уже догадались об этой букве. Попробуйте еще раз.";
            cout << "________________________________________________" << endl;
            continue;
        }

        guessedLetters += guess;

        if (word.find(guess) == string::npos) {
            remainingLives--;
            cout << "________________________________________________" << endl;
            cout << "Неверное предположение.";
            cout << "________________________________________________" << endl;
        }
        else {
            for (size_t i = 0; i < word.size(); ++i) {
                if (word[i] == guess) {
                    word[i] = '_'; // отметка угаданная буква раскрытной
                }
            }
        }
    }

    if (remainingLives > 0) {
        cout << "________________________________________________" << endl;
       cout << "Поздравляю вы угадали слово " << word << endl;
       cout << "________________________________________________" << endl;
    }
    else {
        cout << "________________________________________________" << endl;
        cout << "Игра завершина " << word << endl;
        cout << "________________________________________________" << endl;
    }
}
int main() {
    vector<string> words = readEncryptedWords("file.txt"); //чтение зашифровонного файла

    if (words.empty()) {
       cerr << "Error" << endl;
        return 1;
    }

    playHangman(words);

    return 0;
}

