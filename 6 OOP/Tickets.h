#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>


using namespace std;

extern const char* destinations[];

extern enum class vagon_type_e;
// extern = объ€вить о существовании переменной без еЄ создани€
//используетс€ дл€ объ€влени€ переменных и функций, которые должны быть определены в другом месте программы.
extern const char* vagon_type_s[];

class Tickets{
private:
	double cost_ticket;
	int Day;
	int month;
	int year;
	string destination;
	vagon_type_e type_vagon;
	int number_ticket;
	int hours;
	int minutes;
	int hours_departure;
	int minutes_departure;
	int hours_arrival;
	int minutes_arrival;

public:
	Tickets();
	Tickets(const Tickets& other);
	void random_ticket();
	void print()const;
	void file_write(const string& file_name, int n);
	Tickets(int Day, int month, int year, const string& destination, const vagon_type_e& type_vagon);

	Tickets& operator=(const Tickets& other);
	bool operator==(const Tickets& other);
	double get_cost_ticket()const;
	int get_number_ticket()const;
	string get_city()const;
	int getDaysUntilDeparture() const;
	///*void file_read(const string& file_name, int n, int m, int** arr) {
//	ifstream ifs;
//	ifs.open(file_name);
//	if (!ifs) {
//		cout << "file is not open." << endl;
//		exit(-1);
//	}
//	
//	ifs.close();
//}*/

};



