#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "Polinom.h"
using namespace std;
//typedef string Tkey;
//typedef Polinom TValue;
template< typename Tkey,typename TValue>
class NoSortedTable2
{
    struct TTableRec {
        Tkey key;
        TValue value;
    };
    //f_list <TTableRec> data;
    list<TTableRec> data;
public:
    NoSortedTable2() = default;
    size_t size() const noexcept { return data.size(); }
    TValue& operator[](size_t pos) {
        int i = 0;
        for (auto& val : data)
            if (i == pos)
                return val.value;
    }//?
    void Delete(Tkey key) {
        auto iter = data.begin();
        for (auto& val : data) {
            iter++;
            if (val.key == key) {
                data.erase(--iter);
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
    vector <string> GiveTable() {
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
