#include "UserWords.h"

// ���������� �����, �������� �������������, � �������
void UserWords::addLetters(char letter) {
	letters.push(letter);
}

// ����� �� ����� ���� ����, �������� ������������� � ������
void UserWords::printLetters() {
	if (!letters.empty())
		while (!letters.empty()) {
			cout << letters.front() << " ";
			letters.pop();
		}
}