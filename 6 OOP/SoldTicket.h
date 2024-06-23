#pragma once
#include "Tickets.h"  
#include "Person.h"   

class SoldTicket {
public:
    SoldTicket(const Tickets& ticket, const Person& person, double penalty);

    // Методы доступа к данным
    const Tickets& getTicket() const;
    const Person& getPerson() const;
    double getPenalty() const;
    SoldTicket();

private:
    Tickets ticket;   // Проданный билет
    Person person;    // Покупатель билета
    double penalty;   // Пеня за продажу билета    
};


