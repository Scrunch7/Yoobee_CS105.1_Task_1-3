// 105 Taehg Humphries task 1
#include <iostream>
#include <vector>

using std::cout;
using std::cin;

class Location {


public:
	int longDegrees;
	float longMinutes;
	char longDirection;

	int latDegrees;
	float latMinutes;
	char latDirection;


	void getpos() { // getting the input of the locations. using longitude and latitude
		cout << "\nEnter the location of the ship:\n";
		cout << "Input degrees between 0 and 180: ";
		cin >> longDegrees;
		cout << "Input minutes between 0 and 60: ";
		cin >> longMinutes;
		cout << "Input direction (N/S) : ";
		cin >> longDirection;
		cout << "Input degrees between 0 and 180: ";
		cin >> latDegrees;
		cout << "Input miutes between 0 and 60: ";
		cin >> latMinutes;
		cout << "Input direction (E/W) : ";
		cin >> latDirection;

		
	}
};

class Yacht {
	Location location;


public:
	int number;

	

	void get_pos() { //this stores the yachts posistions as an object
		location.getpos();
	};

	void display() {
		cout << "\nThe ship serial number is :" << number;

		cout << "\nand it's posistion is : " << location.latDegrees << "\xF8" << location.latMinutes << "'" << location.latDirection << " Latitude  " << location.longDegrees << "\xF8" << location.longMinutes << "'" << location.longDirection << " Longtitude";
	};

	Yacht(int num) {
		this->number = num;
	};

};



int main() {

	cout << "******************Ocean Race 2021-22******************\n\n";

	std::vector<Yacht*> Yachts;
	for (int i = 0; i < 3; i++) {
		cout << "\n*************************************";
		Yachts.push_back(new Yacht(i + 1));
		Yachts[i]->get_pos();

	}

	for (Yacht* yacht : Yachts) {
		yacht->display();
	}

}