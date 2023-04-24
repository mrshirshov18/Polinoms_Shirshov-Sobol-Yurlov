#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Polinom.h"
using namespace std;
template< typename Tkey, typename TValue>
class SortedTable
{
    struct TTableRec {
        Tkey key;
        TValue value;
    };
    vector <TTableRec> data{};
    int binary_search(Tkey key) {
        int l = 0;
        int r = data.size();
        if (r == 0)
            return -1;
        int mid;

        while (l < r) {
            mid = (l + r) / 2;

            if (data[mid].key > key)
                r = mid;
            else l = mid + 1;
        }

        r--;

        if (data[r].key == key)
            return r;
        else return -1;
    }
public:
    SortedTable() = default;
    size_t size() const noexcept { return data.size(); }
    TValue& operator[](size_t pos) { return data[pos].value; }//?
    void Delete(Tkey key) {
        if (nullptr == Find(key))
            return;
        int pos = binary_search(key);
        for (size_t i = pos; i < data.size() - 1; i++) {
            data[i] = data[i + 1];
        }
        data.pop_back();
    }
    TValue* Find(Tkey key) {
        int n = binary_search(key);
        if (n > -1)
            return &data[n].value;
        return nullptr;
    }
    TValue FindPol(Tkey key) {
        int n = binary_search(key);
        if (n > -1)
            return data[n].value;
        return Polinom();
    }
    void Insert(Tkey key, TValue value) {
        if (Find(key))
            return;
        size_t pos = data.size();
        for (size_t i = 0; i < data.size(); i++) {
            if (data[i].key >= key) {
                pos = i;
                break;
            }
        }
        if (pos == data.size()) {
            data.push_back({ key,value });
            return;

        }
        TTableRec temp, temp2;
        temp = data[pos];
        data[pos].key = key;
        data[pos].value = value;
        for (size_t i = pos + 1; i < data.size() - 1; i++) {

            temp2 = data[i];
            data[i].key = temp.key;
            data[i].value = temp.value;
            temp = temp2;
        }

        data.push_back(temp);
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


