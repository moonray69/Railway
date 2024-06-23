#pragma once
#include "Tickets.h"  
#include "Person.h"   

class SoldTicket {
public:
    SoldTicket(const Tickets& ticket, const Person& person, double penalty);

    // ������ ������� � ������
    const Tickets& getTicket() const;
    const Person& getPerson() const;
    double getPenalty() const;
    SoldTicket();

private:
    Tickets ticket;   // ��������� �����
    Person person;    // ���������� ������
    double penalty;   // ���� �� ������� ������    
};


