#pragma once
#include <iostream>
#include <string>
#include "Tickets.h"
#include "container.h"

using namespace std;

class Person {
private:
    string name;
    string surname;
    string citizenship;
    int age;
    double money;

    container<Tickets> arr;

public:
    Person();
    Person(const string& name_, const string& surname_, const string& citizenship_, int age_, double money_);
    Person(const Person& other);
    container<Tickets>& get_container();
    void input();
    void print() const;
    Person& operator=(const Person& other);
    double get_money() const;
    void set_money(double new_money);
};
