#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "container.h"
#include "Tickets.h"
#include "Person.h"
#include "SoldTicket.h"

using namespace std;

class Railway {
private:
    container<Tickets> avaiable_tickets;
    container<SoldTicket> rent_tickets;
    container<Person> customers;

public:
    Railway();
    Railway(int size);
    Railway(const Railway& other);
    Railway(int numTickets, double commission);

    void buy_ticket(Person& person);
    void get_ticket_back(Person& person);
    void print_avaiable_tickets();
    void sellTicket(Person& person, int ticketNumber);
    void returnTicket(Person& person, int ticketNumber);
    double calculatePenalty(const Tickets& ticket);

    void print_rent_tickets();
};
