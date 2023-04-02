
#include "postfix.h"
#include "NoSortedTable1.h"

bool TPostfix::isNumber(char c) {
    return '0' <= c && c <= '9';
}
bool TPostfix::isLetter(char c) {
    return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z' || c == '_';
}
bool TPostfix::isOperation(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
bool TPostfix::isMinus(char c) {
    return c == '-';
}
bool TPostfix::isOperator_open(char c) {
    return c == '(';
}
bool TPostfix::isOperator_close(char c) {
    return c == ')';
}
bool TPostfix::isPoint(char c) {
    return c == '.';
}


void TPostfix::Parse() {
    lexemType type = nothing;
    int brackets = 0;// open++, close--
    int left = 0;//левая граница лексемы, i-будет свегда правой границей
    for (int i = 0; i < input_expression.size(); i++) {
        char c = input_expression[i];
        if (c == ' ')
            continue;
        switch (type) {
        case (nothing):
            // начало выражения
            if (isOperator_open(c)) {
                left = i;
                type = operator_open;
            }
            else if (isNumber(c) || isPoint(c) || isMinus(c)) {
                left = i;
                type = number;
            }
            else if (isLetter(c)) {
                left = i;
                type = variable;
            }

            else {
                throw invalid_argument("Invalid expression");
            }
            break;
        case (number):
            if ((isPoint(c)) & (isPoint(input_expression[i - 1])))//две точки подряд нельзя
                throw invalid_argument("Invalid expression");
            if ((isPoint(c) & (!isMinus(input_expression[i - 1]))) || isNumber(c))
                continue;//всё ещё число
            infix.emplace_back(number, input_expression.substr(left, i - left));// добавили
            if (isOperator_close(c)) {
                left = i;
                type = operator_close;
            }
            else if (isOperation(c)) {
                left = i;
                type = operation;
            }
            else {
                throw invalid_argument("Invalid expression");
            }
            break;
        case (variable):
            if (isLetter(c) || isNumber(c))
                continue;
            infix.emplace_back(variable, input_expression.substr(left, i - left));
            operands.insert({ input_expression.substr(left,i - left), T() });
            if (isOperator_close(c)) {
                left = i;
                type = operator_close;
            }
            else if (isOperation(c)) {
                left = i;
                type = operation;
            }
            else {
                throw invalid_argument("Invalid expression");
            }
            break;
        case (operation):
            infix.emplace_back(operation, input_expression.substr(left, i - left));
            if (isOperator_open(c)) {
                left = i;
                type = operator_open;
            }
            else if (isNumber(c) || isPoint(c)) {
                left = i;
                type = number;
            }
            else if (isLetter(c)) {
                left = i;
                type = variable;
            }
            else {
                throw invalid_argument("Invalid expression");
            }
            break;
        case (operator_open):
            brackets++;
            infix.emplace_back(operator_open, input_expression.substr(left, i - left));
            if (isOperator_open(c)) {
                left = i;
                type = operator_open;
            }
            else if (isNumber(c) || isPoint(c) || isMinus(c)) {
                left = i;
                type = number;
            }
            else if (isLetter(c)) {
                left = i;
                type = variable;
            }
            else {
                throw invalid_argument("Invalid expression");
            }
            break;
        case (operator_close):
            brackets--;
            infix.emplace_back(operator_close, input_expression.substr(left, i - left));
            if (isOperator_close(c)) {
                left = i;
                type = operator_close;
            }
            else if (isOperation(c)) {
                left = i;
                type = operation;
            }
            else {
                throw invalid_argument("Invalid expression");
            }
            break;
        }
    }
    infix.emplace_back(type, input_expression.substr(left, input_expression.size() - left));//последняя лексема
    if (type == variable)
        operands.insert({ input_expression.substr(left,input_expression.size() - left), T() });
    if (type == operator_close)
        brackets--;
    if (type == operator_open)
        brackets++;

    if (brackets != 0)
        throw invalid_argument("Invalid expression: troubles with brackets");
    if ((type != operator_close && type != number && type != variable)) {
        throw invalid_argument("Invalid expression: invalid ending");
    }

}

void TPostfix::ToPostfix() {
    Parse();
    Stack<pair<lexemType, string>> st;
    pair<lexemType, string> stelem;
    for (auto& item : infix) {
        switch (item.first) {
        case operator_open:
            st.push(item);
            break;
        case operator_close:
            stelem = st.top();
            st.pop();
            while (stelem.first != operator_open) {
                postfix.emplace_back(stelem);
                stelem = st.top();
                st.pop();
            }
            break;
        case operation:
            while (!st.empty()) {
                stelem = st.top();
                st.pop();
                if (priority[item.second[0]] <= priority[stelem.second[0]])
                    postfix.emplace_back(stelem);
                else {
                    st.push(stelem);
                    break;
                }
            }
            st.push(item);
            break;
        default:
            postfix.emplace_back(item);
        }
    }
    while (!st.empty()) {
        stelem = st.top();
        st.pop();
        postfix.emplace_back(stelem);
    }
}

void TPostfix::GetValues(int n, NoSortedTable1 A, NoSortedTable2 B, SortedTable C, HashTable1 D, HashTable2 G, TreeTable E) {
    for (auto& op : operands) {
        //op.second=A.FindPol(op.first);
        switch(n){
        case(1):
            op.second = A.FindPol(op.first);
        break;
        case(2):
            op.second = B.FindPol(op.first);
        break;

        case 3:
            op.second = C.FindPol(op.first);
        break;
        case 4:
            op.second = D.FindPol(op.first);
        break;
        case 5:
            op.second = G.FindPol(op.first);
        break;
        case 6:
            op.second = E.FindPol(op.first);
        break;
        }
    }
}



