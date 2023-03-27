#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

struct Monom {
    int sign=1;
    double number=1;
    int degree=0;
};
class Polinom
{
    int P=10; //MaxDegree
    string input_expression;
    string Name;
    enum lexemType {
        nothing,
        number,
        sign,
        degree,
        X,
        Y,
        Z,
        equal,
        name
    };
    vector<pair<lexemType, string>> infix;
    list<Monom> pol;
    
    Polinom operator=(Polinom);
    bool isNumber(char c);
    bool isSign(char c);
    bool isPoint(char c);
    bool isdegree(char c);
    bool isX(char c);
    bool isY(char c);
    bool isZ(char c);
    bool isequal(char c);
    void Parse(); //разложить на лексемы
    void Monoms(); //разложить на мономы
    void sort();
    
public:
    Polinom();
    Polinom(string input,string name="pol");
    string GetInfix() { return input_expression; }
    void Give_name(string name){ Name= name;}
    void Print();
    double Point(double x=1.0,double y=1.0,double z=1.0);
    Polinom operator*(double n);
    Polinom operator+(double n);
    Polinom operator-(double n);
    Polinom operator+(Polinom second);
    Polinom operator-(Polinom second);
    //Polinom operator*(Polinom second);
    //Polinom operator/(Polinom second);
};

