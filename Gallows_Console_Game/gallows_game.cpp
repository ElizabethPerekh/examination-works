#include "Words.h"
#include "DrawGallows.h"
#include "UserWords.h"
#include "Menu.h"

#include "time.h"

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    Words word1;
    DrawGallows gallows;
    UserWords letters;
    Menu userMenu;

    string wordUser;
    int topicChoice, roundChoice;
    char letter;
    bool checkUnderline;

    word1.readWords();

    do {
        topicChoice = userMenu.showStartMenu();

        if (topicChoice == 1)
            wordUser = word1.choiceWord(10, 14);

        else if (topicChoice == 2)
            wordUser = word1.choiceWord(0, 4);
        else if (topicChoice == 3)
            wordUser = word1.choiceWord(5, 9);

        cout << endl << wordUser << endl << endl;

        do {
            cout << "Введите букву от 'a' до 'z': ";
            cin >> letter;
            cout << endl;

            letters.addLetters(letter);

            if (word1.check(letter, wordUser)) {
                wordUser = word1.revealLetter(letter, wordUser);
                cout << wordUser << endl << endl;
            }
            else {
                userMenu.setAttemptCounter();
                gallows.drawGallows(userMenu.getAttemptCounter());
                cout << endl;
            }

            checkUnderline = word1.checkUnderline(wordUser);

            if (checkUnderline)
                break;

        } while (userMenu.getAttemptCounter() < 7);

        userMenu.showOutcome(checkUnderline);
        userMenu.showGameStatisticsMenu(word1.getHiddenWord(), letters);

        roundChoice = userMenu.showRoundMenu();
        if (roundChoice == 1)
            userMenu.setRoundCounter();

    } while (roundChoice != 2);
}