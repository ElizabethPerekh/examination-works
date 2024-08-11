#include "Words.h"

string Words::getHiddenWord() {
    return hiddenWord;
}

// Чтение закодированных слов из файла
void Words::readWords() {
    ifstream readFile("D:\\codingWords.txt");

    if (readFile.is_open()) {
        string line, topic, word;

        while (!readFile.eof())
            if (getline(readFile, line)) {
                stringstream ss(line);
                getline(ss, topic, ';');
                getline(ss, word);
                words.insert({ decoding(topic), decoding(word) }); // Расшифровка слов + добавление их в multimap
            }

        readFile.close();
    }
    else
        cout << "File opening error" << endl;
}

// Этап расшифровки слов
string Words::decryptionStage(string result, string currentCode) {
    int asciiCode = stoi(currentCode);
    char character = static_cast<char>(asciiCode);
    result += character;

    return result;
}

// Расшифровка слов
string Words::decoding(string word) {
    string result = "", currentCode = "";

    for (char c : word) {
        if (c != ' ')
            currentCode += c;
        else {
            result = decryptionStage(result, currentCode);
            currentCode = "";
        }
    }

    if (!currentCode.empty())
        result = decryptionStage(result, currentCode);

    return result;
}

// Генерация рандомного числа в диапазоне, зависящем от выбранной темы
int Words::randomNumberGeneration(int min, int max) {
    if (!words.empty())
        return (rand() % (max - min + 1) + min);
    else
        return -1;
}

// Рандомный выбор слова
string Words::randomWord(int min, int max) {
    if (!words.empty()) {
        auto it = words.begin();
        advance(it, randomNumberGeneration(min, max));

        if (it != words.end())
            return it->second;
    }
}

// Создание слова для пользователя в виде "_ _ _"
string Words::choiceWord(int min, int max) {
    if (!words.empty()) {
        hiddenWord = randomWord(min, max);
        string wordUser = "";

        for (int i = 0; i < hiddenWord.size(); i++) {
            if (i < hiddenWord.size() - 1)
                wordUser.append("_ ");
            else
                wordUser.append("_");
        }
        return wordUser;
    }
}

// Проверка наличия буквы в слове
bool Words::check(char letter, string word) {
    for (int i = 0; i < hiddenWord.size(); i++)
        if (hiddenWord[i] == letter)
            return true;

    return false;
}

// Замена "_" на букву в слове, отображаемом для пользователя
string Words::revealLetter(char userLetter, string word) {
    word.erase(remove(word.begin(), word.end(), ' '), word.end());

    for (int i = 0; i < hiddenWord.size(); ++i) {
        if (hiddenWord[i] == userLetter) {
            word[i] = userLetter;
        }
    }

    string spacedWord;

    for (char c : word) {
        spacedWord += c;
        spacedWord += " ";
    }

    spacedWord.pop_back();
    word = spacedWord;

    return word;
}

// Проверка "заполненности" буквами слова, отображаемого для пользователя
bool Words::checkUnderline(string word) {
    for (int i = 0; i < word.size(); ++i)
        if (word[i] == '_')
            return false;

    return true;
}