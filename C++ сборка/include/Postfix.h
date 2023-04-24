#pragma once
#include<iostream>
#include <string>

#include <vector>
#include <map>
#include "Polinom.h"
#include "NoSortedTable1.h"
#include "NoSortedTable2.h"
#include "SortedTable.h"
#include "HashTable1.h"
#include "HashTable2.h"
#include "TreeTable.h"
#include "stack.h"
//#include <stack>
using namespace std;
typedef Polinom T;

class TPostfix
{
    string input_expression;
    enum lexemType {
        nothing,//начало выражения
        number, // 4; -4; .4; 
        variable, //переменная____ a;my_argument - right_____-a;a1 - wrong!
        operation, //+, -, *, /
        operator_open, // (
        operator_close // )
    };
    vector<pair<lexemType, string>> infix; //набор лексем со значениями
    vector<pair<lexemType, string>> postfix;
    //static 
    map<char, int> priority;
    map<string, T> operands; //набор переменных(variable) со значениями (по умолчанию в них нули)

    bool isNumber(char c);      // 0 ... 9
    bool isLetter(char c); // a ... z, A ... Z, _
    bool isOperation(char c);   // +, -, *, /
    bool isMinus(char c);       // -
    bool isPoint(char c);       // .
    bool isOperator_open(char c);       // (
    bool isOperator_close(char c);         // )

    void Parse(); //разложить на лексемы

    void GetValues(int n, NoSortedTable1<string, Polinom>, NoSortedTable2 <string,Polinom> , SortedTable<string, Polinom>,
    HashTable1<string, Polinom>,HashTable2<string, Polinom>,TreeTable<string, Polinom>);
public:
    void ToPostfix();//сделать обратную польскую запись для подсчета
    TPostfix(string _input_expression) :input_expression(_input_expression) {
        this->priority = { {'+',1},{'-',1},{'*',2},{'/',2} };
        if (input_expression.empty())
            throw invalid_argument("Creating arithmetic expression from an empty string");
        ToPostfix();
    }
    string GetInfix() { return input_expression; }

    string GetPostfix() {
        string ans;
        for (auto& i : postfix) {
            ans += ' ';
            ans += i.second;
        }
        return ans;
    }

    //Polinom Calculate(int n, NoSortedTable1 A, NoSortedTable2 B);// Ввод переменных, вычисление по постфиксной форме
    T Calculate(int n, NoSortedTable1<string, Polinom> A, NoSortedTable2 <string,Polinom> B, SortedTable <string, Polinom>C,
    HashTable1 <string, Polinom>D, HashTable2 <string, Polinom>G, TreeTable <string, Polinom>E) { // Ввод переменных, вычисление по постфиксной форме
        GetValues(n, A, B,C,D,G,E);
        Stack<Polinom> st;
        //T leftoperand();
        //T rightoperand();
        for (auto& lexem : postfix) {
            //switch (lexem.second[0]) 
            if (lexem.second[0] == '+') {
                T rightoperand = st.top();
                st.pop();
                T leftoperand = st.top();
                st.pop();
                st.push(leftoperand + rightoperand);
            }
            else if (lexem.second[0] == '-') {
                T rightoperand = st.top();
                st.pop();
                T leftoperand = st.top();
                st.pop();
                st.push(leftoperand - rightoperand);
            }
            else if (lexem.second[0] == '*'){
                T rightoperand = st.top();
                st.pop();
                T leftoperand = st.top();
                st.pop();
                st.push(leftoperand * rightoperand);
            }
            //case '/':
            //    rightoperand = st.top();
            //    st.pop();
            //    leftoperand = st.top();
            //    st.pop();
            //    st.push(leftoperand / rightoperand);
            //    break;
            else {
                if (lexem.first == variable)
                    st.push(operands[lexem.second]);
                else
                    st.push(T(lexem.second));
            }
        }
        return st.top();

    }
};


