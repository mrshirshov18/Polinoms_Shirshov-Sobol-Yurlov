#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <typename Tkey, typename TValue>
class SortedTable
{
    struct TTableRec {
        Tkey key;
        TValue value;
    };
    vector <TTableRec> data{};
    int binary_searck(int key) {
        int l = 0;
        int r = data.size();
        int mid;

        while (l < r) {
            mid = (l + r) / 2;

            if (data.key[mid] > key)
                r = mid; 
            else l = mid + 1;
        }

        r--; 

        if (data.key[r] == key)
            return r;
        else return -1;
    }
public:
    NoSortedTable() = default;
    size_t size() const noexcept { return data.size(); }
    TValue& operator[](size_t pos) { return data[pos].value; }//?
    void Delete(Tkey key) {
        int pos=binary_search(key);
        for (size_t i = pos; i < data.size() - 1;, i++) {
            data[i]=data[i+1];
        }
    }
    TValue* Find(Tkey key) {
        int n= binary_searck(int key);
        if(n>-1)
            return &val[n].value;
        return nullptr;
    }
    void Insert(Tkey key, Tvalue value) {
        if (Find(key)==nullptr)
            return;
        size_t pos=lower_bound(key);
        TTableRec temp,temp2;
        temp = data[pos];
        data[pos].key = key;
        data[pos].value = value;
        for (size_t i = pos+1; i < data.size()-1;, i++) {
            
            temp2=data[i];
            data[i].key=temp.key;
            data[i].value=temp.value;
            temp=temp2;
        }

        data.push_back(temp);
    }
    vector <TTableRec> GiveTable() {
        return data;
    }

};


