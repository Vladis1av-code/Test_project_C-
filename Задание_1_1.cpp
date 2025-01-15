#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class Equation {
public:
    // Віртуальна функція для знаходження коренів (буде реалізована в похідних класах)
    virtual vector<double> solve() const = 0;

    
    virtual void print() const = 0;

    
    Equation() = default;
};

class LinearEquation : public Equation {
private:
    double a; 
    double b; 

public:
    // Конструктор
    LinearEquation(double a_, double b_) : a(a_), b(b_) {}

   
    vector<double> solve() const override {
        vector<double> roots;
        if (a == 0) {
            
        }
        else {
            roots.push_back(-b / a);
        }
        return roots;
    }

   
    void print() const override {
        cout << a << "x" << (b >= 0 ? "+" : "") << b << " = 0" << endl;
    }
};

class QuadraticEquation : public Equation {
private:
    double a; // Коефицент при x^2
    double b; // Коефицент при x
    double c; // 

public:
    // Конструктор
    QuadraticEquation(double a_, double b_, double c_) : a(a_), b(b_), c(c_) {}

    // Функция для нахождение корней
    vector<double> solve() const override {
        vector<double> roots;
        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0) {
            
        }
        else if (discriminant == 0) {
            roots.push_back(-b / (2 * a)); // Один корень
        }
        else {
            double sqrtD = sqrt(discriminant);
            roots.push_back((-b + sqrtD) / (2 * a));
            roots.push_back((-b - sqrtD) / (2 * a)); 
        }
        return roots;
    }

    
    void print() const override {
        cout << a << "x^2" << (b >= 0 ? "+" : "") << b << "x" << (c >= 0 ? "+" : "") << c << " = 0" << endl;
    }
};
int main() {
    setlocale(LC_ALL, "ru");
    
    LinearEquation le(2, 3);
    QuadraticEquation qe(1, 4, 3);

    
    cout << "Уровень: ";
    le.print();
    cout << "Корень: ";
    for (double root : le.solve()) {
        cout << root << " ";
    }
    cout << endl;

    cout << "Квадратное решение: ";
    qe.print();
    cout << "Корень: ";
    for (double root : qe.solve()) {
        cout << root << " ";
    }
    cout << endl;

    return 0;
}
