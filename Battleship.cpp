#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
using namespace std;

int main()
{
    srand(time(0));
    //Number of rows and columns
    cout << "\nHow many rows?\n";
    int rowNumber;
    cin >> rowNumber;
    cout << "\nHow many columns?\n";
    int colNumber;
    cin >> colNumber;

    //Setup
    int turns = 0;
    int shipCount = 0;
    bool ships[rowNumber][colNumber];

    for (int i = 0; i < rowNumber; i++) {
        for (int j = 0; j < colNumber; j++) {
            ships[i + 1][j + 1] = round((float)(rand()) / (float)(RAND_MAX));
        }
    }

    //Check spaces for battleships
    for (int i = 0; i < rowNumber; i++) {
        for (int j = 0; j < colNumber; j++) {
            if (ships[i][j] == 1) {
                ++shipCount;
            }
        }
    }

    while (shipCount != 0) {
        int row, col;

        cout << "\nWhat row do you want to attack?\n";
        cin >> row;
        cout << "\nWhat column do you want to attack?\n";
        cin >> col;
        ++turns;
        if (row < 1 || col < 1 || row > rowNumber || col > colNumber) {
            cout << "Outside of boundaries";
        } else {
            if (ships[row][col] == 1 && shipCount == 1) {
                cout << "\nYou Win! It took you " << turns << " turns!\n";
            } else if (ships[row][col] == 1) {
                --shipCount;
                cout << "\nHit!\n" << shipCount << " ships left!";
                ships[row][col] = 0;
            } else {
                cout << "\nMiss\n" << shipCount << " ships left!";
            }
        }
    }

    return 0;
}