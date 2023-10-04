/***********************************************************************
Full Name : Arian Kazemi
Student ID# : 181613217
Email : akazemi4@myseneca.ca
Section : NEE

Authenticity Declaration :
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
************************************************************************/




#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

#define MIN_TIME 700
#define MAX_TIME 2300
#define MAX_NO_OF_PASSENGERS 1000

namespace sdds {
	class Train {
		char* m_name{};
		int m_passengers{};
		int m_departure_time{};

	public:
		void initialize();

		bool validTime(int value) const;
		bool validNoOfPassengers(int value) const;
		bool isInvalid() const;

		void set(const char* name);
		void set(int passengers, int departure_time);
		void set(const char* name, int passengers, int departure_time);

		void finalize();

		int noOfPassengers() const;
		int getDepartureTime() const;
		const char* getName() const;

		void display() const;

		bool load(int& unboarded_passengers);

		bool updateDepartureTime();

		bool transfer(const Train& train);
	};
}

#endif // !SDDS_TRAIN_H