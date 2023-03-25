#pragma once
#include <iostream>
#include <vector>
using namespace std;
template <typename Tkey, typename TValue>
class NoSortedTable1
{
    struct TTableRec {
        Tkey key;
        TValue value;
    };
    vector <TTableRec> data{};

public:
    NoSortedTable() = default;
    size_t size() const noexcept { return data.size(); }
    TValue& operator[](size_t pos) { return data[pos].value; }//?
    void Delete(Tkey key) {
        for (size_t i = 0; i < data.size(); , i++)
            if (data[i].key == key) {
                data[i] = data[data.size() - 1];
                data.pop_back;
                return;
            }
    }
    TValue* Find(Tkey key) {
        for (auto& val : data)
            if (val.key == key)
                return &val.value;
        return nullptr;
    }
    void Insert(Tkey key, Tvalue value) {
        if (Find(key)==nullptr)
            return;
        data.push_back({ key,value });
    }
    vector <TTableRec> GiveTable() {
        return data;
    }

};
