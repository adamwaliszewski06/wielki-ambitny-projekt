#include <iostream>
#include <limits>
#include <cctype>
#include <cstdlib> // biblioteki potrzebne do uzycia rand i srand 
#include <ctime> 
#include <string>
#include "headerFile.h"
using namespace std;

int DataCounter; // zlicza ile jest zapisanych wartości (każda konwersja to +2 do tej liczby
double memory[100] = { 0 }; // tablica przechowująca wartości liczbowe tempteratur
char memoryUnit[100] = { ' ' }; //tablica przechowująca symbole temperatur
bool conversionFailed = false;



int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    double degrees;
    int yesno;
    int choice, choice2;
    DataCounter = 0;

    while (1) {
        system("cls"); //wywołuje polecenie systemowe clear screen

        if (DataCounter >= 99) {
            cout << "Memory full. Clear history?" << endl;
            cout << "1 - Yes" << endl;
            cout << "0 - No" << endl;
            cin >> yesno;
            if (yesno == 0) {
                cout << "Further conversions will not be saved in history.";
            }
            else {
                
                DataCounter = 0;
            }
        }

        menu();
        char str[100];
        cin.getline(str, 100);
        int choice = convertToInteger(str, sizeof(str));


        if (conversionFailed) { // zabezpieczenie przy wpisaniu nie-liczby lub nie-integera
            cout << "Invalid input." << endl;
            waitForEnter();
        }
        else {
            switch (choice)
            {
            case -1:
                cout << "Exiting program";
                waitForEnter();
                return 0;
            case 1:
                degrees = getF();
                degrees = check(degrees, 'F'); // sprawdza, czy temperatura mieści się we właściwym zakresie; jeśli tak, zwraca ją
                //a jeśli nie, to zwraca -999.0
                if (degrees == -999.0) {
                    cout << "Invalid temperature." << endl;
                    waitForEnter();
                }
                else {
                    cout << "Temperature in Celsius: " << FtoC(degrees) << endl; //wyświetla przekonwertowaną temperaturę
                    if (DataCounter <= 98) {
                        memory[DataCounter] = degrees; //zapisuje wprowadzoną temperaturę
                        memoryUnit[DataCounter] = 'F'; //i jej symbol
                        DataCounter++;
                        memory[DataCounter] = FtoC(degrees); //zapisuje przekonwertowaną temperaturę i symbol
                        memoryUnit[DataCounter] = 'C';
                        DataCounter++; // łącznie DataCounter=DataCounter+2 po każdej konwersji
                    }
                    else
                        cout << "This conversion was not added to history due to lack of space in memory.";
                    waitForEnter();
                }
                break;
            case 2:
                degrees = getF();
                degrees = check(degrees, 'F');
                if (degrees == -999.0) {
                    cout << "Invalid temperature." << endl;
                    waitForEnter();
                }
                else {
                    if (DataCounter <= 98) {
                        cout << "Temperature in Kelvin: " << FtoK(degrees) << endl;
                        memory[DataCounter] = degrees;
                        memoryUnit[DataCounter] = 'F';
                        DataCounter++;
                        memory[DataCounter] = FtoK(degrees);
                        memoryUnit[DataCounter] = 'K';
                        DataCounter++;
                    }
                    else
                        cout << "This conversion was not added to history due to lack of space in memory.";
                    waitForEnter();
                }
                break;
            case 3:
                degrees = getC();
                degrees = check(degrees, 'C');
                if (degrees == -999.0) {
                    cout << "Invalid temperature." << endl;
                    waitForEnter();
                }
                else {
                    if (DataCounter <= 98) {
                        cout << "Temperature in Fahrenheit: " << CtoF(degrees) << endl;
                        memory[DataCounter] = degrees;
                        memoryUnit[DataCounter] = 'C';
                        DataCounter++;
                        memory[DataCounter] = CtoF(degrees);
                        memoryUnit[DataCounter] = 'F';
                        DataCounter++;
                    }
                    else
                        cout << "This conversion was not added to history due to lack of space in memory.";
                    waitForEnter();
                }
                break;
            case 4:
                degrees = getC();
                degrees = check(degrees, 'C');
                if (degrees == -999.0) {
                    cout << "Invalid temperature." << endl;
                    waitForEnter();
                }
                else {
                    if (DataCounter <= 98) {
                        cout << "Temperature in Kelvin: " << CtoK(degrees) << endl;
                        memory[DataCounter] = degrees;
                        memoryUnit[DataCounter] = 'C';
                        DataCounter++;
                        memory[DataCounter] = CtoK(degrees);
                        memoryUnit[DataCounter] = 'K';
                        DataCounter++;
                    }
                    else
                        cout << "This conversion was not added to history due to lack of space in memory.";
                    waitForEnter();
                }
                break;
            case 5:
                degrees = getK();
                degrees = check(degrees, 'K');
                if (degrees == -999.0) {
                    cout << "Invalid temperature." << endl;
                    waitForEnter();
                }
                else {
                    if (DataCounter <= 98) {
                        cout << "Temperature in Celsius: " << KtoC(degrees) << endl;
                        memory[DataCounter] = degrees;
                        memoryUnit[DataCounter] = 'K';
                        DataCounter++;
                        memory[DataCounter] = KtoC(degrees);
                        memoryUnit[DataCounter] = 'C';
                        DataCounter++;
                    }
                    else
                        cout << "This conversion was not added to history due to lack of space in memory.";
                    waitForEnter();
                }
                break;
            case 6:
                degrees = getK();
                degrees = check(degrees, 'K');
                if (degrees == -999.0) {
                    cout << "Invalid temperature." << endl;
                    waitForEnter();
                }
                else {
                    if (DataCounter <= 98) {
                        cout << "Temperature in Fahrenheit: " << KtoF(degrees) << endl;
                        memory[DataCounter] = degrees;
                        memoryUnit[DataCounter] = 'K';
                        DataCounter++;
                        memory[DataCounter] = KtoF(degrees);
                        memoryUnit[DataCounter] = 'F';
                        DataCounter++;
                    }
                    else
                        cout << "This conversion was not added to history due to lack of space in memory.";
                    waitForEnter();
                }
                break;
            case 7:
                if (DataCounter == 0) {
                    cout << "No history available." << endl;
                    waitForEnter();
                }
                else {
                    menu2();






                    /////////////////////////////////////////////////

                    char str2[100];
                    cin.getline(str2, 100);
                    int choice2 = convertToInteger(str2, sizeof(str2));
                    if (conversionFailed) { 
                        cout << "Invalid input." << endl;
                        waitForEnter();
                    }

                    ////////////////////////////////////////////////






                    else {

                        switch (choice2) {
                        case 1:
                        {
                            bool found = false;
                            for (int i = 0; i < DataCounter; i += 2) { //patrzy na temperatury wprowadzone
                                if (memoryUnit[i] == 'F') {
                                    int EntryNumber = (i / 2) + 1;
                                    cout << "<" << EntryNumber << "> " << memory[i] << " " << memoryUnit[i] << " -> " << memory[i + 1] << " " << memoryUnit[i + 1] << endl;
                                    found = true;
                                }
                            }
                            if (!found) {
                                cout << "No conversion history for F found." << endl;
                            }
                        }
                        break;
                        case 2:
                        {
                            bool found = false;
                            for (int i = 0; i < DataCounter; i += 2) {
                                if (memoryUnit[i] == 'C') {
                                    int EntryNumber = (i / 2) + 1;
                                    cout << "<" << EntryNumber << "> " << memory[i] << " " << memoryUnit[i] << " -> " << memory[i + 1] << " " << memoryUnit[i + 1] << endl;
                                    found = true;
                                }
                            }
                            if (!found) {
                                cout << "No conversion history for C found." << endl;
                            }
                        }
                        break;
                        case 3:
                        {
                            bool found = false;
                            for (int i = 0; i < DataCounter; i += 2) {
                                if (memoryUnit[i] == 'K') {
                                    int EntryNumber = (i / 2) + 1;
                                    cout << "<" << EntryNumber << "> " << memory[i] << " " << memoryUnit[i] << " -> " << memory[i + 1] << " " << memoryUnit[i + 1] << endl;
                                    found = true;
                                }
                            }
                            if (!found) {
                                cout << "No conversion history for K found." << endl;
                            }
                        }
                        break;
                        default:
                            for (int i = 0; i < DataCounter; i += 2) {
                                int EntryNumber = (i / 2) + 1;
                                cout << "<" << EntryNumber << "> " << memory[i] << " " << memoryUnit[i] << " -> " << memory[i + 1] << " " << memoryUnit[i + 1] << endl;
                            }
                        }
                        waitForEnter();
                    }
                    break;
                }
            
            case 8:
            {
                while (1) {
                    if (DataCounter == 0) {
                        cout << "No history available." << endl;
                        waitForEnter();
                    }
                    else {
                        for (int i = 0; i < DataCounter; i += 2) {
                            int EntryNumber = (i / 2) + 1;
                            cout << "<" << EntryNumber << "> " << memory[i] << " " << memoryUnit[i] << " -> " << memory[i + 1] << " " << memoryUnit[i + 1] << endl;
                        }
                        cout << "Which element would you like to delete from history?" << endl;
                        int entityToRemove;
                        if (!readInt(entityToRemove)) {
                            cout << "Invalid input." << endl;
                            waitForEnter();
                            break;
                        }
                        int maxEntries = DataCounter / 2;
                        if (entityToRemove < 1 || entityToRemove > maxEntries) {
                            cout << "Error. Invalid number - there is no element <" << entityToRemove << "> in history." << endl;
                        }
                        else {
                            removeFromHistory(entityToRemove);
                        }
                        cout << "Would you like to remove another element? (1 - Yes, 0 - No)" << endl;
                        int yn;
                        cin >> yn;
                        if (yn != 1) {
                            break; // wychodzi z pętli while(1) i wraca do głównego menu
                        }

                    }
                }
            }
            break;
            case 9: // modyfikacja wpisu w historii
            {
                if (DataCounter == 0) {
                    cout << "No history available." << endl;
                    waitForEnter();
                }
                else {
                    for (int i = 0; i < DataCounter; i += 2) {
                        int EntryNumber = (i / 2) + 1;
                        cout << "<" << EntryNumber << "> " << memory[i] << " " << memoryUnit[i] << " -> " << memory[i + 1] << " " << memoryUnit[i + 1] << endl;
                    }
                    cout << "Which element would you like to modify?" << endl;
                    int entityToModify;
                    if (!readInt(entityToModify)) {
                        cout << "Invalid input." << endl;
                        waitForEnter();
                        break;
                    }
                    int maxEntries = DataCounter / 2;
                    if (entityToModify < 1 || entityToModify > maxEntries) {
                        cout << "Error. Invalid number - there is no element <" << entityToModify << "> in history." << endl;
                        waitForEnter();
                        break;
                    }
                    cout << "Enter the unit you'll be converting from (C/F/K): ";
                    char newUnit;
                    cin >> newUnit;
                    newUnit = static_cast<char>(std::toupper(static_cast<unsigned char>(newUnit)));
                    if (newUnit != 'C' && newUnit != 'F' && newUnit != 'K') {
                        cout << "Error. Invalid unit symbol." << endl;
                        waitForEnter();
                        break;
                    }
                    cout << "Enter the temperature value: ";
                    double newTemp;
                    if (!(cin >> newTemp)) {
                        cout << "Invalid number input." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        waitForEnter();
                        break;
                    }
                    int idx = (entityToModify - 1) * 2;
                    double checked = check(newTemp, newUnit);
                    if (checked == -999.0) {
                        cout << "Invalid temperature for unit " << newUnit << endl;
                        waitForEnter();
                        break;
                    }
                    else {
                        switch (choice)
                        {
                        case -1:
                            cout << "Exiting program";
                            waitForEnter();
                            return 0;
                        case 1:
                            degrees = getF();
                            degrees = check(degrees, 'F'); // sprawdza, czy temperatura mieści się we właściwym zakresie; jeśli tak, zwraca ją
                            //a jeśli nie, to zwraca -999.0
                            if (degrees == -999.0) {
                                cout << "Invalid temperature." << endl;
                                waitForEnter();
                            }
                            else {
                                cout << "Temperature in Celsius: " << FtoC(degrees) << endl; //wyświetla przekonwertowaną temperaturę
                                if (DataCounter <= 98) {
                                    memory[DataCounter] = degrees; //zapisuje wprowadzoną temperaturę
                                    memoryUnit[DataCounter] = 'F'; //i jej symbol
                                    DataCounter++;
                                    memory[DataCounter] = FtoC(degrees); //zapisuje przekonwertowaną temperaturę i symbol
                                    memoryUnit[DataCounter] = 'C';
                                    DataCounter++; // łącznie DataCounter=DataCounter+2 po każdej konwersji
                                }
                                else
                                    cout << "This conversion was not added to history due to lack of space in memory.";
                                waitForEnter();
                            }
                            break;
                        case 2:
                            degrees = getF();
                            degrees = check(degrees, 'F');
                            if (degrees == -999.0) {
                                cout << "Invalid temperature." << endl;
                                waitForEnter();
                            }
                            else {
                                if (DataCounter <= 98) {
                                    cout << "Temperature in Kelvin: " << FtoK(degrees) << endl;
                                    memory[DataCounter] = degrees;
                                    memoryUnit[DataCounter] = 'F';
                                    DataCounter++;
                                    memory[DataCounter] = FtoK(degrees);
                                    memoryUnit[DataCounter] = 'K';
                                    DataCounter++;
                                }
                                else
                                    cout << "This conversion was not added to history due to lack of space in memory.";
                                waitForEnter();
                            }
                            break;
                        case 3:
                            degrees = getC();
                            degrees = check(degrees, 'C');
                            if (degrees == -999.0) {
                                cout << "Invalid temperature." << endl;
                                waitForEnter();
                            }
                            else {
                                if (DataCounter <= 98) {
                                    cout << "Temperature in Fahrenheit: " << CtoF(degrees) << endl;
                                    memory[DataCounter] = degrees;
                                    memoryUnit[DataCounter] = 'C';
                                    DataCounter++;
                                    memory[DataCounter] = CtoF(degrees);
                                    memoryUnit[DataCounter] = 'F';
                                    DataCounter++;
                                }
                                else
                                    cout << "This conversion was not added to history due to lack of space in memory.";
                                waitForEnter();
                            }
                            break;
                        case 4:
                            degrees = getC();
                            degrees = check(degrees, 'C');
                            if (degrees == -999.0) {
                                cout << "Invalid temperature." << endl;
                                waitForEnter();
                            }
                            else {
                                if (DataCounter <= 98) {
                                    cout << "Temperature in Kelvin: " << CtoK(degrees) << endl;
                                    memory[DataCounter] = degrees;
                                    memoryUnit[DataCounter] = 'C';
                                    DataCounter++;
                                    memory[DataCounter] = CtoK(degrees);
                                    memoryUnit[DataCounter] = 'K';
                                    DataCounter++;
                                }
                                else
                                    cout << "This conversion was not added to history due to lack of space in memory.";
                                waitForEnter();
                            }
                            break;
                        case 5:
                            degrees = getK();
                            degrees = check(degrees, 'K');
                            if (degrees == -999.0) {
                                cout << "Invalid temperature." << endl;
                                waitForEnter();
                            }
                            else {
                                if (DataCounter <= 98) {
                                    cout << "Temperature in Celsius: " << KtoC(degrees) << endl;
                                    memory[DataCounter] = degrees;
                                    memoryUnit[DataCounter] = 'K';
                                    DataCounter++;
                                    memory[DataCounter] = KtoC(degrees);
                                    memoryUnit[DataCounter] = 'C';
                                    DataCounter++;
                                }
                                else
                                    cout << "This conversion was not added to history due to lack of space in memory.";
                                waitForEnter();
                            }
                            break;
                        case 6:
                            degrees = getK();
                            degrees = check(degrees, 'K');
                            if (degrees == -999.0) {
                                cout << "Invalid temperature." << endl;
                                waitForEnter();
                            }
                            else {
                                if (DataCounter <= 98) {
                                    cout << "Temperature in Fahrenheit: " << KtoF(degrees) << endl;
                                    memory[DataCounter] = degrees;
                                    memoryUnit[DataCounter] = 'K';
                                    DataCounter++;
                                    memory[DataCounter] = KtoF(degrees);
                                    memoryUnit[DataCounter] = 'F';
                                    DataCounter++;
                                }
                                else
                                    cout << "This conversion was not added to history due to lack of space in memory.";
                                waitForEnter();
                            }
                            break;
                        case 7:
                            if (DataCounter == 0) {
                                cout << "No history available." << endl;
                                waitForEnter();
                            }
                            else {
                                menu2();
                                if (!readInt(choice2)) {
                                    cout << "Invalid input." << endl;
                                    waitForEnter();
                                    break;
                                }
                                switch (choice2)
                                {
                                case 1:
                                {
                                    bool found = false;
                                    for (int i = 0; i < DataCounter; i += 2) { //patrzy na temperatury wprowadzone
                                        if (memoryUnit[i] == 'F') {
                                            int EntryNumber = (i / 2) + 1;
                                            cout << "<" << EntryNumber << "> " << memory[i] << " " << memoryUnit[i] << " -> " << memory[i + 1] << " " << memoryUnit[i + 1] << endl;
                                            found = true;
                                        }
                                    }
                                    if (!found) {
                                        cout << "No conversion history for F found." << endl;
                                    }
                                }
                                break;
                                case 2:
                                {
                                    bool found = false;
                                    for (int i = 0; i < DataCounter; i += 2) {
                                        if (memoryUnit[i] == 'C') {
                                            int EntryNumber = (i / 2) + 1;
                                            cout << "<" << EntryNumber << "> " << memory[i] << " " << memoryUnit[i] << " -> " << memory[i + 1] << " " << memoryUnit[i + 1] << endl;
                                            found = true;
                                        }
                                    }
                                    if (!found) {
                                        cout << "No conversion history for C found." << endl;
                                    }
                                }
                                break;
                                case 3:
                                {
                                    bool found = false;
                                    for (int i = 0; i < DataCounter; i += 2) {
                                        if (memoryUnit[i] == 'K') {
                                            int EntryNumber = (i / 2) + 1;
                                            cout << "<" << EntryNumber << "> " << memory[i] << " " << memoryUnit[i] << " -> " << memory[i + 1] << " " << memoryUnit[i + 1] << endl;
                                            found = true;
                                        }
                                    }
                                    if (!found) {
                                        cout << "No conversion history for K found." << endl;
                                    }
                                }
                                break;
                                default:
                                    for (int i = 0; i < DataCounter; i += 2) {
                                        int EntryNumber = (i / 2) + 1;
                                        cout << "<" << EntryNumber << "> " << memory[i] << " " << memoryUnit[i] << " -> " << memory[i + 1] << " " << memoryUnit[i + 1] << endl;
                                    }
                                }
                                waitForEnter();
                            }
                            break;
                        case 8:
                        {
                            while (1) {
                                if (DataCounter == 0) {
                                    cout << "No history available." << endl;
                                    waitForEnter();
                                }
                                else {
                                    for (int i = 0; i < DataCounter; i += 2) {
                                        int EntryNumber = (i / 2) + 1;
                                        cout << "<" << EntryNumber << "> " << memory[i] << " " << memoryUnit[i] << " -> " << memory[i + 1] << " " << memoryUnit[i + 1] << endl;
                                    }
                                    cout << "Which element would you like to delete from history?" << endl;
                                    int entityToRemove;
                                    if (!readInt(entityToRemove)) {
                                        cout << "Invalid input." << endl;
                                        waitForEnter();
                                        break;
                                    }
                                    int maxEntries = DataCounter / 2;
                                    if (entityToRemove < 1 || entityToRemove > maxEntries) {
                                        cout << "Error. Invalid number - there is no element <" << entityToRemove << "> in history." << endl;
                                    }
                                    else {
                                        removeFromHistory(entityToRemove);
                                    }
                                    cout << "Would you like to remove another element? (1 - Yes, 0 - No)" << endl;
                                    int yn;
                                    cin >> yn;
                                    if (yn != 1) {
                                        break; // wychodzi z pętli while(1) i wraca do głównego menu
                                    }

                                }
                            }
                        }
                        break;
                        case 9: // modyfikacja wpisu w historii
                        {
                            if (DataCounter == 0) {
                                cout << "No history available." << endl;
                                waitForEnter();
                            }
                            else {
                                for (int i = 0; i < DataCounter; i += 2) {
                                    int EntryNumber = (i / 2) + 1;
                                    cout << "<" << EntryNumber << "> " << memory[i] << " " << memoryUnit[i] << " -> " << memory[i + 1] << " " << memoryUnit[i + 1] << endl;
                                }
                                cout << "Which element would you like to modify?" << endl;
                                int entityToModify;
                                if (!readInt(entityToModify)) {
                                    cout << "Invalid input." << endl;
                                    waitForEnter();
                                    break;
                                }
                                int maxEntries = DataCounter / 2;
                                if (entityToModify < 1 || entityToModify > maxEntries) {
                                    cout << "Error. Invalid number - there is no element <" << entityToModify << "> in history." << endl;
                                    waitForEnter();
                                    break;
                                }
                                cout << "Enter the unit for the new temperature you'll be converting from (C/F/K): ";
                                char newUnit;
                                cin >> newUnit;
                                newUnit = static_cast<char>(std::toupper(static_cast<unsigned char>(newUnit)));
                                if (newUnit != 'C' && newUnit != 'F' && newUnit != 'K') {
                                    cout << "Error. Invalid unit symbol." << endl;
                                    waitForEnter();
                                    break;
                                }
                                cout << "Enter the temperature value: ";
                                double newTemp;
                                if (!(cin >> newTemp)) {
                                    cout << "Invalid number input." << endl;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    waitForEnter();
                                    break;
                                }
                                int idx = (entityToModify - 1) * 2;
                                double checked = check(newTemp, newUnit);
                                if (checked == -999.0) {
                                    cout << "Invalid temperature for unit " << newUnit << endl;
                                    waitForEnter();
                                    break;
                                }

                                memory[idx] = newTemp;
                                memoryUnit[idx] = newUnit;

                                cout << "Pick which unit to convert this temperature to" << endl <<

                                    "1 - Celsius" << endl <<

                                    "2 - Fahrenheit" << endl <<

                                    "3 - Kelvin" << endl;
                                int pick;
                                if (!readInt(pick)) {
                                    cout << "Invalid input." << endl;
                                    waitForEnter();
                                    break;
                                }

                                if (newUnit == 'C')
                                {
                                    if (pick == 1) {
                                        memory[idx + 1] = newTemp;
                                        memoryUnit[idx + 1] = 'C';
                                    }
                                    else if (pick == 2) {
                                        memory[idx + 1] = CtoF(newTemp);
                                        memoryUnit[idx + 1] = 'F';
                                    }
                                    else {
                                        memory[idx + 1] = CtoK(newTemp);
                                        memoryUnit[idx + 1] = 'K';
                                    }
                                }
                                else if (newUnit == 'F')
                                {
                                    if (pick == 1) {
                                        memory[idx + 1] = FtoC(newTemp);
                                        memoryUnit[idx + 1] = 'C';
                                    }
                                    else if (pick == 2) {
                                        memory[idx + 1] = newTemp;
                                        memoryUnit[idx + 1] = 'F';
                                    }
                                    else {
                                        memory[idx + 1] = FtoK(newTemp);
                                        memoryUnit[idx + 1] = 'K';
                                    }
                                }
                                else {
                                    if (pick == 1) {
                                        memory[idx + 1] = KtoC(newTemp);
                                        memoryUnit[idx + 1] = 'C';
                                    }
                                    else if (pick == 2) {
                                        memory[idx + 1] = KtoF(newTemp);
                                        memoryUnit[idx + 1] = 'F';
                                    }
                                    else {
                                        memory[idx + 1] = newTemp;
                                        memoryUnit[idx + 1] = 'K';
                                    }
                                }
                                cout << "Updated to: " << endl << "<" << entityToModify << "> " << newTemp << " " << newUnit << " -> " << memory[idx + 1] << " " << memoryUnit[idx + 1] << endl;
                                waitForEnter();
                            }
                        }
                        break;
                        case 10: // losowe wypełnienie historii
                            ///////////////////////
                            ///////////////////////
                            ///////////////////////
                            ///////////////////////
                            ///////////////////////
                            /////////////////////
                            ///////////////////////


                        {
                            cout << "How many random entries would you like to generate?" << endl;
                            int howMany;
                            if (!readInt(howMany)) {
                                cout << "Invalid input." << endl;
                                waitForEnter();
                                break;
                            }
                            if (DataCounter + howMany * 2 > 100) {
                                cout << "Not enough space in memory for that many entries. Generate only " << (100 - DataCounter) / 2 << " entries? (1 - Yes, 0 - No)" << endl;
                                int yn;
                                if (!readInt(yn)) {
                                    cout << "Invalid input." << endl;
                                    waitForEnter();
                                    break;
                                }
                                if (yn == 1) {
                                    howMany = (100 - DataCounter) / 2;
                                }
                                else {
                                    break;
                                }
                            }

                            for (int i = 0; i < howMany; ++i) {
                                int unitSelect = rand() % 3; // losuje 0, 1 lub 2

                                if (unitSelect == 0) {
                                    int tempInt = rand() % 1001 - 273; // int in [-273, 727]
                                    double fromTemp = (double)tempInt;

                                    memory[DataCounter] = fromTemp;
                                    memoryUnit[DataCounter] = 'C';
                                    DataCounter++;

                                    int toUnitSelect = rand() % 2; // 0 lub 1

                                    if (toUnitSelect == 0) { // C to F

                                        memory[DataCounter] = CtoF(fromTemp);
                                        memoryUnit[DataCounter] = 'F';
                                        DataCounter++;

                                    }
                                    else {

                                        memory[DataCounter] = CtoK(fromTemp);
                                        memoryUnit[DataCounter] = 'K';
                                        DataCounter++;
                                    }
                                }

                                else if (unitSelect == 1) { // F
                                    int tempInt = rand() % 1001 - 459; // int in [-459, 541]
                                    double fromTemp = (double)tempInt;
                                    int toUnitSelect = rand() % 2; // 0 lub 1

                                    memory[DataCounter] = fromTemp;
                                    memoryUnit[DataCounter] = 'F';
                                    DataCounter++;


                                    if (toUnitSelect == 0) {// F to C
                                        memory[DataCounter] = FtoC(fromTemp);
                                        memoryUnit[DataCounter] = 'C';
                                        DataCounter++;
                                    }
                                    else { // F to K
                                        memory[DataCounter] = FtoK(fromTemp);
                                        memoryUnit[DataCounter] = 'K';
                                        DataCounter++;
                                    }
                                }
                                else { // K
                                    int tempInt = rand() % 1001; // int in [0, 1000]
                                    double fromTemp = (double)tempInt;
                                    int toUnitSelect = rand() % 2; // 0 lub 1

                                    memory[DataCounter] = fromTemp;
                                    memoryUnit[DataCounter] = 'K';
                                    DataCounter++;

                                    if (toUnitSelect == 0) { // K to C
                                        memory[DataCounter] = KtoC(fromTemp);
                                        memoryUnit[DataCounter] = 'C';
                                        DataCounter++;
                                    }
                                    else { // K to F
                                        memory[DataCounter] = KtoF(fromTemp);
                                        memoryUnit[DataCounter] = 'F';
                                        DataCounter++;
                                    }
                                }
                            }
                            break;
                        default:
                            cout << "Exiting program";
                            waitForEnter();
                            return 0;
                        }
                        }
                    }
                }
            }
            }
        }
    }

    return 0;
}
    

       



double FtoC(double degrees){
    double result = (5.0 / 9.0) * (degrees - 32.0);
    return result;
}

double FtoK(double degrees) {
    double result = (5.0 / 9.0) * (degrees + 459.67);
    return result;
}
double CtoF(double degrees) {
    double result = (9.0 / 5.0) * degrees + 32.0;
    return result;
}

double CtoK(double degrees) {
    double result = degrees + 273.15;
    return result;
}

double KtoC(double degrees) {
    double result = degrees - 273.15;
    return result;
}

double KtoF(double degrees) {
    double result = degrees*(9.0/5.0)-459.67;
    return result;
}

void menu() {
    cout << endl << "Enter a number to choose an option: " << endl;
    cout << "1 - convert Fahrenheit to Celsius" << endl;
    cout << "2 - convert Fahrenheit to Kelvin" << endl;
    cout << "3 - convert Celsius to Fahrenheit" << endl;
    cout << "4 - convert Celsius to Kelvin " << endl;
    cout << "5 - convert Kelvin to Celsius" << endl;
    cout << "6 - convert Kelvin to Fahrenheit" << endl;
    cout << "7 - show history" << endl;
    cout << "8 - remove elements from history" << endl;
    cout << "9 - modify an element from history" << endl;
    cout << "10 - randomise entries in history" << endl;
    cout << "-1 - exit the program" << endl;
}

void menu2() {
    cout << endl << "Enter a number to choose which part of history to show: " << endl;
    cout << "1 - conversions from F to C and to K" << endl;
    cout << "2 - conversions from C to F and to K" << endl;
    cout << "3 - conversions from K to C and F" << endl;
    cout << "4 - full history" << endl;
}

double getF() {
    double F;
    cout << "Enter the temperature in Fahrenheit: ";
    cin >> F;
    return F;
}

double getC() {
    double C;
    cout << "Enter the temperature in Celsius: ";
    cin >> C;
    return C;
}

double getK() {
    double K;
    cout << "Enter the temperature in Kelvin: ";
    cin >> K;
    return K;
}

double check(double temp, char u) { //u for unit
    if (u == 'K') { // jeśli check (degrees, 'K'), to sprawdź, czy temp<0 - jeśli tak, to zwróć -999
        if (temp < 0.0) {
            return -999.0;
        }
    }
    else if (u == 'C') { //jeśli check (degrees, 'C'), to sprawdź, czy temp<-273.15 - ...
        if (temp < -273.15) {
            return -999.0;
        }
    }
    else if (u == 'F') { //jeżeli check(degrees,'F'), to sprawdź, czy temp<-459.67 - ...
        if (temp < -459.67) {
            return -999.0;
        }
    }
    else { // jeżeli jednostka to nie K, C lub F, to też zwróć -999, bo to błąd
        return -999.0;
    }
    return temp; //jeżeli temperatura ma poprawną jednostkę i jest większa niż minimum dla tej jednoski, po prostu zwróć temperaturę
}

void removeFromHistory(int nr) {
    int idx = (nr - 1) * 2; // indeks pierwszego elementu pary do usunięcia
    // przesuwamy wszystkie elementy po usuwanej parze o 2 miejsca w lewo
    for (int i = idx; i < DataCounter - 2; ++i) {
        memory[i] = memory[i + 2];
        memoryUnit[i] = memoryUnit[i + 2];
    }
    DataCounter -= 2;
    cout << "Element <" << nr << "> removed from history." << endl;
}

void waitForEnter() {
    cout << endl << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); /* z pomocą copilot; wyjaśnienie na przyszłość:
    pomija/usuwa wszystkie znaki do i włącznie ze znakiem nowej linii, który został po naciśnięciu Enter,
    dzięki czemu cin.get() nie zwraca tego "/n" natychmiast i nie zaczyna od nowa od razu, tylko czeka na
    kolejny Enter */
    cin.get();
}


/* Z pliku laboratoryjnego o convertToInteger:
funkcja dostaje tablice znakow i jej rozmiar.
Wynik: zwraca liczbe calkowita typu int na bazie znakow
w tablicy vector[]. Jesli w tablicy sa znaki inne niz
cyfry, to ustawia zmienna globalna conversionFailed na true.
 */
int convertToInteger(const char vector[], int size) {
    int result = 0;
    bool isNegative = false;

    for (int i = 0; i < size; ++i) {
        if (vector[i] == '\0')
            break; // Stop processing at the null-terminator

        if (isdigit(vector[i])) { // sprawdz czy znak to cyfra
            result = result * 10 + (vector[i] - '0'); //dla cyfr, konwertuj
        }
        else if (vector[i] == '-' && i == 0) {
            isNegative = true; // sprawdz czy liczba zaczyna sie od minusa
        }
        else if (vector[i] == '+' && i == 0) {
            continue; //a jak od plusa to ignoruj
        }
        else {
            if (conversionFailed == false) {
                cout << "Error. Incorrect input for integer type" << endl;
                conversionFailed = true;
            }
        }
    }
    return (isNegative ? -result : result);
}



double convertToDouble(const char vector[], int size) { //code 06_07
    double result = 0.0;
    double fractionalMultiplier = 0.1;
    bool isNegative = false;
    bool isFractional = false;
    bool signRecognised = false;

    for (int i = 0; i < size; ++i) {
        if (vector[i] == '\0')
            break; // Stop processing at the null-terminator

        if (isdigit(vector[i])) {
            if (isFractional) {
                result += (vector[i] - '0') * fractionalMultiplier;
                fractionalMultiplier *= 0.1;
            }
            else {
                result = result * 10.0 + (vector[i] - '0');
            }
        }
        else if (vector[i] == '.' && isFractional == false) {
            isFractional = true; // Start processing fractional part
        }
        else if (vector[i] == '-' && signRecognised == false) {
            signRecognised = true;
            isNegative = true;
        }
        else if (vector[i] == '+' && signRecognised == false) {
            signRecognised = true;
            continue;
        }
        else {
            if (conversionFailed == false) {
                cout << "Error. Incorrect input for integer type" << endl;
                conversionFailed = true;
            }
        }
    }

    return isNegative ? -result : result;
}

bool readInt(int &out) {
    // Try to read an integer from stdin. On failure, clear the error state
    // and discard the rest of the line. Return true on success, false on failure.
    if (!(cin >> out)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    // Consume the remainder of the line so subsequent getline/get calls behave correctly.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return true;
}