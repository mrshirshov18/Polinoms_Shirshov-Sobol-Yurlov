#pragma once
#include "Polinom.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
template< typename Tkey, typename TValue>
class NoSortedTable1
{
    int const MaxSize = 100;
    struct TTableRec {
        Tkey key;
        TValue value;
    };
    vector <TTableRec> data{};


public:
    NoSortedTable1() = default;
    size_t size() const noexcept { return data.size(); }
    TValue& operator[](size_t pos) { return data[pos].value; }//?
    void Delete(Tkey key) {
        for (auto& elem : data) {
            if (elem.key == key) {
                elem.key = data[data.size() - 1].key;
                elem.value = data[data.size() - 1].value;
                data.pop_back();
                return;
            }
        }
    }
    TValue* Find(Tkey key) {
        for (auto& val : data)
            if (val.key == key)
                return &val.value;
        return nullptr;
    }
    Polinom FindPol(Tkey key) {
        for (auto& val : data)
            if (val.key == key)
                return val.value;
        return Polinom();
    }
    void Insert(Tkey key, TValue value) {
        if (Find(key))
            return;
        data.push_back({ key,value });
    }
    vector<string> GiveTable() {
        vector<string> arr;
        for (auto& elem : data) {
            arr.push_back(elem.key + " = " + elem.value.GivePolinom());
        }
        return arr;
    }
    void Print() {
        for (auto& elem : data) {
            cout << elem.key << " = ";
            elem.value.Print();
            cout << endl;
        }
    }

};
