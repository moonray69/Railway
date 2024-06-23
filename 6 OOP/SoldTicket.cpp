#include "SoldTicket.h"

SoldTicket::SoldTicket(const Tickets& ticket, const Person& person, double penalty): ticket(ticket), person(person), penalty(penalty) {
  
}

const Tickets& SoldTicket::getTicket() const {
    return ticket;
}

const Person& SoldTicket::getPerson() const {
    return person;
}

double SoldTicket::getPenalty() const {
    return penalty;
}

SoldTicket::SoldTicket() {

}


