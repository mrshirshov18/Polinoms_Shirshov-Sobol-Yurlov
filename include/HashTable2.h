#pragma once
#include <iostream>
#include <vector>
using namespace std;
template <typename Tkey, typename TValue>
class HashTable2
{
    int static const MaxSize = 101;
    struct TTableRec {
        Tkey key;
        TValue value;
        int state = 0;  //-1 deleted; 1 reserved ; 0 empty
    };
    int const p = 2; //шаг перехода функциии перехода
    TTableRec data[MaxSize]{};
    int size;//количество занятых
    int h(Tkey key) {
        int sum = 0;
        for (char ch : key)
            sum += ch;
        return sum % MaxSize;
    }; //хеш функция
    int hh(Tkey key) {
        return (h(key) + p) % MaxSize;
    }; //функция перехода
public:
    HashTable2() = default;
    int size_of_table() const noexcept { return size; }
    TValue& operator[](size_t pos) { return data[pos].value; }//?
    void Delete(Tkey key) {
        int delkey = Find_pos(key);
        if (delkey) {
            data[delkey].state = -1;
            size--;
        }
        return;
    }
    int Find_pos(Tkey key) {
        int num = -1; //номер найденной строки
        int ind = h(key);
        while (1) {
            if (data[ind].state == 1 && data[ind].key == key) {
                num = ind;
                return num;
            }
            if (data[ind].state == 0) {
                return num;
            }
            ind = hh(key);
        }
    }
    TValue* Find(Tkey key) {
        int num = -1; //номер найденной строки
        int ind = h(key);
        while (1) {
            if (data[ind].state == 1 && data[ind].key == key) {
                num = ind;
                return &data[ind].value;
            }
            if (data[ind].state == 0) {
                return nullptr;
            }
            ind = hh(key);
        }
    }
    void Insert(Tkey key, TValue value) {
        if (size == MaxSize)
            return;
        int num = -1;//номер строки для вставки
        int ind = h(key);
        while (1) {
            if (data[ind].state == 1 && data[ind].key == key) {
                return;
            }
            if (data[ind].state == -1 && num == -1) {
                num = ind;
            }
            if (data[ind].state == 0 && num == -1) {
                data[ind].state = 1;
                data[ind].value = value;
                data[ind].key = key;
                size++;
                return;
            }
            if (data[ind].state == 0 && num > -1) {
                data[num].state = 1;
                data[num].value = value;
                data[num].key = key;
                size++;
                return;
            }
            ind = hh(key);
        }
    }
    vector<string> GiveTable() {
        vector<string> arr;
        for (int i = 0; i < MaxSize; i++) {
            if (data[i].state == 1)
                arr.push_back(data[i].key + " = " + data[i].value.GivePolinom());
        }
        return arr;
    }
    void Print() {

        for (int i = 0; i < MaxSize; i++) {
            if (data[i].state == 1) {
                cout << data[i].key << " = ";
                data[i].value.Print();
                cout << endl;
            }
        }
    }
};

