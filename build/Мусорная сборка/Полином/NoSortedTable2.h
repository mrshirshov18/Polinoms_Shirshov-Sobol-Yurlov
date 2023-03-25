#pragma once
#include "f_list.h"
template <typename Tkey, typename TValue>
class NoSortedTable2
{
    struct TTableRec {
        Tkey key;
        TValue value;
    };
    f_list <TTableRec> data();

public:
    NoSortedTable() = default;
    size_t size() const noexcept { return data.size(); }
    TValue& operator[](size_t pos) {
        int i=0;
        for (auto& val : data)
            if(i==pos)
                return val.value;
    }//?
    void Delete(Tkey key) {
        TValue& before=&data.value;
        for (auto& val : data)
            if (val.key == key) {
                if(&val.value==before)
                    data.pop_front;
                data.erase_after(before);
            }
            before=&val.value;
    }
    TValue* Find(Tkey key) {
        for (auto& val : data)
            if (val.key == key)
                return &val.value;
        return nullptr;
    }

    void Insert(Tkey key, Tvalue value) {
        if (Find(key))
            return;
        
        for (auto& val : data)
        data.push_back({ key,value });
    }
    f_list <TTableRec> GiveTable() {
        return data;
    }

};
