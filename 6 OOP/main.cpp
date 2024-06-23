#include <ctime>
#include "Person.h"
#include "Railway.h"
#include "Tickets.h"
#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>

using namespace std;

void clearScreen() {
    // Для Windows
#ifdef _WIN32
    system("cls");
#else
    // Для Unix/Linux/MacOS
    system("clear");
#endif
}

void printTrain(int offset) {
    string train[] = {
        "      ====        ____                __  ",
        "  _D _|  |_______/ ____\\__I_I_____===__|  ",
        "   |(_)---  |   H\\ ______/ |   |      ||  ",
        "   /     |  |   H  |  |     |   |      ||  ",
        "  |      |  |   H  |__------------------|  ",
        "  | ________|___H__/__|_____/[][]~\\____|  ",
        "  |/ |   |-----------I_____I [][] []  D  ",
        "   |  |   |  || ||  |     |   |  |  ||   |  ",
        "  __|  |___|  ||_|  |_____|____|  |  ||___|  ",
        " |_ /   \\  |  |_|  |_____|_____|  |  ||___|  ",
        "     (O) |__|  (O)---()------()-------(O)   ",
    };

    for (const auto& line : train) {
        for (int i = 0; i < offset; ++i) {
            std::cout << " ";
        }
        std::cout << line << std::endl;
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
	srand(time(NULL));

    int restart;
    restart = 0;
    while(restart != 'n')
    {
        const int trackLength = 52; // Длина "рельсов"
        Person person;
        person.input();
        person.print();

        // Створення залізниці зі списком доступних квитків
        Railway railway(10); // Створюємо залізницю з 10 доступними квитками

        // railway.
         // Отримання квитка
        railway.buy_ticket(person); // Особа купує квиток

        railway.print_rent_tickets();

        char action;
        cout << "Хотите вернуть билет (r) или отправиться в путь (t)? ";
        cin >> action;

        if (action == 'r') {
            railway.get_ticket_back(person);
        }
        else if (action == 't') {
            cout << "Приятного путешествия!" << endl;
            for (int i = 0; i < trackLength; ++i) {
                clearScreen();
                printTrain(i);
                this_thread::sleep_for(chrono::milliseconds(100));
            }
        }
        else {
            cout << "Неверный выбор. Программа завершена." << endl;
        }

        // Повернення квитка
       // railway.get_ticket_back(person);
        cout << "enter restart program y or end program n: ";
        cin >> restart;
    }

    return 0;
}