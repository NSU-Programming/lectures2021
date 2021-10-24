#include <memory>
#include <string>
#include <iostream>

using namespace std;

class Expression;
using ExpressionPtr = shared_ptr<Expression>;

class Expression {
 public:
    string as_string() const {
        return "Expression";
    }
};

class IntValue : public Expression {
    int m_value;
 public:
    IntValue(int v) : m_value(v) {}
    string as_string() const {
        return to_string(m_value);
    }
};

ostream& operator<<(ostream &os, const ExpressionPtr& eptr) {
    return os << eptr->as_string();
}

int main() {
    auto expr = make_shared<Expression>();
    ExpressionPtr val = make_shared<IntValue>(9);
    cout << expr << '\n' << val << endl;
    return 0;
}
