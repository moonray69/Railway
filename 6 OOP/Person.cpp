#include "Person.h"

Person::Person() {
	name = "";
	surname = "";
	citizenship = "";
	age = 0;
	money = 0;
}


Person::Person(const string& name_, const string& surname_, const string& citizenship_, int age_, double money_) {
	name = name_;
	surname = surname_;
	citizenship = citizenship_;
	age = age_;
	money = money_;
}

Person::Person(const Person& other) {
	this->name = other.name;
	this->surname = other.surname;
	this->citizenship = other.citizenship;
	this->age = other.age;
	this->money = other.money;
}

container<Tickets>& Person::get_container() {
	return arr;
}

void Person::input() {
	cout << "=============================================" << endl;
	cout << "Input your surname: ";
	cin >> surname;
	cout << "Input your name: ";
	cin >> name;
	cout << "Input your age: ";
	cin >> age;
	cout << "Input your citizenship: ";
	cin >> citizenship;
	cout << "Input your capital: ";
	cin >> money;
	cout << "=============================================" << endl << endl;
}

void Person::print()const {
	cout << "=============================================" << endl;
	cout << "Surname: " << surname << endl;
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Citizenship: " << citizenship << endl;
	cout << "Capital: " << money << endl << endl;
	cout << "=============================================" << endl;
}

Person& Person::operator=(const Person& other) {
	if (this == &other) {
		return *this;
	}
	this->name = other.name;
	this->surname = other.surname;
	this->citizenship = other.citizenship;
	this->age = other.age;
	this->money = other.money;

	return *this;
}

double Person::get_money()const {
	return money;
}

void Person::set_money(double new_money) {
	money = new_money;
}

