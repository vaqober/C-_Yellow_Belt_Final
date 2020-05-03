#include <vector>
#include <memory>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdint>
#include <cmath>

using namespace std;

class Figure {
public:
    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Triangle : public Figure {
public:
    Triangle(int a, int b, int c) : a_(a), b_(b), c_(c) {

    }

    string Name() const override {
        return name;
    }

    double Perimeter() const override {
        return a_ + b_ + c_;
    }

    double Area() const override {
        double p = Perimeter() / 2.0;
        return sqrt(p * (p - a_) * (p - b_) * (p - c_));
    }

private:
    int a_, b_, c_;
    const string name = "TRIANGLE";
};

class Rect : public Figure {
public:
    Rect(double width, double height) : width_(width), height_(height) {

    }

    string Name() const override {
        return name;
    }

    double Perimeter() const override {
        return 2 * (width_ + height_);
    }

    double Area() const override {
        return width_ * height_;
    }

private:
    double width_, height_;
    const string name = "RECT";
};

class Circle : public Figure {
public:
    Circle(double r) : r_(r) {

    }

    string Name() const override {
        return name;
    }

    double Perimeter() const override {
        return 2 * pi_ * r_;
    }

    double Area() const override {
        return pi_ * r_ * r_;
    }

private:
    double r_;
    const double pi_ = 3.14;
    const string name = "CIRCLE";
};

shared_ptr<Figure> CreateFigure(istream& iss) {
    string name;
    iss >> name;
    if (name == "TRIANGLE") {
        int a, b, c;
        iss >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    }
    else if (name == "RECT") {
        int width, height;
        iss >> width >> height;
        return make_shared<Rect>(width, height);
    }
    else if (name == "CIRCLE") {
        int radius;
        iss >> radius;
        return make_shared<Circle>(radius);
    }
    
}


int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            figures.push_back(CreateFigure(is));
        }
        else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                    << current_figure->Name() << " "
                    << current_figure->Perimeter() << " "
                    << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}