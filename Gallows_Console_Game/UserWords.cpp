#include "UserWords.h"

// Добавление буквы, введённой пользователем, в очередь
void UserWords::addLetters(char letter) {
	letters.push(letter);
}

// Вывод на экран всех букв, введённых пользователем в раунде
void UserWords::printLetters() {
	if (!letters.empty())
		while (!letters.empty()) {
			cout << letters.front() << " ";
			letters.pop();
		}
}