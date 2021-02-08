#include "people.h"
#include "ppl.cpp"

int menu() {
    for (int i = 0; i < 20; ++i)
        std::cout << '*';
    std::cout << std::endl;
    std::cout << "1. Add a note to notebook." << std::endl;
    std::cout << "2. Delete a note from a notebook." << std::endl;
    std::cout << "3. Save notebbok." << std::endl;
    std::cout << "4. Export notebook to text file." << std::endl;
    std::cout << "5. Sorting by surname." << std::endl;
    std::cout << "6. Sorting by date of birth." << std::endl;
    std::cout << "7. Sorting ny number of days before birthday." << std::endl;
    std::cout << "8. Search by surname." << std::endl;
    std::cout << "9. Search by phone number." << std::endl;
    std::cout << "0. Exit." << std::endl;
    int tmp;
    std::cin >> tmp;
    std::cin.ignore();
    return tmp;
}

int main()
{
    DataBase DB;
    DB.count = 0;
    DB.data = nullptr;
    int action;
    do {
        action = menu();
        switch (action) {
        case 1: addNote(DB); break;
        case 2: deleteNote(DB); break;
        case 3: saveDB(DB); break;
        case 4: exportDB(DB); break;
        case 5: sortSN(DB); break;    // сортировка по фамилии
        case 6: sortB(DB); break;     // сортировка по дню рождения
        case 7: sortDB(DB); break;    // сортировка по количеству дней до дня рождения
        case 8: searchSN(DB); break;  // поиск по фамилии
        case 9: searchPN(DB); break;  // поиск по номеру телефона
        }
    } while (action != 0);

    if (DB.data)
        delete[] DB.data;

    return 0;
}