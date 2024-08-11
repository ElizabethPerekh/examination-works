#pragma once
#include <queue>
#include <iostream>
using namespace std;

class UserWords {

private:
	queue<char> letters;

public:
	UserWords() : letters{} {}

	// ���������� �����, �������� �������������, � �������
	void addLetters(char letter);

	// ����� �� ����� ���� ����, �������� ������������� � ������
	void printLetters();
};