/*
Nora Luna
CS 202
Program 2
reservation.cpp

This file contains the definitions for the Date and Reservation classes,
as well as the 3 classes that are derived from Reservation: Airline,
Hotel, and Car. 
The Date class keeps track of year, month, and day (all integers). The 
Date class has all the relational operators overloaded. It also has some
additional operators for functionality. 
The Reservation class has the relational operators overloaded and some
additional for functionality. It contains 4 private data members,
name, start date, end date, and location. There are function to
input these data (user input), and to display.
The derived classes all hold unqiue data as well as the functions for the
user to input the data.
*/

#include <memory>
#include <cstring>
#include "reservation.h"
#include "error.h"


//Date prototypes

//constructor
Date::Date() : year(0), month(0), day(0)
{
}

//destructor
Date::~Date()
{
}

//copy constructor with arguments
Date::Date(int aYear, int aMonth, int aDay) : year(aYear), 
    month(aMonth), day(aDay) 
{
}

//operator overloading =
Date& Date::operator=(const Date& aDate)    //add it to the list

{
    if(this == &aDate)
        return *this;

    //exception handling
    try
    {
        if(!aDate)
            throw aDate;

        year = aDate.year;
        month = aDate.month;
        day = aDate.day;

    }catch(Date&)
    {
        cerr << "Error, no date to assign." << endl;
    }
    return *this;
}

//operator overloading !
bool Date::operator!() const
{
    if(year == 0 || month == 0 || day == 0)
        return true;
    else
        return false;
}

//operator overloading ==
bool Date::operator==(const Date& aDate) const
{
    if(year == aDate.year && month == aDate.month && day == aDate.day)
        return true;
    else
        return false;
}

//operator overloading !=
bool Date::operator!=(const Date& aDate) const
{

    if(year != aDate.year || month != aDate.month || day != aDate.day)
        return true;
    else
        return false;
}

//operator overing <
bool Date::operator<(const Date& aDate) const
{

    if(year < aDate.year)
        return true;
    else
        if(year == aDate.year && month < aDate.month)
            return true;
        else
            if(year == aDate.year && month == aDate.month && 
                    day < aDate.day)
                return true;
            else
                return false;
}

//operator overloading <=
bool Date::operator<=(const Date& aDate) const
{

    if(year < aDate.year)
        return true;
    else
        if(year == aDate.year && month < aDate.month)
            return true;
        else
            if(year == aDate.year && month == aDate.month &&
                    day <= aDate.day)
                return true;
            else
                return false;
}

//operator overloading >
bool Date::operator>(const Date& aDate) const
{

    if(year > aDate.year)
        return true;
    else
        if(year == aDate.year && month > aDate.month)
            return true;
        else
            if(year == aDate.year && month == aDate.month &&
                    day > aDate.day)
                return true;
            else
                return false;
}

//operator overloading >=
bool Date::operator>=(const Date& aDate) const
{
    if(year > aDate.year)
        return true;
    else
        if(year == aDate.year && month > aDate.month)
            return true;
        else
            if(year == aDate.year && month == aDate.month &&
                    day >= aDate.day)
                return true;
            else
                return false;
}

//operator overloading <<
ostream& operator<<(ostream& out, const Date& aDate)
{
    out << aDate.day << "/" << aDate.month << "/" << aDate.year;
    return out;
}

//operator overload >>
istream& operator>>(istream& in, Date& aDate)
{
    string input;

    getline(cin, input);


    //exception handling
    if(input.length() != 10)
        throw input;

    aDate.day = stoi(input.substr(0,2));

    //exception handling
    if(aDate.day < 0 || aDate.day > 31)
        throw aDate.day;

     aDate.month = stoi(input.substr(3,2));

     //exception handling
     if(aDate.month < 0 || aDate.month > 12)
         throw aDate.month;
    
     aDate.year = stoi(input.substr(6));

     //exception handing
     if(aDate.year < 2022 || aDate.year > 3022)
         throw aDate.year;

     return in;

}


//input date 
void Date::inputDate(void)
{
    string input;
    cout << "Please input the date in the format (DD/MM/YYYY): ";

    getline(cin, input);


    //exception handling
    if(input.length() != 10)
        throw input;

    day = stoi(input.substr(0,2));

    //exception handling
    if(day < 0 || day > 31)
        throw day ;

    month = stoi(input.substr(3,2));
     
    //exception handling
    if(month < 0 || month > 12)
         throw month;

    year = stoi(input.substr(6));

    //exception handling
    if(year < 2022 || year > 3022)
         throw year;

}





//Reservation prototypes

//constructor
Reservation::Reservation() : name("none"),
    start(0,0,0), end(0,0,0), location(nullptr)
{
}

//destructor
Reservation::~Reservation()
{
    if(location)
        delete [] location;
}

//copy constructor
Reservation::Reservation(const Reservation& toCopy)
{
    if(location)
        delete [] location;

    *this = toCopy;
}

//operator overloading =
Reservation& Reservation::operator=(const Reservation& aReservation)
{
    if(this == &aReservation)
        return *this;

    if(location)
        delete [] location;

    this->name = aReservation.name;
    this->start = aReservation.start;
    this->end = aReservation.end;
    this->location = new char[strlen(aReservation.location) + 1];
    strcpy(this->location, aReservation.location);

    return *this;
}


//operator overloading !
bool Reservation::operator!() const
{
    if(name == "none" || !start || !end || location == nullptr)
        return true;
    else
        return false;
}

//operator overloading ==
//checks for equality, compared to a reservation object
bool Reservation::operator==(const Reservation& r) const
{
    if(name == r.name && start == r.start && end == r.end &&
            strcmp(location, r.location) == 0)
        return true;
    else
        return false;
}

//operator overloading ==
//checks for equality using name, compared to a string
bool Reservation::operator==(const string& s) const
{
    if(name == s)
        return true;
    else
        return false;
}

//operator overloading !=
//checks for inequality, compared to a Reservation object
bool Reservation::operator!=(const Reservation& r) const
{
    if(name != r.name || start != r.start || end != r.end || 
            strcmp(location, r.location) != 0)
        return true;
    else
        return false;
}

//operator overloading !=
//checks for inequality using name, compared to a string
bool Reservation::operator!=(const string& s) const
{
    if(name != s)
        return true;
    else
        return false;
}


//operator overloading <
//checks for < using name
bool Reservation::operator<(const Reservation& r) const
{
    if(name < r.name)
        return true;
    else
        return false;
}

//operator overloading <=
//checks for <= using name
bool Reservation::operator<=(const Reservation& r) const
{
    if(name <= r.name)
        return true;
    else
        return false;
}

//operator overloading >=
//checks for >= using name
bool Reservation::operator>=(const Reservation& r) const
{
    if(name >= r.name)
        return true;
    else
        return false;
}

//operator overloading >
//checks for > using name
bool Reservation::operator>(const Reservation& r) const
{
    if(name > r.name)
        return true;
    else
        return false;
}

//operator overloading<<
ostream& operator<<(ostream& out, const Reservation& r)
{
    cout << "Name: " << r.name << endl;
    cout << "Start Date: " << r.start << endl;
    cout << "End Date: " << r.end << endl;
    cout << "Location: " << r.location << endl;
    return out;
}

//user input name
bool Reservation::inputName(void)
{
    string input;
    cout << "Please input the name: ";

    getline(cin, input);
    name = input;
    return true;
}

//user input location
bool Reservation::inputLocation(void)
{
    string loc;
    cout << "Please enter the destination: ";
    
    getline(cin, loc);

    location = new char[loc.length() + 1];
    strcpy(this->location, loc.c_str());

    return true;
}

//user input start date
void Reservation::inputStartDate(void)
{
    cout << "Please input departure date." << endl;
    try
    {
        start.inputDate();
    } catch(string&)
    {
        cerr << "Incorrect input. Date format: DD/MM/YYYY." << endl;
        //use recursion to re-enter date
    }
    catch(int&)
    {
        cerr << "Date is incorrect." << endl;
    }
    catch(...)
    {
        cerr << "Bad Input. Please re-enter date." << endl;
    }
}

//user input end date
void Reservation::inputEndDate(void)
{
    cout << "Please input return date." << endl;
    try
    {
        end.inputDate();
    } catch(string&)
    {
        cerr << "Incorrect input. Date format: DD/MM/YYYY." << endl;
        //use recursion to re-enter date
    }
    catch(int&)
    {
        cerr << "Date is incorrect." << endl;
    }
    catch(...)
    {
        cerr << "Bad Input. Please re-enter date." << endl;
    }
}

//user makes reservation, calls helper functions
bool Reservation::makeReservation(void)
{
    inputName();
    inputLocation();
    try
    {
        inputStartDate();
    }catch(...)
    {
        cout << "Error entering date." << endl;
    }
    try
    {
        inputEndDate();
    }catch(...)
    {
        cout << "Error entering date." << endl;
    }
    return true;
}

bool Reservation::display(void)
{
    cout << "Name: " << name << endl;
    cout << "Start Date: " << start << endl;
    cout << "End Date: " << end << endl;
    cout << "Location: " << location << endl;
    return true;
}


//Airline member functions

//constructor, init list
Airline::Airline() : seat("none"), accessibleSeating(false)
{
}

//destructor
Airline::~Airline()
{
}

//operator overload =
Airline& Airline::operator=(const Airline& anAirline)
{
    if(this == &anAirline)
        return *this;

    Reservation::operator=(anAirline);
    this->seat = anAirline.seat;
    this->accessibleSeating = anAirline.accessibleSeating;

    return *this;
}

//operator overloading ==
bool Airline::operator==(const Airline& a) const
{
    if(Reservation::operator==(a) == true && seat == a.seat &&
            accessibleSeating == a.accessibleSeating)
        return true;
    else
        return false;
}

bool Airline::operator==(const string& s) const
{
    return Reservation::operator==(s);
}

//operator overloading !=
bool Airline::operator!=(const Airline& a) const
{
   if(Reservation::operator!=(a) == true || seat != a.seat ||
           accessibleSeating != a.accessibleSeating)
       return true;
   else
       return false;
}

bool Airline::operator!=(const string& s) const
{
    return Reservation::operator!=(s);
}

//operator overload <<
ostream& operator<<(ostream& out, const Airline& a)
{
    cout << "Name: " << a.name << endl;
    cout << "Start Date: " << a.start << endl;
    cout << "End Date: " << a.end << endl;
    cout << "Location: " << a.location << endl;
    cout << "Seat preference: " << a.seat << endl;
    if(a.accessibleSeating == true)
        cout << "Accessible seating" << endl;
    return out;

}

//user selects seat
bool Airline::selectSeat(void)
{
    string input;
    cout << "Enter your seat preference (aisle, window, middle): ";
   
    getline(cin, input);

    seat = input;

    return true;
}

//user input accessible seating
bool Airline::selectAccessibleSeating(void)
{
    char input;
    cout << "Do you need accessible seating? Enter (y/n): ";

    cin >> input;
    getchar();
    
    if(input == 'y' || input == 'Y')
        accessibleSeating = true;
    else
        accessibleSeating = false;
    return true;
}

//user creates a new reservation, calls helper functions
bool Airline::makeReservation(void)
{

    Reservation::makeReservation();
    selectSeat();
    selectAccessibleSeating();
    return true;
}

bool Airline::display(void)
{
    Reservation::display();
    cout << "Seat preference: " << seat << endl;
    if(accessibleSeating)
        cout << "Accessible seating" << endl;
    return true;
}

//Car member functions

//constructor
Car::Car() : carOption(nullptr), automatic(false), renterAge(0)
{
}

//destructor
Car::~Car()
{
    if(carOption)
        delete [] carOption;
}

//copy constructor
Car::Car(const Car& toCopy) :Reservation(toCopy)
{
    if(carOption)
        delete [] carOption;

    *this = toCopy;
}

//operator overloading =
Car& Car::operator=(const Car& aCar)
{
    if(this == &aCar)
        return *this;

    Reservation::operator=(aCar);
    this->automatic = aCar.automatic;
    this->renterAge = aCar.renterAge;
    this->carOption = new char[strlen(aCar.carOption) + 1];
    strcpy(this->carOption, aCar.carOption);

    return *this;
}

//operator overloading !
bool Car::operator!() const
{
    if(name == "none" || !start || !end || location == nullptr 
            || renterAge == 0)
        return true;
    else
        return false;

}

//operator overloading ==
bool Car::operator==(const Car& c) const
{
    if(Reservation::operator==(c) == true && automatic == c.automatic 
            && renterAge == c.renterAge && accessibleCar == c.accessibleCar
            && strcmp(carOption, c.carOption) == 0)
        return true;
    else
        return false;
}

bool Car::operator==(const string& s) const
{
    return Reservation::operator==(s);
}

//operator overloading !=
bool Car::operator!=(const Car& c) const
{
    if(Reservation::operator!=(c) == true || automatic != c.automatic ||
            renterAge != c.renterAge || accessibleCar != c.accessibleCar ||
            strcmp(carOption, c.carOption) != 0)
        return true;
    else
        return false;
}

bool Car::operator!=(const string& s) const
{
    return Reservation::operator!=(s);
}

//operator overloading <<
ostream& operator<<(ostream& out, const Car& c)
{
    cout << "Name: " << c.name << endl;
    cout << "Start Date: " << c.start << endl;
    cout << "End Date: " << c.end << endl;
    cout << "Location: " << c.location << endl;
    cout << "Car: " << c.carOption << endl;
    cout << "Renter's Age: " << c.renterAge << endl;
    if(c.automatic == true)
        cout << "Automatic transmission" << endl;
    else
        cout << "Manual transmission" << endl;
    return out;
}

//user selects car size
bool Car::selectCarSize(void)
{
    char input;
    cout << "Please select from the following options:" << endl;
    cout << "a. 2-door Economy" << endl;
    cout << "b. 4-door Economy" << endl;
    cout << "c. Luxury" << endl;
    cout << "d. Truck" << endl;
    cout << "e. SUV" << endl;
    cout << "f. Cargo Van" << endl;
    cout << "Vehicle Selection (enter a, b, c, d, e, or f): ";
    
    cin >> input;
    getchar();

    switch(input)
    {
        case 'a':
            carOption = new char[strlen("2-door Economy") + 1];
            strcpy(carOption, "2-door Economy");
            break;
        case 'b':
            carOption = new char[strlen("4-door Economy") + 1];
            strcpy(carOption, "4-door Economy");
            break;
        case 'c':
            carOption = new char[strlen("Luxury") + 1];
            strcpy(carOption, "Luxury");
            break;
        case 'd':
            carOption = new char[strlen("Truck") + 1];
            strcpy(carOption, "Truck");
            break;
        case 'e':
            carOption = new char[strlen("SUV") + 1];
            strcpy(carOption, "SUV");
            break;
        case 'f':
            carOption = new char[strlen("Cargo Van") + 1];
            strcpy(carOption, "Cargo Van");
            break;
        default:
            break;
    }
    
    return true;
}

//user selects auto/manual
bool Car::selectAuto(void)
{
    char input;
    cout << "Would you like automatic transmission? (Enter y/n): ";
    cin >> input;
    getchar();

    if(input == 'y' || input == 'Y')
        automatic = true;
    else
        automatic = false;

    return true;
}

//user inputs age
bool Car::inputRenterAge(void)
{
    int input;
    cout << "Please enter the driver's age: ";
    
    cin >> input;
    getchar();

    //exception handling
    if(input < 18 || input > 120)
        throw input;

    renterAge = input;
    return true;
}

bool Car::selectAccessibleCar(void)
{
    char input;
    cout << "Do you need an accessible vehicle? Enter (y/n): ";
        
    cin >> input;
    getchar();

    if(input == 'y' || input == 'Y')
        accessibleCar = true;
    else
        accessibleCar = false;
    return true;

}

//user makes reservation
bool Car::makeReservation(void)
{
    Reservation::makeReservation();
    selectCarSize();
    selectAccessibleCar();
    selectAuto();

    try
    {
        inputRenterAge();
    } catch(int&)
    {
        cerr << "Please enter a number between 18 - 120." 
            << endl;
        //use recursion to re-enter
    }
    return true;
}

//Hotel member functions

//constructor
Hotel:: Hotel() : numBeds(0), sizeBeds("none"), numPeople(0), 
    accessible(false) 
{
}

//destructor
Hotel::~Hotel()
{
}

//operator overloading
Hotel& Hotel::operator=(const Hotel& aHotel)
{
    if(this == &aHotel)
        return *this;

    Reservation::operator=(aHotel);
    this->numBeds = aHotel.numBeds;
    this->sizeBeds = aHotel.sizeBeds;
    this->numPeople = aHotel.numPeople;
    this->accessible = aHotel.accessible;

    return *this;
}

//operator overloading !
bool Hotel::operator!() const
{
    if(name == "none" || !start || !end || location == nullptr )
        return true;
    else
        return false;
}

//operator overloading ==
bool Hotel::operator==(const Hotel& h) const
{
    if(Reservation::operator==(h) == true && numBeds == h.numBeds &&
            sizeBeds == h.sizeBeds && numPeople == h.numPeople 
            && accessible == h.accessible)
        return true;
    else
        return false;
}

bool Hotel::operator==(const string& s) const
{
    return Reservation::operator==(s);
}


//operator overloading !=
bool Hotel::operator!=(const Hotel& h) const
{
    if(Reservation::operator!=(h) == true || numBeds != h.numBeds ||
            sizeBeds != h.sizeBeds || numPeople != h.numPeople ||
            accessible != h.accessible)
        return true;
    else
        return false;
}

bool Hotel::operator!=(const string& s) const
{
    return Reservation::operator!=(s);
}
//operator overloading <<
ostream& operator<<(ostream& out, const Hotel& h)
{
    cout << "Name: " << h.name << endl;
    cout << "Start Date: " << h.start << endl;
    cout << "End Date: " << h.end << endl;
    cout << "Location: " << h.location << endl;
    cout << "Number of Beds: " << h.numBeds << endl;
    cout << "Size of Beds: " << h.sizeBeds << endl;
    cout << "Number of People: " << h.numPeople << endl;
    if(h.accessible == true)
        cout << "Accessible Room" << endl;

    return out;
}

//user inputs number of beds
bool Hotel::inputNumBeds(void)
{
    int input;
    cout << "Please enter the number of beds needed: ";
    
    cin >> input;
    getchar();
   
    numBeds = input;

    return true;
}

//user inputs size of beds
bool Hotel::inputSizeBeds(void)
{
    string input;
    cout << "Please enter bed size (twin, queen, king): ";
    getline(cin, input);
    sizeBeds = input;
    return true;
}

//user inputs number of people
bool Hotel::inputNumPeople(void)
{
    int input;
    cout << "Enter number of people: ";
    cin >> input;
    
    getchar();

    numPeople = input;
    return true;
}

//user inputs accessible room
bool Hotel::accessibleRoom(void)
{
    char input;
    cout << "Do you need an accessible room? Enter (y/n): ";
    
    cin >> input;
    getchar();

    if(input == 'y' || input == 'Y')
        accessible = true;
    else
        accessible = false;
    return true;

}

//user makes a new reservation
bool Hotel::makeReservation(void)
{
    Reservation::makeReservation();
    try
    {
        inputNumBeds();
    } catch(string&)
    {
        cerr << "Bad input. Enter integers only." << endl;
    }

    inputSizeBeds();

    try
    {
        inputNumPeople();
    } catch(string&)
    {
        cerr << "Bad input. Enter integers only." << endl;
    }
    accessibleRoom();
    return true;
}


