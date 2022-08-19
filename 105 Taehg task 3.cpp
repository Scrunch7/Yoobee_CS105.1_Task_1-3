#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const double pi = 3.141;
int select = 0;
enum { SQUARE = 1, RECTANGLE, TRIANGLE, CIRCLE, EXIT };
void menu();

//parent class
class Shapes {

	double calc_result, height, width, radius;

public:

	Shapes() {
		calc_result = height = width = radius = 0;
	}

	double calculatePerimeter(double height, double width) {
		double result = 0;
		result = height * 2 + width * 2;
		setResult(result);
		return result;
	}

	//overloaded function for rectangles and squares
	double calculateArea(double height, double width) {
		double result = 0;
		result = height * width;
		setResult(result);
		return result;
	}

	//circle with overloading
	double calculateArea(double radius) {
		double result = 0;
		result = pi * (radius * radius);
		setResult(result);
		return result;
	}

	void giveResult() {
		cout << calc_result;
	}

	double getData() {
		double input = 0;
		cin >> input;
		return input;
	}

	void setResult(double input) {
		calc_result = input;
	}
};


//derived classes
class Square : public Shapes {
public:

	void drawShape() {
		for (int i = 0; i < 5; i++) { //rows
			for (int j = 0; j < 5; j++) { //columns
				cout << " *";
			}

			cout << endl;
		}
	}
};

class Rectangle : public Shapes {
public:

	void drawShape() {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 10; j++) {
				cout << " *";
			}

			cout << endl;
		}
	}
};

class Triangle : public Shapes {
public:

	void drawShape() {
		int shapeWidth = 1;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < shapeWidth; j++) {
				cout << " *";

			}

			//cuts square in half diagonally 
			shapeWidth++;
			cout << endl;
		}
	}

	//right angle triangle
	double calculateArea(double height, double width) {
		double result = 0;
		result = (height * width) / 2;
		setResult(result);
		return result;
	}

	//calculating the parameter
	double calculatePerimeter(double height, double width) {
		double result, hypotenuse = 0;
		hypotenuse = (height * height) + (width * width);
		hypotenuse = sqrt(hypotenuse);
		result = height + width + hypotenuse;
		setResult(result);
		return result;
	}
};

class Circle : public Shapes {
public:
	void drawShape() {
		cout << "           ******    \n";
		cout << "         **********  \n";
		cout << "       **************\n";
		cout << "       **************\n";
		cout << "       **************\n";
		cout << "         **********  \n";
		cout << "           ******    ";
	}
	double calculatePerimeter(double radius) {
		double result = 0;
		result = 2 * pi * radius;
		setResult(result);
		return result;
	}
};



void area() {
	double height, width, radius = 0;
	Square square;
	Rectangle rectangle;
	Circle circle;
	Triangle triangle;

	switch (select) {

	case SQUARE:
		cout << "Please enter the side of the square in centimeters: ";
		width = square.getData();
		square.calculateArea(width, width); //squares are equal, only one value needed
		cout << "\nThe result is: ";
		square.giveResult();
		cout << " square centimeters (sq.cm)\n";
		break;

	case RECTANGLE:
		cout << "Please enter the height of the rectangle in centimeters: ";
		height = rectangle.getData();
		cout << "Please enter the base of the rectangle in centimeters: ";
		width = rectangle.getData();
		rectangle.calculateArea(height, width);
		cout << "\nThe result is: ";
		rectangle.giveResult();
		cout << " square centimeters (sq.cm)\n";
		break;

	case CIRCLE:
		cout << "Please enter the radius of the circle in centimeters: ";
		radius = circle.getData();
		circle.calculateArea(radius);
		cout << "\nThe result is: ";
		circle.giveResult();
		cout << " square centimeters (sq.cm)\n"; 
		break;

	case TRIANGLE:
		cout << "Please enter the height of the triangle in centimeters: ";
		height = triangle.getData();
		cout << "Please enter the width of the triangle in centimeters: ";
		width = triangle.getData();
		triangle.calculateArea(height, width);
		cout << "\nThe result is: ";
		triangle.giveResult();
		cout << " square centimeters (sq.cm)\n";
		break;
	}
	cout << endl;
}

void perimeter() {
	double height, width, radius = 0;
	Square square;
	Rectangle rectangle;
	Circle circle;
	Triangle triangle;

	switch (select) {

	case SQUARE:
		cout << "Please enter the side of the square in centimeters: ";
		width = square.getData();
		square.calculatePerimeter(width, width); //squares are equal, only one value needed
		cout << "\nThe result is: ";
		square.giveResult();
		cout << "cm\n";
		break;

	case RECTANGLE:
		cout << "Please enter the height of the rectangle in centimeters: ";
		height = rectangle.getData();
		cout << "Please enter the base of the rectangle in centimeters: ";
		width = rectangle.getData();
		rectangle.calculatePerimeter(height, width);
		cout << "\nThe result is: ";
		rectangle.giveResult();
		cout << "cm\n";
		break;

	case CIRCLE:
		cout << "Please enter the radius of the circle in centimeters: ";
		radius = circle.getData();
		circle.calculatePerimeter(radius);
		cout << "\nThe result is: ";
		circle.giveResult();
		cout << "cm\n";
		break;

	case TRIANGLE:
		cout << "Please enter the height of the triangle in centimeters: ";
		height = triangle.getData();
		cout << "Please enter the width of the triangle in centimeters: ";
		width = triangle.getData();
		triangle.calculatePerimeter(height, width);
		cout << "\nThe result is: ";
		triangle.giveResult();
		cout << "cm\n";
		break;

	}
	cout << endl;
}

void display() {
	Square square;
	Rectangle rectangle;
	Triangle triangle;
	Circle circle;

	switch (select) {

	case SQUARE:
		cout << "*******************\nSquare Calculator\n\n*******************\n\n";
		square.drawShape();
		cout << endl;
		break;

	case RECTANGLE:
		cout << "*******************\nRectangle Calculator\n\n*******************\n\n";
		rectangle.drawShape();
		cout << endl;
		break;

	case TRIANGLE:
		cout << "*******************\nTriangle Calculator\n\n*******************\n\n";
		triangle.drawShape();
		cout << endl;
		break;

	case CIRCLE:
		cout << "*******************\nCircle Calculator\n\n*******************\n\n";
		circle.drawShape();
		cout << endl;
		break;
	}
}

void menu2() {
	int select;
	display();
	cout << "What would you like to calculate?\n";
	cout << "	1. Area (Area = base * base sq.units)\n	2. Perimeter (Perimeter = 4 * base sq.units)\n	3. Return to main menu (Shapes Calculater)\n";
	cin >> select;

	switch (select) {

	case 1:
		area();
		menu2();
		break;

	case 2:
		perimeter();
		menu2();
		break;

	case 3:
		menu();
		break;

	default:
		cout << "Not an option\n";
		menu2();
		break;
	}
}

void menu() {

	cout << "*******************\nShapes Calculator\n\n*******************\n";
	cout << "PLease choose an option between 1 and 5: ";
	cout << "\n	1. Square\n	2. Rectangle\n	3. Triangle\n	4. Circle\n	5. Exit\n";
	cin >> select;

	if (select > 0 && select < 5) {
		menu2();
	}
	else if (select == 5) {
	}
	else {
		cout << "Invalid selection.\n";
		menu();
	}
}


int main() {
	Square square;
	Rectangle rectangle;
	Circle circle;
	Triangle triangle;

	while (select != 5) {
		menu();
	}

	return 0;
}