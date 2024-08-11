#include "Menu.h"

void Menu::setAttemptCounter() {
    attemptCounter++;
}

int Menu::getAttemptCounter() {
    return attemptCounter;
}

void Menu::setRoundCounter() {
    roundCounter++;
}

int Menu::getRoundCounter() {
    return roundCounter;
}

int Menu::showStartMenu() {
    int topicChoice;

    do {
        cout << "----- ���� ���� -----" << endl << endl;
        cout << "����� ����:" << endl;
        cout << "1 - �������" << endl;
        cout << "2 - ��������" << endl;
        cout << "3 - ���" << endl << endl;

        cout << "������� ��� ��������� ����: ";
        cin >> topicChoice;

        if (topicChoice < 1 || topicChoice > 3)
            cout << "������������ ����. ��������� �������" << endl << endl;

    } while (topicChoice < 1 || topicChoice > 3);

    return topicChoice;
}

void Menu::showOutcome(bool checkUnderline) {
    if (checkUnderline)
        cout << "�� ��������!" << endl << endl;
    else
        cout << "�� ���������!" << endl << endl;
}

void Menu::showGameStatisticsMenu(string hiddenWord, UserWords& letters) {
    cout << "----- ���������� " << roundCounter << " ������ ���� -----" << endl << endl;
    cout << "���������� �������: " << clock() / 1000.0 << endl;
    cout << "���������� �������: " << attemptCounter << endl;
    cout << "������� �����: " << hiddenWord << endl;
    cout << "�������� �����: ";
    letters.printLetters();
    cout << endl;
}

int Menu::showRoundMenu() {
    int roundChoice;

    do {
        cout << endl << "������ ����� �����?" << endl;
        cout << "1 - ��" << endl;
        cout << "2 - ���" << endl << endl;

        cout << "������� ��� ����: ";
        cin >> roundChoice;

        if (roundChoice < 1 || roundChoice > 2)
            cout << "������������ ����. ��������� �������" << endl << endl;
        else
            cout << endl << endl;

    } while (roundChoice < 1 || roundChoice > 2);

    return roundChoice;
}