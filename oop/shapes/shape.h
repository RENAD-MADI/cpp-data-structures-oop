
#pragma once

#include <iostream>
#include <cmath>
#include <string>
#include <numbers>
using namespace std;


class Shape
{
public:
    // Shapes are deleted through Shape* in main, so the destructor must be virtual.
    virtual ~Shape() = default;

    void printArea()
    {
        cout << "area = " << area << endl;
    }

    void printPerimeter()
    {
        cout << "perimeter = " << perimeter << endl;
    }

    virtual void computeArea() = 0;
    virtual void computePerimeter() = 0;
    virtual string toString() const = 0;

protected:
    double area;
    double perimeter;
};

class Square : public Shape
{
public:
    Square(double side_i = 0)
    {
        side = side_i;
    }

    void computeArea() override
    {
        area = side * side;
    }

    void computePerimeter() override
    {
        perimeter = 4 * side;
    }

    string toString() const override
    {
        return "Square: side = " + to_string(side);
    }

private:
    double side = 0;
};

class Rectangle : public Shape
{
public:
    Rectangle(double width_i = 0, double height_i = 0)
    {
        width = width_i;
        height = height_i;
    }

    void computeArea() override
    {
        area = width * height;
    }

    void computePerimeter() override
    {
        perimeter = 2 * (width + height);
    }

    string toString() const override
    {
        return "Rectangle: width = " + to_string(width) +
               " height = " + to_string(height);
    }

private:
    double width = 0, height = 0;
};

class Circle : public Shape
{
public:
    Circle(double radius_i = 0)
    {
        radius = radius_i;
    }

    void computeArea() override
    {
        area = numbers::pi * radius * radius;
    }

    void computePerimeter() override
    {
        perimeter = 2 * numbers::pi * radius;
    }

    string toString() const override
    {
        return "Circle: radius = " + to_string(radius);
    }

private:
    double radius = 0;
};

class RightTriangle : public Shape
{
public:
    RightTriangle(double base_i = 0, double height_i = 0, double hypotenuse_i = 0)
    {
        base = base_i;
        height = height_i;
        hypotenuse = hypotenuse_i;
    }

    void computeArea() override
    {
        area = 0.5 * base * height;
    }

    void computePerimeter() override
    {
        perimeter = base + height + hypotenuse;
    }

    string toString() const override
    {
        return "RightTriangle: base = " + to_string(base) +
               " height = " + to_string(height) +
               " hypotenuse = " + to_string(hypotenuse);
    }

private:
    double base = 0, height = 0, hypotenuse = 0;
};

