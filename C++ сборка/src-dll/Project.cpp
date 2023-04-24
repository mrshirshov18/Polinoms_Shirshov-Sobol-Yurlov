#include "Project.h"
#define Project
#ifdef Project

extern "C" __declspec(dllexport) int sum(int a, int b) {
    return a + b;
}

NoSortedTable1 <string, Polinom> A;
NoSortedTable2  <string, Polinom> B;
SortedTable <string, Polinom>  C;
HashTable1  <string, Polinom> D;
HashTable2  <string, Polinom> E;
TreeTable <string, Polinom> F;


 vector<string> v;
 int idx; //STATIC

extern "C" __declspec(dllexport) const int calcTable(const char* num)
{
    // ��������� ������ ����������
    int pos = stoi(num);

    /*while (getPolinomeItem(buff)) {
        cout << buff << endl;
    }*/
    v.clear();
    switch (pos) {
    case 1:
        v = A.GiveTable();
        break;
    case 2:
        v = B.GiveTable();
        break;
    case 3:
        v = C.GiveTable();
        break;
    case 4:
        v = D.GiveTable();
        break;
    case 5:
        v = E.GiveTable();
        break;
    case 6:
        v = F.GiveTable();
        break;
    }
    Polinom A("X","X");
    Polinom B("Y", "Y");
    Polinom C("Z", "Z");
    v.push_back("X = "+A.GivePolinom());
    v.push_back("Y = " + B.GivePolinom());
    v.push_back("Z = " + C.GivePolinom());
    idx = 0;
    return v.size();
}
extern "C" __declspec(dllexport) const bool returnbool() {
    if (idx < v.size()) {
        return true;
    }
    return false;
}
extern "C" __declspec(dllexport) const bool returnbool2(int index) {
    if (index < v.size()) {
        return true;
    }
    return false;
}
extern "C" __declspec(dllexport) const int retursize() {
    return v.size();
}
extern "C" __declspec(dllexport) const bool fun_give_table_item1(char* buff, int buff_size, const char* num) {
    //calcTable(num);
    
    if (idx < v.size())
    {
        strncpy(buff, v.at(idx).c_str(), buff_size);
        buff[buff_size - 1] = '\0';
        idx++;
        return true;
    }
    /*while (getItem(buff)) {
        cout << buff << endl;
    }*/
    return false;
}
extern "C" __declspec(dllexport) const char* fun_give_table_item2(char* buff, int buff_size, const char *num, int iter) {
    //calcTable(num);
    strncpy(buff, v.at(iter).c_str(), buff_size);
    //strncpy(buff, string(std::to_string(v.size())).c_str(), buff_size);
    buff[buff_size - 1] = '\0';
    return buff;
    /*while (getItem(buff)) {
        cout << buff << endl;
    }*/
}
extern "C" __declspec(dllexport) const char* fun_give_table(char* buff, int buff_size, const char* num) {
    //calcTable(num);
    string ans;
    while (idx < v.size())
    {
        ans+=v.at(idx);
        ans+='\n';
        idx++;
    }
    strncpy(buff, ans.c_str(), buff_size);
    buff[buff_size - 1] = '\0';
    
    return buff;
    /*while (getItem(buff)) {
        cout << buff << endl;
    }*/
}
extern "C" __declspec(dllexport) const char* fun_long_expression(char* buff, int buff_size, const char* num, const char* expression, const char* name) {
    TPostfix tre(expression);
    int pos = stoi(num);
    Polinom res = tre.Calculate(pos, A, B, C, D, E, F);
    A.Insert(name, res);
    B.Insert(name, res);
    C.Insert(name, res);
    D.Insert(name, res);
    E.Insert(name, res);
    F.Insert(name, res);
    string return_ans = res.GivePolinom();
    strncpy(buff, return_ans.c_str(), buff_size);
    buff[buff_size - 1] = '\0';
    return buff;
}
extern "C" __declspec(dllexport) const char* fun_pol1_znak_pol2(char* buff, int buff_size, const char* pol1, const char* pol2, const char* Znak) {
    Polinom Pol1(pol1);
    Polinom Pol2(pol2);
    Polinom ans;
    string return_ans = "";
    if (strcmp(Znak, "+") == 0) {
        ans = Pol1 + Pol2;
        return_ans = ans.GivePolinom();
    }
    else if (strcmp(Znak, "-") == 0) {
        ans = Pol1 - Pol2;
        return_ans = ans.GivePolinom();
    }
    else if (strcmp(Znak, "*") == 0) {
        ans = Pol1 * Pol2;
        return_ans = ans.GivePolinom();
    }
    /*if (strcmp(Znak, "/") == 0) {
        ans = Pol1 / Pol2;
        return_ans = ans.GivePolinom();
    }*/
    strncpy(buff, return_ans.c_str(), buff_size);
    buff[buff_size - 1] = '\0';
    return buff;
}
extern "C" __declspec(dllexport) const char* fun_pol_in_point(char* buff, int buff_size, const char* pol1, const char* x, const char* y, const char* z) {

    double X, Y, Z;
    X = stod(x);
    Y = stod(y);
    Z = stod(z);
    Polinom Pol(pol1);
    string return_ans = to_string(Pol.Point(X, Y, Z));
    strncpy(buff, return_ans.c_str(), buff_size);
    buff[buff_size - 1] = '\0';
    return buff;
}
extern "C" __declspec(dllexport) const char* fun_pol_mul_const(char* buff, int buff_size, const char* pol1, const char* constant) {
    double Const;
    Const = stod(constant);
    Polinom Pol(pol1);
    Polinom ans;
    ans = Pol * Const;
    string return_ans = ans.GivePolinom();
    strncpy(buff, return_ans.c_str(), buff_size);
    buff[buff_size - 1] = '\0';
    return buff;
}
#endif // Project
