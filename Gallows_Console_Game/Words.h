#pragma once
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

class Words {

private:
    string hiddenWord;
    multimap<string, string> words;

public:
    Words() : hiddenWord{ "" }, words{} {}

    string getHiddenWord();

    // Чтение закодированных слов из файла
    void readWords();

    // Этап расшифровки слов
    string decryptionStage(string result, string currentCode);

    // Расшифровка слов
    string decoding(string word);

    // Генерация рандомного числа в диапазоне, зависящем от выбранной темы
    int randomNumberGeneration(int min, int max);

    // Рандомный выбор слова
    string randomWord(int min, int max);

    // Создание слова для пользователя в виде "_ _ _"
    string choiceWord(int min, int max);

    // Проверка наличия буквы в слове
    bool check(char letter, string word);

    // Замена "_" на букву в слове, отображаемом для пользователя
    string revealLetter(char userLetter, string word);

    // Проверка "заполненности" буквами слова, отображаемого для пользователя
    bool checkUnderline(string word);
};