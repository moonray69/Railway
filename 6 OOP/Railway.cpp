#include "Railway.h"
#include "SoldTicket.h"

Railway::Railway() : avaiable_tickets(), rent_tickets() {}

Railway::Railway(int size) :avaiable_tickets(), rent_tickets() {
	for (int i = 0; i < size; i++)
	{
		Tickets ticket;
		ticket.random_ticket();
		avaiable_tickets.push_back(ticket);
	}
}

Railway::Railway(int numTickets, double commission) {
    for (int i = 0; i < numTickets; ++i) {
        Tickets ticket;
        avaiable_tickets.push_back(ticket);
    }
}

Railway::Railway(const Railway& other) :avaiable_tickets(other.avaiable_tickets), rent_tickets(other.rent_tickets) {}

void Railway::buy_ticket(Person& person) {
    string position;

    cout << "��� ���� ��� ������'�!" << endl << endl;
    for (int i = 0; i < avaiable_tickets.get_size(); i++)
    {
        cout << i + 1 << ". " << avaiable_tickets[i].get_city() << endl;
    }

    cout << "���� ������ ������ �������(ĳ�����)?" << endl;
    cin >> position;

    bool is_exist = false;
    int number_card;

    int city = atoi(position.c_str());
    if (city != 0)
    {
        if (city < 1 || city > avaiable_tickets.get_size())
        {
            cout << "���� ������ �����." << endl;
            return;
        }
        position = avaiable_tickets[city - 1].get_city();
    }

    for (int i = 0; i < avaiable_tickets.get_size(); i++)
    {
        if (position == avaiable_tickets[i].get_city())
        {
            cout << "=============================================" << endl;
            cout << avaiable_tickets[i].get_number_ticket() << ":" << endl;
            avaiable_tickets[i].print();
            cout << "=============================================" << endl;
            is_exist = true;
        }
    }
    if (!is_exist)
    {
        cout << "�� ������ ���� �� �� ������" << endl;
        return;
    }

    cout << "������ ����� ����� ������ ������ ��������: ";
    cin >> number_card;

    is_exist = false;
    for (int i = 0; i < avaiable_tickets.get_size(); i++)
    {
        if (position == avaiable_tickets[i].get_city() && number_card == avaiable_tickets[i].get_number_ticket())
        {
            is_exist = true;
            number_card = i; // ��������� ������� ���������� ������ � ������� available_tickets
            break;
        }
    }
    sellTicket(person, number_card);
    //if (person.get_money() >= avaiable_tickets[number_card].get_cost_ticket()) {
    //    // ������� ����� ����� � ������� �� ���������� ������
    //    //Tickets purchased_ticket = avaiable_tickets[number_card];

    //    //// ��������� ����� ����� � ������ rent_tickets
    //    //rent_tickets.push_back(purchased_ticket);

    //    //// ��������� ����� ����� � ��������� person
    //    //auto arr = person.get_container();
    //    //arr.push_back(purchased_ticket);

    //    //// ��������� ������� person �� ��������� ������
    //    //double ticket_cost = avaiable_tickets[number_card].get_cost_ticket();
    //    //person.set_money(person.get_money() - ticket_cost);

    //    //// ������� ����� �� ������ available_tickets
    //    //avaiable_tickets.pop_back(number_card);

    //    //cout << "������ ������� ������:)" << endl;
    //    //cout << "������� ������ � ��� �����: " << person.get_money() << endl;
    //    
    //}
    //else {
    //    cout << "�������� � 3 �������� ������ ��������" << endl;
    //}
}


void Railway::get_ticket_back(Person& person) {
	int number = 0;


	cout << "��� ���� ��� ������'�!" << endl << endl;

	cout << "������ ����� ������� ������ ������ ���������." << endl;
	cin >> number;

	for (int i = 0; i < rent_tickets.get_size(); i++)
	{
		if (rent_tickets[i].getTicket().get_number_ticket() == number)
		{
			//Tickets returned_ticket = rent_tickets[i];//�������� ����� ��� ��������
			//rent_tickets.pop_back(i);
   //         // ���������� ������ �� ����� � �������� person
   //         double ticket_cost = returned_ticket.get_cost_ticket();
   //         person.set_money(person.get_money() + ticket_cost);
			////��������� ����� � �����(������) ������
			//avaiable_tickets.push_back(returned_ticket);
			//cout << "������ ������ �����!(����� �� ���������)" << endl;
			////cout << "ϳ��� ����� ����� � ��� ����������: " << person.get_money() - returned_ticket.get_cost_ticket() << endl;
			//cout << "ϳ��� ����� ����� ��� ��������� �����, ��� ��������� ������: " << person.get_money() << endl;
            returnTicket(person, i);
			return;
		}
	}
	cout << "������ ������ �� ��������:)" << endl;
}

void Railway::print_avaiable_tickets() {
	for (int i = 0; i < avaiable_tickets.get_size(); i++)
	{
		cout << "=============================================" << endl;
		cout << avaiable_tickets[i].get_number_ticket() << endl;
		avaiable_tickets[i].print();
		cout << "=============================================" << endl;
	}
}

void Railway::print_rent_tickets() {
	for (int i = 0; i < rent_tickets.get_size(); i++)
	{
		cout << "=============================================" << endl;
		cout << rent_tickets[i].getTicket().get_number_ticket() << endl;
		rent_tickets[i].getTicket().print();
		cout << "=============================================" << endl;
	}
}

void Railway::sellTicket(Person& person, int ticketNumber) {
    Tickets ticket = avaiable_tickets[ticketNumber];

    if (person.get_money() >= ticket.get_cost_ticket()) {
        // ������ ����
        double penalty = calculatePenalty(ticket);

        // ������ ������
        person.set_money(person.get_money() - ticket.get_cost_ticket());

        // �������� ������ � ������� ������
        SoldTicket soldTicket(ticket, person, penalty);
        customers.push_back(person);
        // ���������� ������ � ������ ������������
        rent_tickets.push_back(soldTicket);

        // �������� ������ �� ���������
        avaiable_tickets.pop_back(ticketNumber);

        cout << "������ ������� ������:)" << endl;
        cout << "������� ������ � ��� �����: " << person.get_money() << endl;
    }
    else {
        cout << "����������� ����� ��� ��������� ������" << endl;
    }
}

void Railway::returnTicket(Person& person, int ticketNumber) {
    SoldTicket ticket = rent_tickets[ticketNumber];

    // ������ ���� ��� ��������
    double penalty = calculatePenalty(ticket.getTicket());

    // ������� ����� ��������� ������ � ������ ����
    double refundedAmount = ticket.getTicket().get_cost_ticket() * (1 - penalty);
    person.set_money(person.get_money() + refundedAmount);

    // �������� ������ �� ������ ������������
    rent_tickets.pop_back(ticketNumber);

    cout << "������ ������ �����. ��� ����������: " << refundedAmount << " ���" << endl;
    cout << "������� ������ � ��� �����: " << person.get_money() << " ���" << endl;

    // ����� ���������� � ���� 
    cout << "���� �� �������: " << (penalty * 100) << "%" << endl;
}

 //����� ��� ������� ����� ��� ��������
double Railway::calculatePenalty(const Tickets& ticket) {
    int daysUntilDeparture = ticket.getDaysUntilDeparture(); 
    // ������ ������� �� ������������� ������
    // ��������, ���������� ������� ���� � ����� ����������� �� ������
    // � ��������� ���� � ����������� �� ���������� ���� �� �����������
    double penalty = 0.0;
    // ������ ������� ���� � ����������� �� ������� �� ������������� ������
    // ����� ������������ switch ��� if-else ��� ����������� �������� ����
    // � ����������� �� ���������� ���� �� ������������� ������
    if (daysUntilDeparture >= 30) {
        penalty = 0.01; // 1% ����
    }
    else if (daysUntilDeparture >= 15) {
        penalty = 0.05; // 5% ����
    }
    else if (daysUntilDeparture >= 3) {
        penalty = 0.10; // 10% ����
    }
    else {
        penalty = 0.30; // 30% ���� (�� 3 ��� ��� �����)
    }

    return penalty;
}

void write_to_file(const string& file_name) {
    ofstream OFS(file_name);
        if (!OFS) {
            cout << "ERROR, no open file." << endl;
            return;
        }

}





