#pragma once
#include <queue>
#include <iostream>
using namespace std;

class UserWords {

private:
	queue<char> letters;

public:
	UserWords() : letters{} {}

	// Добавление буквы, введённой пользователем, в очередь
	void addLetters(char letter);

	// Вывод на экран всех букв, введённых пользователем в раунде
	void printLetters();
};