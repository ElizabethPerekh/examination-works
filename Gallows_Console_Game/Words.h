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

    // ������ �������������� ���� �� �����
    void readWords();

    // ���� ����������� ����
    string decryptionStage(string result, string currentCode);

    // ����������� ����
    string decoding(string word);

    // ��������� ���������� ����� � ���������, ��������� �� ��������� ����
    int randomNumberGeneration(int min, int max);

    // ��������� ����� �����
    string randomWord(int min, int max);

    // �������� ����� ��� ������������ � ���� "_ _ _"
    string choiceWord(int min, int max);

    // �������� ������� ����� � �����
    bool check(char letter, string word);

    // ������ "_" �� ����� � �����, ������������ ��� ������������
    string revealLetter(char userLetter, string word);

    // �������� "�������������" ������� �����, ������������� ��� ������������
    bool checkUnderline(string word);
};