#include <iostream>
#include "Polinom.h"
#include "NoSortedTable1.h"
#include "NoSortedTable2.h"
#include "SortedTable.h"
#include "HashTable1.h"
#include "TreeTable.h"
#include "Postfix.h"

#define Project
#ifdef Project
NoSortedTable1 <string, Polinom> A;
NoSortedTable2  <string, Polinom> B;
SortedTable <string, Polinom>  C;
HashTable1  <string, Polinom> D;
HashTable2  <string, Polinom> E;
TreeTable <string, Polinom> F;
string f3(string num, string expression, string name) {
    TPostfix tre(expression);
    int pos=stoi(num);
    Polinom res = tre.Calculate(pos, A, B, C, D, E, F);
    switch (pos) {
        case 1:
            A.Insert(name,res);
            break;
        case 2:
            B.Insert(name, res);
            break;
        case 3:
            C.Insert(name, res);
            break;
        case 4:
            D.Insert(name, res);
            break;
        case 5:
            E.Insert(name, res);
            break;
        case 6:
            F.Insert(name, res);
            break;
    }
}
string f1(string pol1,string pol2,string Znak) {
    Polinom Pol1(pol1);
    Polinom Pol2(pol2);
    Polinom ans;
    if(Znak=="+"){
        ans=Pol1+Pol2;
        return ans.GivePolinom();
    }
    if (Znak == "-") {
        ans = Pol1 - Pol2;
        return ans.GivePolinom();
    }
    if (Znak == "*") {
        ans = Pol1 * Pol2;
        return ans.GivePolinom();
    }
    /*if (Znak == "/") {
        ans = Pol1 + Pol2;
        return ans.GivePolinom();
    }*/
}
string f2_in_point(string pol1,string x,string y,string z) {
    double X,Y,Z;
    X=stod(x);
    Y=stod(y);
    Z=stod(z);
    Polinom Pol(pol1);
    return to_string(Pol.Point(X,Y,Z));
}
string f2_const(string pol1, string constant) {
    double Const;
    Const=stod(constant);
    Polinom Pol(pol1);
    Polinom ans;
    ans = Pol*Const;
    return ans.GivePolinom();
}

int main() {
    
}
#endif // Project



#ifdef DEBUG
int main()
{
    Polinom a("-2XYZ-3XY+8X^2Z^3");
    Polinom b("XYZ+3XY+9X^2Z");
    NoSortedTable1 <string, Polinom> A;
    Polinom c = a + b;
    Polinom mult = a * b;
    cout << a.Point(1.0, 1.0, 1.0) << endl;
    a.Print(); cout << endl;
    b.Print(); cout << endl;
    c.Print(); cout << endl;
    Polinom f = a * 3;
    Polinom f2 = a * (-3);
    cout << "f=   ";
    f.Print();
    f = a + 2.1;
    cout << "f4=   ";
    f.Print();
    f = a - 2.1;
    cout << "f5=   ";
    f.Print();
    cout << endl;
    cout << "f2=   ";
    f2.Print();
    cout << endl;
    Polinom d = a - b;
    d.Print(); cout << endl;
    cout << "mult=   ";
    mult.Print();
    cout << endl;

    A.Insert("a", a);
    A.Insert("b", b);
    A.Insert("c", c);
    A.Insert("c", c);
    A.Delete("b");
    A.Print();
    Polinom* pa = A.Find("a");
    pa->Print();
    cout << endl;


    cout << "Table";
    cout << endl;
    vector<string> temp = A.GiveTable();
    for (auto& elem : temp) {
        cout << elem;
    }
    cout << "end of Table";
    cout << endl;


    NoSortedTable2  <string, Polinom> B;
    B.Insert("a", a);
    B.Insert("b", b);
    B.Insert("c", c);
    B.Insert("c", c);
    B.Delete("b");
    B.Print();
    Polinom* pb = B.Find("a");
    pb->Print();
    cout << endl;
    cout << endl;




    SortedTable <string, Polinom>  C;
    C.Insert("a", a);
    C.Insert("b", b);
    C.Insert("c", c);
    C.Insert("c", c);
    C.Delete("b");
    C.Print();
    Polinom* pc = C.Find("a");
    pc->Print();
    cout << endl;
    cout << endl;


    HashTable1  <string, Polinom> D;
    D.Insert("a", a);
    D.Insert("a", a);
    D.Insert("b", b);
    D.Insert("c", c);
    D.Insert("c", c);
    D.Delete("b");
    D.Print();
    Polinom* pd = D.Find("a");
    pd->Print();
    //cout<<pd->GetInfix();
    cout << endl;
    cout << endl;
    cout << endl << "Tree";
    cout << endl;


    TreeTable <string, Polinom> E;
    E.Insert("a", a);
    E.Insert("b", b);
    E.Insert("c", c);
    E.Insert("c", c);
    E.Delete("b");
    E.Delete("c");
    E.Print();
    Polinom* pe = E.Find("a");
    pe->Print();

    HashTable2  <string, Polinom> G;
    G.Insert("a", a);
    G.Insert("a", a);
    G.Insert("b", b);
    G.Insert("c", c);
    G.Insert("c", c);
    G.Delete("b");


    cout << endl;
    TPostfix tre("a+c+1");
    Polinom res = tre.Calculate(1, A, B, C, D, G, E);
    cout << "res = ";
    res.Print();
    cout << endl;
    TPostfix tfgdf("a*a+c+1");
    Polinom res2 = tfgdf.Calculate(1, A, B, C, D, G, E);
    cout << "res = ";
    res2.Print();
}
#endif // DEBUG


