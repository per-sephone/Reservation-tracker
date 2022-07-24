/*
Nora Luna
CS 202
Program 2
main.cpp

This file contains my main user interface. There is a main menu
where the user can choose which reservation to make: Airline, Car,
Hotel. Each derived class has its own menu with the ability to
add a new reservation, remove a reservation, search for a reservation,
and display all.
*/

//#include <iostream>
#include "manager.h"


using namespace std;


//displays the primary derived menu
bool introDisplay()
{
    cout << endl;
    cout << "a. Display all" << endl;
    cout << "b. Add Reservation" << endl;
    cout << "c. Remove Reservation" << endl;
    cout << "d. Search Reservations" << endl;
    cout << "Please select from the above options: ";
    return true;

}

//displys the secondary derived menu (which includes exit)
bool mainDisplay()
{
    cout << endl;
    cout << "a. Display all" << endl;
    cout << "b. Add Reservation" << endl;
    cout << "c. Remove Reservation" << endl;
    cout << "d. Search Reservations" << endl;
    cout << "e. Exit" << endl;
    cout << "Please select from the above options: ";

    return true;
}

//main menu for airline manager object
//airline manager manages a DLL template of Airline objects
bool airlineMenu(AirlineManager& airline)
{

    char option;

    introDisplay();

    cin >> option;
    getchar();
    cout << endl;

    do
    {
        switch(option)
        {
            case 'a':
                airline.display();
                break;
            case 'b':
                airline.insert();
                break;
            case 'c':
                airline.remove();
                break;
            case 'd':
                airline.search();
                break;
            default:
                break;

        }
        mainDisplay();
        cin >> option;
        getchar();
        cout << endl;

    } while(option != 'e');
    return true;
}

//main menu for hotel manager object
//hotel manager manages a list template of hotel objects
bool hotelMenu(HotelManager& hotel)
{

    char option;

    introDisplay();

    cin >> option;
    getchar();
    cout << endl;

    do
    {
        switch(option)
        {
            case 'a':
                hotel.display();
                break;
            case 'b':
                hotel.insert();
                break;
            case 'c':
                hotel.remove();
                break;
            case 'd':
                hotel.search();
                break;
            default:
                break;

        }
        mainDisplay();
        cin >> option;
        getchar();
        cout << endl;

    } while(option != 'e');
    return true;
}

//main menu for car manager object
//car manager manages an array template of car objects
bool carMenu(CarManager& car)
{

    char option;

    introDisplay();

    cin >> option;
    getchar();
    cout << endl;

    do
    {
        switch(option)
        {
            case 'a':
                car.display();
                break;
            case 'b':
                car.insert();
                break;
            case 'c':
                car.remove();
                break;
            case 'd':
                car.search();
                break;
            default:
                break;

        }
        mainDisplay();
        cin >> option;
        getchar();
        cout << endl;

    } while(option != 'e');
    return true;
}


//main menu, allows the user to choose which
//reservations they would like to manage
int main()
{
    //create an airline manager object
    //this object manages the template that contains the 
    //airline reservation objects
    AirlineManager airlineRes;
    //create list of hotel
    //this object manages the template that contains the
    //hotel reservation objects
    HotelManager hotelRes;
    //create a car manager object
    //this object manages the template that contains the
    //car reservation objects
    CarManager carRes;

    char option;

    cout << "Welcome to the vacation reservation machine!" << endl;
    cout << "a. Airline" << endl;
    cout << "b. Hotel" << endl;
    cout << "c. Car Rental" << endl;
    cout << "Please select the type of reservation: ";

    cin >> option;
    getchar(); //collects newline char

    do
    {
        switch(option)
        {
            case 'a':
                airlineMenu(airlineRes);
                break;
            case 'b':
                hotelMenu(hotelRes);
                break;
            case 'c':
                carMenu(carRes);
                break;
            default:
                break;
        }
        cout << endl;
        cout << "a. Airline" << endl;
        cout << "b. Hotel" << endl;
        cout << "c. Car Rental" << endl;
        cout << "d. Exit" << endl;
        cout << "Please select the type of reservation: ";
        cin >> option;
        getchar();
        cout << endl;

    } while (option != 'd');


    return 0;
}
