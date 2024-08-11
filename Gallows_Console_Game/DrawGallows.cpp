#include "DrawGallows.h"

void DrawGallows::drawGallows1() {
    cout << "  _____" << endl;
    cout << " |    |" << endl;
    cout << " |    " << endl;
    cout << " |    " << endl;
    cout << " |    " << endl;
    cout << "_|_" << endl;
}

void DrawGallows::drawGallows2() {
    cout << "  _____" << endl;
    cout << " |    |" << endl;
    cout << " |    O" << endl;
    cout << " |    " << endl;
    cout << " |    " << endl;
    cout << "_|_" << endl;
}

void DrawGallows::drawGallows3() {
    cout << "  _____" << endl;
    cout << " |    |" << endl;
    cout << " |    O" << endl;
    cout << " |    |" << endl;
    cout << " |    " << endl;
    cout << "_|_" << endl;
}

void DrawGallows::drawGallows4() {
    cout << "  _____" << endl;
    cout << " |    |" << endl;
    cout << " |    O" << endl;
    cout << " |   /|" << endl;
    cout << " |    " << endl;
    cout << "_|_" << endl;
}

void DrawGallows::drawGallows5() {
    cout << "  _____" << endl;
    cout << " |    |" << endl;
    cout << " |    O" << endl;
    cout << " |   /|\\" << endl;
    cout << " |    " << endl;
    cout << "_|_" << endl;
}

void DrawGallows::drawGallows6() {
    cout << "  _____" << endl;
    cout << " |    |" << endl;
    cout << " |    O" << endl;
    cout << " |   /|\\" << endl;
    cout << " |   /" << endl;
    cout << "_|_" << endl;
}

void DrawGallows::drawGallows7() {
    cout << "  _____" << endl;
    cout << " |    |" << endl;
    cout << " |    O" << endl;
    cout << " |   /|\\" << endl;
    cout << " |   / \\" << endl;
    cout << "_|_" << endl;
}

void DrawGallows::drawGallows(int count) {
    switch (count) {
    case 1:
        drawGallows1();
        break;
    case 2:
        drawGallows2();
        break;
    case 3:
        drawGallows3();
        break;
    case 4:
        drawGallows4();
        break;
    case 5:
        drawGallows5();
        break;
    case 6:
        drawGallows6();
        break;
    case 7:
        drawGallows7();
    default:
        break;
    }
}