#include <iostream>
#include <cmath>
using namespace std;

// template function to calculate area of rectangle
template <typename T>
T areaRectangle(T length, T width) { return length * width; }

// template function to calculate area of square
template <typename T>
T areaSquare(T side) { return side * side; }

// template function to calculate area of triangle
template <typename T>
T areaTriangle(T base, T height) { return 0.5 * (base * height); }

// template function to calculate area of circle
template <typename T>
T areaCircle(T radius) { return M_PI * (radius * radius); }

// function to check if value user enters if valid
template <typename T>
T isValid()
{
    T value;
    while (!(cin >> value) || value <= 0) {
                cout << "Invalid input. Please enter a number: ";
                cin.clear(); // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
    return value;
}

int main()
{
    char choice = 'y';
    string shape = "";
    double length = 0.0;
    double width = 0.0;
    double side = 0.0;
    double base = 0.0;
    double height = 0.0;
    double calculatedArea = 0.0;
    double radius = 0.0;
    // double roundedArea = 0.0;

    // Print welcome message
    cout << "Welcome to the Area Calculator!" << endl;

    // use while loop to repeat program
    while (choice == 'y' || choice == 'Y')
    {
        // ask user what shape they want to calculate the area for
        cout << "What shape do you want to calculate the area for (rectangle, square, triangle, circle)? ";
        cin >> shape;

        if (shape == "rectangle" || shape == "Rectangle") // calculate area of rectangle
        {
            cout << "What is the length of the rectangle? "; // find length of rectangle
            length = isValid<double>(); 
            cout << "What is the width of the rectangle? "; // find the width of the rectangle
            width = isValid<double>();

            calculatedArea = areaRectangle(length, width);
            // roundedArea = round(calculatedArea * 10) / 10; // round area to one decimal place
            // output area of rectangle
            cout << "The area of the rectangle is " << calculatedArea << "!" << endl;
        }
        else if (shape == "square" || shape == "Square") // calculate area of square
        {
            cout << "What is the of the side of the square? "; // find side of square
            side = isValid<double>();
            calculatedArea = areaSquare(side);
            // roundedArea = round(calculatedArea * 10) / 10; // round area to one decimal place
            // output area of square
            cout << "The area of the square is " << calculatedArea << "!" << endl;
        }
        else if (shape == "triangle" || shape == "Triangle") // calculate area of triangle
        {
            cout << "What is the base of the triangle? "; // find base of triangle
            base = isValid<double>();
            cout << "What is the height of the rectangle? "; // find height of triangle
            height = isValid<double>();
            calculatedArea = areaTriangle(base, height);
            // roundedArea = round(calculatedArea * 10) / 10; // round area to one decimal place
            // output area of triangle
            cout << "The area of the triangle is " << calculatedArea << "!" << endl;
        }
        else if (shape == "circle" || shape == "Circle") // calculate area of circle
        {
            cout << "What is the radius of the circle? "; // find radius of circle
            radius = isValid<double>();
            calculatedArea = areaCircle(radius);
            // output area of circle
            cout << "The area of the circle is " << calculatedArea << "!" << endl;
        }
        else
        {
            cout << "Please enter a valid shape ('rectangle', 'square', 'triangle', 'circle): \n";
            continue;
        }

        // ask user if they want to play again
        cout << "Do you want to play again? (y/n) ";
        cin >> choice;
    }

    // print thank you message
    cout << "Thank you for playing the Area Calculator!" << endl;

    return 0;
}