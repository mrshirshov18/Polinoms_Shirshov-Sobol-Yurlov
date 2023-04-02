#include "Polinom.h"

bool Polinom::isNumber(char c) {
    return '0' <= c && c <= '9';
}
bool Polinom::isSign(char c) {
    return c == '-' || c == '+';
}
bool Polinom::isPoint(char c) {
    return c == '.';
}
bool Polinom::isX(char c) {
    return c == 'X';
}
bool Polinom::isY(char c) {
    return c == 'Y';
}
bool Polinom::isZ(char c) {
    return c == 'Z';
}
bool Polinom::isdegree(char c) {
    return c == '^';
}
bool Polinom::isequal(char c) {
    return c == '=';
}

Polinom::Polinom() {
    input_expression = "0=pol";
    Name = "pol";
    Parse();
    Monoms();
}
Polinom::Polinom(string input, string name) {
    input_expression = input + "=" + name;
    Name = name;
    Parse();
    Monoms();
}
Polinom Polinom:: operator=(Polinom second) {
    input_expression = second.input_expression;
    infix = second.infix;
    pol = second.pol;
    Name = second.name;
    return *this;
}
void Polinom::Parse() {
    //lexemType type = nothing;
    int state = 0; //состояние автомата
    int left = 0; //левая граница лексемы
    int number_of_points = 0; //количество точек в числе( не больше одной)
    for (int i = 0; i < input_expression.size(); i++) {
        char c = input_expression[i];
        if (c == ' ') {
            left++;
            continue;
        }
        switch (state) {
        case(0):
            if (isSign(c)) {
                infix.emplace_back(sign, input_expression.substr(left, 1));
                left = i + 1;
                state = 0;
            }
            else if (isX(c)) {
                infix.emplace_back(X, input_expression.substr(left, 1));
                left = i + 1;
                state = 0;
            }
            else if (isY(c)) {
                infix.emplace_back(Y, input_expression.substr(left, 1));
                left = i + 1;
                state = 0;
            }
            else if (isZ(c)) {
                infix.emplace_back(Z, input_expression.substr(left, 1));
                left = i + 1;
                state = 0;
            }
            else if (isdegree(c)) {
                infix.emplace_back(degree, input_expression.substr(left, 1));
                left = i + 1;
                state = 0;
            }
            else if (isNumber(c)) {
                state = 1;
            }
            else if (isequal(c)) {
                infix.emplace_back(equal, input_expression.substr(left, 1));
                state = 2;
                left = i + 1;
            }
            else
                throw invalid_argument("Invalid expression");
            break;

        case(1):
            if (isSign(c)) {
                infix.emplace_back(number, input_expression.substr(left, i - left));
                infix.emplace_back(sign, input_expression.substr(i, 1));
                number_of_points = 0;
                left = i + 1;
                state = 0;
            }
            else if (isX(c)) {
                infix.emplace_back(number, input_expression.substr(left, i - left));
                infix.emplace_back(X, input_expression.substr(i, 1));
                number_of_points = 0;
                left = i + 1;
                state = 0;
            }
            else if (isY(c)) {
                infix.emplace_back(number, input_expression.substr(left, i - left));
                infix.emplace_back(Y, input_expression.substr(i, 1));
                number_of_points = 0;
                left = i + 1;
                state = 0;
            }
            else if (isZ(c)) {
                infix.emplace_back(number, input_expression.substr(left, i - left));
                infix.emplace_back(Z, input_expression.substr(i, 1));
                number_of_points = 0;
                left = i + 1;
                state = 0;
            }
            else if (isdegree(c)) {
                infix.emplace_back(number, input_expression.substr(left, i - left));
                infix.emplace_back(degree, input_expression.substr(i, 1));
                number_of_points = 0;
                left = i + 1;
                state = 0;
            }
            else if (isNumber(c)) {
                //left = i+1;
                state = 1;
            }
            else if (isPoint(c)) {
                if (number_of_points >= 1)
                    throw invalid_argument("Invalid expression");
                number_of_points = 1;
                state = 1;
            }
            else if (isequal(c)) {
                infix.emplace_back(number, input_expression.substr(left, i - left));
                infix.emplace_back(equal, input_expression.substr(i, 1));
                state = 2;
            }
            else
                throw invalid_argument("Invalid expression");
            break;

        case(2):
            infix.emplace_back(name, input_expression.substr(i, input_expression.size()));
            i = input_expression.size();
            break;
        }

    }
}
void Polinom::Monoms() {
    int state = 0; //состояние автомата
    Monom build;
    for (auto& item : infix) {
        int type = item.first;
        switch (state) {
        case(0):
            if (type == sign) {
                if (item.second == "-")
                    build.sign = -1;
                state = 1;
            }
            else if (type == X) {
                //int a=stoi(item.second);
                build.degree += P * P;
                state = 3;
            }
            else if (type == Y) {
                //int a=stoi(item.second);
                build.degree += P;
                state = 6;
            }
            else if (type == Z) {
                //int a=stoi(item.second);
                build.degree += 1;
                state = 9;
            }
            else if (type == number) {
                build.number = stod(item.second);
                state = 2;
            }
            else
                throw invalid_argument("Invalid expression");
            break;
        case(1):
            if (type == X) {
                //int a=stoi(item.second);
                build.degree += P * P;
                state = 3;
            }
            else if (type == Y) {
                //int a=stoi(item.second);
                build.degree += P;
                state = 6;
            }
            else if (type == Z) {
                //int a=stoi(item.second);
                build.degree += 1;
                state = 9;
            }
            else if (type == number) {
                build.number = stod(item.second);
                state = 2;
            }
            else
                throw invalid_argument("Invalid expression");
            break;
        case(2):
            if (type == sign) {
                pol.push_back(build);
                build.sign = 1;
                build.number = 1;
                build.degree = 0;
                state = 1;
                if (item.second == "-")
                    build.sign = -1;
            }
            else if (type == X) {
                //int a=stoi(item.second);
                build.degree += P * P;
                state = 3;
            }
            else if (type == Y) {
                //int a=stoi(item.second);
                build.degree += P;
                state = 6;
            }
            else if (type == Z) {
                //int a=stoi(item.second);
                build.degree += 1;
                state = 9;
            }
            else if (type == equal) {
                state = 12;
                pol.push_back(build);
                build.sign = 1;
                build.number = 1;
                build.degree = 0;
            }
            else
                throw invalid_argument("Invalid expression");
            break;
        case(3):
            if (type == sign) {
                pol.push_back(build);
                build.sign = 1;
                build.number = 1;
                build.degree = 0;
                if (item.second == "-")
                    build.sign = -1;
                state = 1;
            }
            else if (type == equal) {
                state = 12;
                pol.push_back(build);
                build.sign = 1;
                build.number = 1;
                build.degree = 0;
            }
            else if (type == degree) {
                state = 4;
            }
            else if (type == Y) {
                state = 6;
                build.degree += P;
            }
            else if (type == Z) {
                state = 9;
                build.degree += 1;
            }
            else
                throw invalid_argument("Invalid expression");
            break;
        case(4):
            if (type == number) {
                build.degree += ((stoi(item.second) - 1) * P * P);
                state = 5;
            }
            else
                throw invalid_argument("Invalid expression");
            break;
        case(5):
            if (type == sign) {
                pol.push_back(build);
                build.sign = 1;
                build.number = 1;
                build.degree = 0;
                if (item.second == "-")
                    build.sign = -1;
                state = 1;
            }
            else if (type == equal) {
                state = 12;
                pol.push_back(build);
                build.sign = 1;
                build.number = 1;
                build.degree = 0;
            }
            else if (type == Y) {
                state = 6;
                build.degree += P;
            }
            else if (type == Z) {
                state = 9;
                build.degree += 1;
            }
            else
                throw invalid_argument("Invalid expression");
            break;
        case(6):
            if (type == sign) {
                pol.push_back(build);
                build.sign = 1;
                build.number = 1;
                build.degree = 0;
                if (item.second == "-")
                    build.sign = -1;
                state = 1;
            }
            else if (type == equal) {
                state = 12;
                pol.push_back(build);
                build.sign = 1;
                build.number = 1;
                build.degree = 0;
            }
            else if (type == degree) {
                state = 7;
            }
            else if (type == Z) {
                state = 9;
                build.degree += 1;
            }
            else
                throw invalid_argument("Invalid expression");
            break;
        case(7):
            if (type == number) {
                build.degree += ((stoi(item.second) - 1) * P);
                state = 8;
            }
            else
                throw invalid_argument("Invalid expression");
            break;
        case(8):
            if (type == sign) {
                pol.push_back(build);
                build.sign = 1;
                build.number = 1;
                build.degree = 0;
                if (item.second == "-")
                    build.sign = -1;
                state = 1;
            }
            else if (type == equal) {
                state = 12;
                pol.push_back(build);
                build.sign = 1;
                build.number = 1;
                build.degree = 0;
            }
            else if (type == Z) {
                state = 9;
                build.degree += 1;
            }
            else
                throw invalid_argument("Invalid expression");
            break;
        case(9):
            if (type == sign) {
                pol.push_back(build);
                build.sign = 1;
                build.number = 1;
                build.degree = 0;
                if (item.second == "-")
                    build.sign = -1;
                state = 1;
            }
            else if (type == equal) {
                state = 12;
                pol.push_back(build);
                build.sign = 1;
                build.number = 1;
                build.degree = 0;
            }
            else if (type == degree) {
                state = 10;
            }
            else
                throw invalid_argument("Invalid expression");
            break;
        case(10):
            if (type == number) {
                build.degree += ((stoi(item.second) - 1));
                state = 11;
            }
            else
                throw invalid_argument("Invalid expression");
            break;
        case(11):
            if (type == sign) {
                pol.push_back(build);
                build.sign = 1;
                build.number = 1;
                build.degree = 0;
                if (item.second == "-")
                    build.sign = -1;
                state = 1;
            }
            else if (type == equal) {
                state = 12;
                pol.push_back(build);
                build.sign = 1;
                build.number = 1;
                build.degree = 0;
            }
            else
                throw invalid_argument("Invalid expression");
            break;
        case(12):
            if (type == name) {
                Name = item.second;
            }
            else
                throw invalid_argument("Invalid expression");
            break;
        }

    }
}
void Polinom::Print() {
    for (auto& item : pol) {
        if (item.sign == -1)
            cout << "-";
        else
            cout << "+";
        cout << item.number << "X^" << item.degree / (P * P) << "Y^" << (item.degree % (P * P)) / P << "z^" << item.degree % P;
    }

    return;
}
string Polinom::GivePolinom() {
    string ans{};
    for (auto& item : pol) {
        if (item.sign == -1)
            ans += "-";
        else
            ans += "+";
        ans += (to_string(item.number) + "X^" + to_string(item.degree / (P * P)) + "Y^"
            + to_string((item.degree % (P * P)) / P) + "z^" + to_string(item.degree % P));
    }
    return ans;
}
double Polinom::Point(double x, double y, double z) {
    double ans = 0;
    for (auto& monom : pol) {
        double pointXYZ = pow(x, monom.degree / (P * P)) * pow(y, (monom.degree % (P * P)) / P) * pow(z, monom.degree % P);
        ans += monom.number * monom.sign * pointXYZ;
    }
    return ans;
}
Polinom Polinom::operator*(double n) {
    if (n == 0) {
        Polinom ans("0");
        return ans;
    }
    Polinom ans = *this;
    int flag = 0;
    if (n < 0) {
        flag = -1;
    }
    else
        flag = 1;
    for (auto& monom : ans.pol) {
        monom.number *= n * flag;
        monom.sign *= flag;
    }
    return ans;
}
Polinom Polinom::operator+(double n) {
    Polinom ans = *this;
    string a = to_string(n);
    string b = a;
    Polinom second(b);
    return ans + second;
}
Polinom Polinom::operator-(double n) {
    Polinom ans = *this;
    string a = to_string(n);
    string b = a;
    Polinom second(b);
    return ans - second;
}
void Polinom::sort() {
}
Polinom Polinom::operator+(Polinom second) {
    Polinom ans("0");
    ans.pol.pop_back();
    for (auto& elem1 : pol) {
        int num = 0;
        int flag = 0;
        for (auto& elem2 : second.pol) {
            if (elem1.degree == elem2.degree) {
                num += (elem1.number * elem1.sign + elem2.number * elem2.sign);
                flag = 1;
            }

        }
        if (flag == 0) {
            ans.pol.push_back(elem1);
        }
        if (num != 0) {
            Monom a;
            if (num < 0) {
                num = -num;
                int sign = -1;
            }
            a.sign = elem1.sign;
            a.degree = elem1.degree;
            a.number = num;
            ans.pol.push_back(a);
        }
    }
    for (auto& elem1 : second.pol) {
        int flag = 0;
        for (auto& elem2 : pol) {
            if (elem1.degree == elem2.degree) {
                flag = 1;
            }

        }
        if (flag == 0) {
            ans.pol.push_back(elem1);
        }
    }
    return ans;
}
Polinom Polinom::operator-(Polinom second) {
    return *(this) + second * (-1);
}
Polinom Polinom::operator*(Polinom second) {
    Polinom ans("0");
    ans.pol.pop_back();
    Polinom Ans("0");
    Ans.pol.pop_back();
    for (auto& elem1 : pol) {
        for (auto& elem2 : second.pol) {
            Monom temp;
            temp.sign=elem1.sign*elem2.sign;
            temp.degree= elem1.degree + elem2.degree; //не работает если p не 10!!!!
            temp.number= elem1.number * elem2.number;
            Polinom tmp("0");
            tmp.pol.pop_back();
            tmp.pol.push_back(temp);
            Ans=ans+tmp;
            ans=Ans;
        }
    }
    return Ans;
}