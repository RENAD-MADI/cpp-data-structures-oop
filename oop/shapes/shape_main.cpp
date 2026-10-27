#include <iostream>
#include <vector>
#include "shape.h"

using namespace std;

int main(void)
{
    const int size = 8;
    vector<Shape*> A(size);

    A[0] = new Square(5);
    A[1] = new Triangle(4, 2);
    A[2] = new Square(10);
    A[3] = new Triangle(8, 4);
    A[4] = nullptr;
    A[5] = new Circle(5);
    A[6] = new Rectangle(2, 4);

    for (int i = 0; i < size; i++)
    {
        cout << "i = " << i << ",  ";
        if (A[i] != nullptr)
        {
            A[i]->computeArea();
            A[i]->computePerimeter(); // New line to compute perimeter
            cout << "A[" << i << "] = ";
            cout << A[i]->toString() << endl;
            cout << "Area: ";
            A[i]->printArea();
            cout << "Perimeter: "; // New line to print perimeter
            A[i]->printPerimeter();
        }
        else
            cout << "area = NULL";
        cout << endl;
    }

    // Clean up memory
    for (int i = 0; i < size; i++)
    {
        delete A[i];
    }

    return 0;
}

