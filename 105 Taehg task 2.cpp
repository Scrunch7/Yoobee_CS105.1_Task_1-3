#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

int pick;

void charPrint(); //required for charCreate

class Player {

	string name;
	Race race;
	int hitPoints;
	int magicPoints;

public:

	Player() { //default constructor
		name = "";
		race = HUMAN;
		hitPoints = 0;
		magicPoints = 0;
	}

	Player(string name, Race race, int hitPoints, int magicPoints) {

	}

	string getName() {
		return name;
	}


	Race getRace() { //returns race as enum
		return race;
	}

	string whatRace() { //returns race as string
		Race raceSel;
		raceSel = getRace();

		switch (raceSel) {
		case HUMAN:
			return "Human";
			break;
		case ELF:
			return "Elf";
			break;
		case DWARF:
			return "Dwarf";
			break;
		case ORC:
			return "Orc";
			break;
		case TROLL:
			return "Troll";
			break;
		}
	}

	int getHitPoints() {
		return hitPoints;
	}

	int getMagicPoints() {
		return magicPoints;
	}

	void setName(string input) {
		name = input;
	}

	void setRace(Race input) {
		race = input;
	}

	void setHitpoints(int input) {
		hitPoints = input;
	}

	void setMagicPoints(int input) {
		magicPoints = input;
	}

	string attack() {
		//default attack method before being set by child class
		return "No attack method defined yet!\n";
	}


};


//Derived attack function overrides
class Warrior : public Player {
public:
	string attack();
};

class Priest : public Player {
public:
	string attack();
};

class Mage : public Player {
public:
	string attack();
};


//declare a vector of each derived class
vector<Warrior> warrior;
vector<Priest> priest;
vector<Mage> mage;


Race raceSel() { //enum values are in the player.h

	cout << "What race do you want?\n";
	cout << "	1. Human!\n";
	cout << "	2. Elf!\n";
	cout << "	3. Dwarf!\n";
	cout << "	4. Orc!\n";
	cout << "	5. Troll!\n";
	cin >> pick;

	switch (pick) {
	case HUMAN:
		return HUMAN;
		break;
	case ELF:
		return ELF;
		break;
	case DWARF:
		return DWARF;
		break;
	case ORC:
		return ORC;
		break;
	case TROLL:
		return TROLL;
		break;
	default:
		cout << "Invalid selection.\n";
		raceSel();
		break;
	}
}

string nameSel() {
	string name;
	cout << "What would you like to name your character?";
	cin >> name;
	return name;
}


bool charCreate() {
	Warrior warriorTemp; //temp variables for each player class
	Priest priestTemp;
	Mage mageTemp;

	cout << "	\nCHARACTER CREATION\n";
	cout << "Which of the following would you like?\n";
	cout << "	1. Warrior!\n";
	cout << "	2. Priest!\n";
	cout << "	3. Mage!\n";
	cout << "	4. Finish crating player charatcer!\n";
	cin >> pick;

	switch (pick) {
	case WARRIOR:
		warriorTemp.setHitpoints(200); //different hitpoints and magicpoints depending on player class selected
		warriorTemp.setMagicPoints(0);
		warriorTemp.setRace(raceSel());
		warriorTemp.setName(nameSel());
		warrior.push_back(warriorTemp); //appends new values onto the vector
		return true;
		break;
	case PRIEST:
		priestTemp.setHitpoints(100);
		priestTemp.setMagicPoints(200);
		priestTemp.setRace(raceSel());
		priestTemp.setName(nameSel());
		priest.push_back(priestTemp);
		return true;
		break;
	case MAGE:
		mageTemp.setHitpoints(200);
		mageTemp.setMagicPoints(0);
		mageTemp.setRace(raceSel());
		mageTemp.setName(nameSel());
		mage.push_back(mageTemp);
		return true;
		break;
	case 4:
		charPrint();
		return false;
		break;
	default:
		cout << "Invalid selection.\n";
		charCreate();
		break;
	}
}

string Warrior::attack() {
	return "I will destroy you with my sword!\n";
}
string Priest::attack() {
	return "I will assault you with my holy wrath!\n";
}
string Mage::attack() {
	return "I will crush you with my arcane missiles!\n";
}

//goes through the vectors and couts each player's stats
void charPrint() {

	//Warrior cout
	cout << "---------------\nWARRIOR LIST:\n---------------\n";

	for (int i = 0; i < warrior.size(); i++) {
		cout << "I am a warrior with the name " << warrior[i].getName() << " and with race " << warrior[i].whatRace() << " and my attack is: " << warrior[i].attack();
	}

	//Priest cout
	cout << "---------------\nPRIEST LIST:\n---------------\n";

	for (int i = 0; i < priest.size(); i++) {
		cout << "I am a priest with the name " << priest[i].getName() << " and with race " << priest[i].whatRace() << " and my attack is: " << priest[i].attack();
	}

	//Mage cout
	cout << "---------------\nMAGE LIST:\n---------------\n";

	for (int i = 0; i < mage.size(); i++) {
		cout << "I am a mage with the name " << mage[i].getName() << " and with race " << mage[i].whatRace() << " and my attack is: " << mage[i].attack();
	}
}


int main() {
	bool players = true;

	while (players) {
		players = charCreate();
	}

	cout << "\nCharacter creation done!.......\nYou can now move to the next level!";

	return 0;
}