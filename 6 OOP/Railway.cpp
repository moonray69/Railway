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

    cout << "Дай боже вам здоров'я!" << endl << endl;
    for (int i = 0; i < avaiable_tickets.get_size(); i++)
    {
        cout << i + 1 << ". " << avaiable_tickets[i].get_city() << endl;
    }

    cout << "Куди бажаєте поїхати Парубче(Дівчино)?" << endl;
    cin >> position;

    bool is_exist = false;
    int number_card;

    int city = atoi(position.c_str());
    if (city != 0)
    {
        if (city < 1 || city > avaiable_tickets.get_size())
        {
            cout << "Нема такого білету." << endl;
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
        cout << "До такого міста ми не їздемо" << endl;
        return;
    }

    cout << "Введіть номер білета котрий хочете придбати: ";
    cin >> number_card;

    is_exist = false;
    for (int i = 0; i < avaiable_tickets.get_size(); i++)
    {
        if (position == avaiable_tickets[i].get_city() && number_card == avaiable_tickets[i].get_number_ticket())
        {
            is_exist = true;
            number_card = i; // сохраняем позицию выбранного билета в массиве available_tickets
            break;
        }
    }
    sellTicket(person, number_card);
    //if (person.get_money() >= avaiable_tickets[number_card].get_cost_ticket()) {
    //    // Создаем новый билет с данными из выбранного билета
    //    //Tickets purchased_ticket = avaiable_tickets[number_card];

    //    //// Добавляем новый билет в список rent_tickets
    //    //rent_tickets.push_back(purchased_ticket);

    //    //// Добавляем новый билет в контейнер person
    //    //auto arr = person.get_container();
    //    //arr.push_back(purchased_ticket);

    //    //// Уменьшаем капитал person на стоимость билета
    //    //double ticket_cost = avaiable_tickets[number_card].get_cost_ticket();
    //    //person.set_money(person.get_money() - ticket_cost);

    //    //// Удаляем билет из списка available_tickets
    //    //avaiable_tickets.pop_back(number_card);

    //    //cout << "Квиток придбан успішно:)" << endl;
    //    //cout << "Залишок грошей у вас зараз: " << person.get_money() << endl;
    //    
    //}
    //else {
    //    cout << "Максимум в 3 штурмову можемо підкинути" << endl;
    //}
}


void Railway::get_ticket_back(Person& person) {
	int number = 0;


	cout << "Дай боже вам здоров'я!" << endl << endl;

	cout << "Введіть номер білетика котрий хочете повернути." << endl;
	cin >> number;

	for (int i = 0; i < rent_tickets.get_size(); i++)
	{
		if (rent_tickets[i].getTicket().get_number_ticket() == number)
		{
			//Tickets returned_ticket = rent_tickets[i];//сохраняю билет для возврата
			//rent_tickets.pop_back(i);
   //         // Возвращаем деньги за билет к капиталу person
   //         double ticket_cost = returned_ticket.get_cost_ticket();
   //         person.set_money(person.get_money() + ticket_cost);
			////возвращаю билет в семью(массив) авіабле
			//avaiable_tickets.push_back(returned_ticket);
			//cout << "Квиток успішно сдано!(Гроші не повернемо)" << endl;
			////cout << "Післа купівлі білета у вас залишилося: " << person.get_money() - returned_ticket.get_cost_ticket() << endl;
			//cout << "Післа сдачі білета вам повернули кошти, ваш теперешній капітал: " << person.get_money() << endl;
            returnTicket(person, i);
			return;
		}
	}
	cout << "Такого квитка не знайдено:)" << endl;
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
        // Расчет пени
        double penalty = calculatePenalty(ticket);

        // Оплата билета
        person.set_money(person.get_money() - ticket.get_cost_ticket());

        // Создание записи о продаже билета
        SoldTicket soldTicket(ticket, person, penalty);
        customers.push_back(person);
        // Добавление билета в список арендованных
        rent_tickets.push_back(soldTicket);

        // Удаление билета из доступных
        avaiable_tickets.pop_back(ticketNumber);

        cout << "Квиток придбан успішно:)" << endl;
        cout << "Залишок грошей у вас зараз: " << person.get_money() << endl;
    }
    else {
        cout << "Недостатньо коштів для придбання квитка" << endl;
    }
}

void Railway::returnTicket(Person& person, int ticketNumber) {
    SoldTicket ticket = rent_tickets[ticketNumber];

    // Расчет пени при возврате
    double penalty = calculatePenalty(ticket.getTicket());

    // Возврат части стоимости билета с учетом пени
    double refundedAmount = ticket.getTicket().get_cost_ticket() * (1 - penalty);
    person.set_money(person.get_money() + refundedAmount);

    // Удаление билета из списка арендованных
    rent_tickets.pop_back(ticketNumber);

    cout << "Квиток успішно сдано. Вам возвращено: " << refundedAmount << " грн" << endl;
    cout << "Залишок грошей у вас зараз: " << person.get_money() << " грн" << endl;

    // Вывод информации о пене 
    cout << "Пеня за возврат: " << (penalty * 100) << "%" << endl;
}

 //Метод для расчета денег при возврате
double Railway::calculatePenalty(const Tickets& ticket) {
    int daysUntilDeparture = ticket.getDaysUntilDeparture(); 
    // Расчет времени до использования билета
    // Например, сравниваем текущую дату с датой отправления на билете
    // и вычисляем пеню в зависимости от количества дней до отправления
    double penalty = 0.0;
    // Логика расчета пени в зависимости от времени до использования билета
    // Можно использовать switch или if-else для определения процента пени
    // в зависимости от количества дней до использования билета
    if (daysUntilDeparture >= 30) {
        penalty = 0.01; // 1% пени
    }
    else if (daysUntilDeparture >= 15) {
        penalty = 0.05; // 5% пени
    }
    else if (daysUntilDeparture >= 3) {
        penalty = 0.10; // 10% пени
    }
    else {
        penalty = 0.30; // 30% пени (за 3 дня или менее)
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





