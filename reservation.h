/*
Nora Luna
CS 202
Program 2
reservation.h

This file contains the function prototypes for the Date and 
Reservation classes, and the 3 derived classes Airline, Hotel, and
Car. The functions for these classes allow the user to input
data for each private data memeber. The relational operators
are overloaded in the Date and Reservation classes, as well as some
additional operators for functionality in the derived classes.
*/

#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
using namespace std;

class Date
{
    public:
        Date();
        ~Date();
        Date(int day, int month, int year);

        Date& operator=(const Date& aDate);
        bool operator!() const;
        bool operator==(const Date& aDate) const;
        bool operator!=(const Date& aDate) const;
        bool operator<(const Date& aDate) const;
        bool operator<=(const Date& aDate) const;
        bool operator>=(const Date& aDate) const;
        bool operator>(const Date& aDate) const;
        friend ostream& operator<<(ostream& out, const Date& aDate);
        friend istream& operator>>(istream& in, Date& aDate);

        void inputDate(void);

    protected:
        int year;
        int month;
        int day;
};

class Reservation
{
    public:
        Reservation();
        ~Reservation();
        Reservation(const Reservation& toCopy);

        Reservation& operator=(const Reservation& aReservation);
        bool operator!() const;
        bool operator==(const Reservation& r) const;
        bool operator==(const string& s) const;
        bool operator!=(const Reservation& r) const;
        bool operator!=(const string& s) const;
        bool operator<(const Reservation& r) const;
        bool operator<=(const Reservation& r) const;
        bool operator>=(const Reservation& r) const;
        bool operator>(const Reservation& r) const;
        friend ostream& operator<<(ostream& out, const Reservation& r);


        bool inputName(void);
        bool inputLocation(void);
        void inputStartDate(void);
        void inputEndDate(void);
        bool makeReservation(void);
        bool display(void);



    protected:
        string name;
        Date start;
        Date end;
        char* location;
};

class Airline: public Reservation
{
    public:
	    Airline();
	    ~Airline();

    	Airline& operator=(const Airline& anAirline);
        bool operator==(const Airline& a) const;
        bool operator==(const string& s) const;
        bool operator!=(const Airline& a) const;
        bool operator!=(const string& s) const;
        friend ostream& operator<<(ostream& out, const Airline& a);
        friend istream& operator>>(istream& in, const Airline& a);

	    bool selectSeat(void);
	    bool selectAccessibleSeating(void);
    	bool makeReservation(void);
        bool display(void);
	
    protected:
	    string seat;
	    bool accessibleSeating;
};


class Car: public Reservation
{
    public:
        Car();
	    ~Car();
	    Car(const Car& toCopy);

	    Car& operator=(const Car& aCar);
        bool operator!() const;
        bool operator==(const Car& c) const;
        bool operator==(const string& s) const;
        bool operator!=(const Car& c) const;
        bool operator!=(const string& s) const;
        friend ostream& operator<<(ostream& out, const Car& c);

	    bool selectCarSize(void);
	    bool selectAuto(void);
	    bool inputRenterAge(void);
        bool selectAccessibleCar(void);
	    bool makeReservation(void);

    protected:
	    char* carOption;
	    bool automatic;
	    int renterAge;
        bool accessibleCar;
};

class Hotel: public Reservation
{
    public:
	    Hotel();
	    ~Hotel();

	    Hotel& operator=(const Hotel& aHotel);
        bool operator!() const;
        bool operator==(const Hotel& h) const;
        bool operator==(const string& s) const;
        bool operator!=(const Hotel& h) const;
        bool operator!=(const string& s) const;
        friend ostream& operator<<(ostream& out, const Hotel& h);

	    bool inputNumBeds(void);
	    bool inputSizeBeds(void);
	    bool inputNumPeople(void);
	    bool accessibleRoom(void);
	    bool makeReservation(void);

    protected:
	    int numBeds;
	    string sizeBeds;
	    int numPeople;
	    bool accessible;
};

#endif
