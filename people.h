#ifndef __MY_NOTEBOOK__
#define __MY_NOTEBOOK__
#include <iostream>

struct people {
    char surname[32];
    char name[16];
    char phone[16];
    char email[32];
    char birthday[10];
};

struct DataBase {
    int count;
    people* data;
};
std::ostream& operator << (std::ostream& out, const people& st);
std::istream& operator >> (std::istream& in, people& st);

bool operator < (const people& left, const people& right);
bool SB(const people& left, const people& right);
bool SS(const people& left, const people& right);
bool SDB(const people& left, const people& right);

int addNote(DataBase& DB);
void deleteNote(DataBase& DB);
void saveDB(const DataBase& DB);
void exportDB(const DataBase& DB);
void sortSN(DataBase& DB);
void sortB(DataBase& DB);
void sortDB(DataBase& DB);
int searchSN(const DataBase& DB);
int searchPN(const DataBase& DB);


template <typename T>
void MySort(T* M, int n, bool (*comparator)(const T&, const T&)) {
    for (int j = 0; j < n - 1; ++j) {
        int k = j;
        for (int i = k + 1; i < n; ++i) {
            if (comparator(M[i], M[k]))
                k = i;
        }
        if (j < k) {
            std::swap(M[k], M[j]);
        }
    }
}
#endif