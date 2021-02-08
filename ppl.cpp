#include "people.h"
#include <fstream>
#include <ctime>
#include <string>

std::ostream& operator << (std::ostream& out, const people& ppl) {
    out << ppl.surname << " " << ppl.name << " " << ppl.phone << " " << ppl.email << " " << ppl.birthday << " ";
    return out;
}

std::istream& operator >> (std::istream& in, people& ppl) {
    std::cout << "Enter surname: ";
    in.getline(ppl.surname, 32);
    std::cout << "Enter name: ";
    in.getline(ppl.name, 16);
    std::cout << "Enter phone number: ";
    in.getline(ppl.phone, 16);
    std::cout << "Enter E-mail: ";
    in.getline(ppl.email, 32);
    std::cout << "Enter date of birth: ";
    in.getline(ppl.birthday, 10);
    return in;
}

bool operator < (const people& l, const people& r) {
    return strcmp(l.surname, r.surname) < 0;
}
bool SS(const people& l, const people& r) {
    int res = strcmp(l.surname, r.surname);
    if (res < 0)
        return true;
    if (res == 0)
        return strcmp(l.name, r.name) < 0;
    return false;
}
bool SB(const people& l, const people& r) {
    int d = 0, m = 0, y = 0, D = 0, M = 0, Y = 0;
    d = (l.birthday[0] - 48) * 10 + (l.birthday[1] - 48);
    m = (l.birthday[3] - 48) * 10 + (l.birthday[4] - 48);
    y = (l.birthday[6] - 48) * 1000 + (l.birthday[7] - 48) * 100 + (l.birthday[8] - 48) * 10 + (l.birthday[9] - 48);

    D = (r.birthday[0] - 48) * 10 + (r.birthday[1] - 48);
    M = (r.birthday[3] - 48) * 10 + (r.birthday[4] - 48);
    Y = (r.birthday[6] - 48) * 1000 + (r.birthday[7] - 48) * 100 + (r.birthday[8] - 48) * 10 + (r.birthday[9] - 48);

    if (y < Y) return true;
    if (y == Y && m < M) return true;
    if (y == Y && m == M && d < D) return true;
    return false;
}

bool SDB(const people& l, const people& r) {
    int ld = 0, lm = 0, rd = 0, rm = 0;
    ld = (l.birthday[0] - 48) * 10 + (l.birthday[1] - 48);
    lm = (l.birthday[3] - 48) * 10 + (l.birthday[4] - 48);

    rd = (r.birthday[0] - 48) * 10 + (r.birthday[1] - 48);
    rm = (r.birthday[3] - 48) * 10 + (r.birthday[4] - 48);

    if (lm < rm) return true;
    if (lm == rm && ld < rd) return true;
    return false;
}

int addNote(DataBase& DB) {
    people* tmp = new people[DB.count + 1];
    for (int i = 0; i < DB.count; ++i) {
        tmp[i] = DB.data[i];
    }
    if (DB.data)
        delete[] DB.data;
    DB.data = tmp;

    std::cin >> DB.data[DB.count];
    ++DB.count;
    std::cout << "New note added to notebook!" << std::endl;
    return DB.count;
}
void deleteNote(DataBase& DB) {
    int x = searchSN(DB);
    if (x < 0) {
        return;
    }
    std::cout << "Are you sure you want to delete the note from the notebook? (Y(y)/N(n)): ";
    char ch[128];
    std::cin.getline(ch, 128);
    if (ch[0] == 'Y' || ch[0] == 'y') {
        for (int i = x + 1; i < DB.count; ++i) {
            DB.data[i - 1] = DB.data[i];
        }
        --DB.count;
    }
    std::cout << "The note has been deleted from the notebook!" << std::endl;
}
void saveDB(const DataBase& DB) {
    char fname[256];
    std::cout << "Notebook file name [default: notebook.db]: ";
    std::cin.getline(fname, 256);
    if (strlen(fname) < 1)
        strcpy_s(fname, "notebook.db");

    std::ofstream ofile;
    ofile.open(fname, std::ios_base::binary);
    if (!ofile) {
        std::cout << "This file doesn't open! " << fname << std::endl;
        return;
    }
    ofile.write((const char*)&DB.count, sizeof(int));
    ofile.write((const char*)DB.data, sizeof(people) * DB.count);
    ofile.close();
}
void exportDB(const DataBase& DB) {
    char fname[256];
    std::cout << "Enter the name of the notebook text file [default: notebook.txt]: ";
    std::cin.getline(fname, 256);
    if (strlen(fname) < 1)
        strcpy_s(fname, "notebook.txt");
    std::ofstream ofile;
    ofile.open(fname);
    if (!ofile) {
        std::cout << "This file doesn't open! " << std::endl;
        return;
    }
    for (int i = 0; i < DB.count; ++i) {
        ofile << DB.data[i] << "  " << std::endl;
    }
    ofile.close();
    std::cout << "Notebook data has been exported to a file!" << std::endl;
}
void sortSN(DataBase& DB) {
    MySort(DB.data, DB.count, SS);
    std::cout << "Notebook sorted by surname!" << std::endl;
}

void sortB(DataBase& DB) {
    MySort(DB.data, DB.count, SB);
    std::cout << "Notebook sorted by date of birth!" << std::endl;
}

void sortDB(DataBase& DB) {
    MySort(DB.data, DB.count, SDB);
    time_t curr_time;
    curr_time = time(NULL);
    tm* tm_local = localtime(&curr_time);
    int ld = 0, lm = 0, a = 0;
    ld = tm_local->tm_mday;
    lm = tm_local->tm_mon;
    for (int i = 0; i < DB.count; ++i)
    {
        int rd = 0, rm = 0;
        rd = (DB.data[i].birthday[0] - 48) * 10 + (DB.data[i].birthday[1] - 48);
        rm = (DB.data[i].birthday[3] - 48) * 10 + (DB.data[i].birthday[4] - 48);
        if (ld <= rd && lm <= rm) {
            a = i;
            break;
        }
    }
    int b = 0;
    people* tmp = new people[DB.count];
    for (int i = k; i < DB.count; ++i) {
        tmp[l++] = DB.data[i];
    }
    for (int i = 0; i < k; ++i) {
        tmp[b++] = DB.data[i];
    }
    if (DB.data) delete[] DB.data;
    DB.data = tmp;

    std::cout << "Notebook sorted by number of days before birthday!" << std::endl;
}

int searchSN(const DataBase& DB) {
    std::cout << "Enter the user's surname: ";
    char tmp[32];
    std::cin >> tmp;
    std::cin.ignore();
    for (int x = 0; x < DB.count; ++x) {
        int res = strcmp(tmp, DB.data[x].surname);
        if (res == 0)
        {
            std::cout << DB.data[x] << std::endl;
            return x;
        }
    }
    std::cout << "There is no user with that surname! " << std::endl;
    return 1;
}

int searchPN(const DataBase& DB) {
    std::cout << "Enter the user's phone number: ";
    char tmp[32];
    std::cin >> tmp; std::cin.ignore();
    for (int x = 0; x < DB.count; ++x) {
        int res = strcmp(tmp, DB.data[x].phone);
        if (res == 0)
        {
            std::cout << DB.data[x] << std::endl;
            return x;
        }
    }
    std::cout << "User with this phone number doesn't exist" << std::endl;
    return 1;
}