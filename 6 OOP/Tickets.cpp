#include "Tickets.h"
 const char* destinations[] = { "Kyiv", "Odesa", "Zhytomyr", "Kharkiv", "Lviv", "Kryvyi Rih", "Vinnytsa", "Poltava" };

  enum class vagon_type_e {
	 Plackart, Coupe, Premium, InterCity, UnDefine
 };

   const char* vagon_type_s[] = {
	"Plackart", "Coupe", "Premium", "InterCity"
  };
   //
   //static_cast =  это оператор в C++, который используется для явного преобразования типов данных во время компиляции
void Tickets::random_ticket() {
	type_vagon = static_cast<vagon_type_e>(rand() % 4);
	if (type_vagon == vagon_type_e::Plackart) {
		cost_ticket = 350;
	}
	else if (type_vagon == vagon_type_e::Coupe) {
		cost_ticket = 500;
	}
	else if (type_vagon == vagon_type_e::Premium) {
		cost_ticket = 750;
	}
	else if (type_vagon == vagon_type_e::InterCity) {
		cost_ticket = 800;
	}
	//hours = 1 + rand() % 24;
	//minutes =1 + rand() % 60;
	Day = 1 + rand() % 31;
	month = 1 + rand() % 12;
	year = 2024;
	hours_departure = rand() % 24;
	minutes_departure = 1 + rand() % 59;
	hours_arrival = hours_departure + (1 + rand() % 6);  // Припустимо, що час подорожі від 1 до 6 годин
	minutes_arrival = 1 + rand() % 59;

	destination = destinations[rand() % 7];
	number_ticket = rand() % 100 - 1;
}


Tickets::Tickets() {
	random_ticket();
}

Tickets::Tickets(int Day, int month, int year, const string& destination, const vagon_type_e& type_vagon) {
	this->Day = Day;
	this->month = month;
	this->year = year;
	this->destination = destination;
	this->type_vagon = type_vagon;
	number_ticket = rand() % 100000 - 1;
	cost_ticket = 0;
}


Tickets::Tickets(const Tickets& other) {
	this->cost_ticket = other.cost_ticket;
	this->Day = other.Day;
	this->month = other.month;
	this->year = other.year;
	this->destination = other.destination;
	this->type_vagon = other.type_vagon;
	this->number_ticket = other.number_ticket;
	this->hours_departure = other.hours_departure;
	this->minutes_departure = other.minutes_departure;
	this->hours_arrival = other.hours_arrival;
	this->minutes_arrival = other.minutes_arrival;

}

void Tickets::print()const {
	cout << "Date: " << Day << "." << month << "." << year << endl;
	cout << "Destination: " << destination << endl;
	cout << "Type vagon: " << vagon_type_s[static_cast<int> (type_vagon)] << endl;
	cout << "Ticket cost: " << cost_ticket << endl;
	cout << "Departure time: " << hours_departure << ":" << minutes_departure << endl;
	cout << "Arrival time: " << hours_arrival << ":" << minutes_arrival << endl << endl;
}

void Tickets::file_write(const string& file_name, int n) {
	ofstream ofs;
	ofs.open(file_name);
	if (!ofs) {
		cout << "file is not open." << endl;
		exit(-1);
	}
	for (int i = 0; i < n; i++) {
		Tickets ticket;
		ticket.random_ticket();
		ofs << Day << " " << month << " " << year << endl;
		ofs << destination << endl;
		ofs << vagon_type_s[static_cast<int> (type_vagon)] << endl;
		ofs << cost_ticket << endl << endl;
	}
	ofs.close();
}


/*void file_read(const string& file_name, int n, int m, int** arr) {
	ifstream ifs;
	ifs.open(file_name);
	if (!ifs) {
		cout << "file is not open." << endl;
		exit(-1);
	}

	ifs.close();
}*/

Tickets& Tickets::operator=(const Tickets& other) {
	if (this == &other) {
		return *this;
	}
	this->cost_ticket = other.cost_ticket;
	this->Day = other.Day;
	this->month = other.month;
	this->year = other.year;
	this->destination = other.destination;
	this->type_vagon = other.type_vagon;
	this->number_ticket = other.number_ticket;
	this->hours_departure = other.hours_departure;
	this->minutes_departure = other.minutes_departure;
	this->hours_arrival = other.hours_arrival;
	this->minutes_arrival = other.minutes_arrival;

	return *this;
}
bool Tickets::operator==(const Tickets& other) {
	return other.Day == Day && other.month == month && other.year == year && other.destination == destination;
}

double Tickets::get_cost_ticket()const {
	return cost_ticket;
}

// написать метод который возвращает номер билета в тикете
int Tickets::get_number_ticket()const {
	return number_ticket; 
}

string Tickets::get_city()const {
	return destination;
}

int Tickets::getDaysUntilDeparture() const {
	// Получаем текущее время в секундах с начала эпохи (1 января 1970 года)
	time_t currentTime;
	time(&currentTime);

	// Получаем структуру tm для текущей локальной даты и времени
	tm currentDateTime;
	localtime_s(&currentDateTime, &currentTime);

	// Создаем структуру tm для даты и времени отправления из объекта Tickets
	tm departureTime = {};
	departureTime.tm_year = year - 1900; // Год начинается с 1900
	departureTime.tm_mon = month - 1;    // Месяц начинается с 0 (январь - 0)
	departureTime.tm_mday = Day;
	departureTime.tm_hour = hours_departure;
	departureTime.tm_min = minutes_departure;
	departureTime.tm_sec = 0;

	// Преобразуем структуру tm в секунды с начала эпохи
	time_t departureTimeInSeconds = mktime(&departureTime);

	// Вычисляем разницу во времени между текущим временем и временем отправления
	double diffInSeconds = difftime(departureTimeInSeconds, currentTime);
	int daysUntilDeparture = static_cast<int>(diffInSeconds / (60 * 60 * 24)); // Преобразуем разницу в дни

	return daysUntilDeparture;
}

