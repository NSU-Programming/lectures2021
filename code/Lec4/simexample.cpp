#include <iostream>
#include <memory>

using namespace std;

class Expression {
 public:
    virtual double value() const = 0;
    virtual string str() const = 0;
};

class Value : public Expression {
    double m_value;
 public:
    Value(double v) : m_value(v) {}
    double value() const override {return m_value;}
    string str() const override { return to_string(m_value);}
};

using ExprPtr = unique_ptr<Expression>;
class UnaryExpression : public Expression {
    const string m_symbol;
 protected:
    ExprPtr m_expr;
 public:
    UnaryExpression(ExprPtr eptr, const string& sym) :
        m_expr(move(eptr)), m_symbol(sym) {}
    string str() const override {
        return m_symbol + "(" + m_expr->str() + ")";
    }
};

class BinaryExpression : public Expression {
    const string m_symbol;
 protected:
    ExprPtr m_lhs;
    ExprPtr m_rhs;
 public:
    BinaryExpression(ExprPtr lhs, ExprPtr rhs, const string& sym) :
        m_lhs(move(lhs)), m_rhs(move(rhs)), m_symbol(sym) {}
    string str() const override {
        return "(" + m_lhs->str() + ")" + m_symbol + "(" + m_rhs->str() + ")";
    }
};

class UnaryMinus : public UnaryExpression {
 public:
    UnaryMinus(ExprPtr eptr) : UnaryExpression(move(eptr), "-") {}
    double value() const {return -m_expr->value();}
};

class Plus : public BinaryExpression {
 public:
    Plus(ExprPtr lhs, ExprPtr rhs) : BinaryExpression(move(lhs), move(rhs), "+") {}
    double value() const {return m_lhs->value() + m_rhs->value();}
};

class Minus : public BinaryExpression {
 public:
    Minus(ExprPtr lhs, ExprPtr rhs) : BinaryExpression(move(lhs), move(rhs), "-") {}
    double value() const {return m_lhs->value() - m_rhs->value();}
};

void print_expr(const Expression& expr) {
    cout << expr.str() << '\n';
}

int main() {
    auto v1 = make_unique<Value>(9.);
    auto v2 = make_unique<Value>(15.);
    auto sum = make_unique<Plus>(move(v1), move(v2));
    auto v3 = make_unique<Value>(21.);
    auto dif = make_unique<Minus>(move(sum), move(v3));
    auto expr = make_unique<UnaryMinus>(move(dif));

    cout << expr->str() << " = " << expr->value() << endl;
    return 0;
}
