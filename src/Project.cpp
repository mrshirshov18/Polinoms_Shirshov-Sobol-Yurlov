//#include "Project.h"
//#define Project
//#ifdef Project
//NoSortedTable1 <string, Polinom> A;
//NoSortedTable2  <string, Polinom> B;
//SortedTable <string, Polinom>  C;
//HashTable1  <string, Polinom> D;
//HashTable2  <string, Polinom> E;
//TreeTable <string, Polinom> F;
//extern "C" __declspec(dllexport)string f3(string num, string expression, string name) {
//    TPostfix tre(expression);
//    int pos = stoi(num);
//    Polinom res = tre.Calculate(pos, A, B, C, D, E, F);
//    A.Insert(name, res);
//    B.Insert(name, res);
//    C.Insert(name, res);
//    D.Insert(name, res);
//    E.Insert(name, res);
//    F.Insert(name, res);
//    return (res.GivePolinom());
//}
//extern "C" __declspec(dllexport)string f1(string pol1, string pol2, string Znak) {
//    Polinom Pol1(pol1);
//    Polinom Pol2(pol2);
//    Polinom ans;
//    if (Znak == "+") {
//        ans = Pol1 + Pol2;
//        return ans.GivePolinom();
//    }
//    if (Znak == "-") {
//        ans = Pol1 - Pol2;
//        return ans.GivePolinom();
//    }
//    if (Znak == "*") {
//        ans = Pol1 * Pol2;
//        return ans.GivePolinom();
//    }
//    /*if (Znak == "/") {
//        ans = Pol1 + Pol2;
//        return ans.GivePolinom();
//    }*/
//}
//extern "C" __declspec(dllexport)string f2_in_point(string pol1, string x, string y, string z) {
//    double X, Y, Z;
//    X = stod(x);
//    Y = stod(y);
//    Z = stod(z);
//    Polinom Pol(pol1);
//    return to_string(Pol.Point(X, Y, Z));
//}
//string f2_const(string pol1, string constant) {
//    double Const;
//    Const = stod(constant);
//    Polinom Pol(pol1);
//    Polinom ans;
//    ans = Pol * Const;
//    return ans.GivePolinom();
//}
//
//int main() {
//
//}
//#endif // Project