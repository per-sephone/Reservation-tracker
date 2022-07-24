/*
Nora Luna
CS 202
Program 2
manager.cpp

This file contains member functions for the class manager. Each 
class manager has the ability to insert, remove, search, and display.
AirlineManager contains the DLL template that I wrote. HotelManager
contains the STL template for list. CarManager contains the STL
template for array.
*/


#include "manager.h"


//AirlineManager member functions

//constructor
AirlineManager::AirlineManager()
{
}

//destructor
AirlineManager::~AirlineManager()
{
}

//display list
bool AirlineManager::display()
{
    try
    {
        airlines.display();
    }catch(...)
    {
        cout << endl << "Reservations list is empty." << endl;
    }
    return true;
}

//insert new reservation
bool AirlineManager::insert()
{
    //create a new object
    Airline newAirline;
    if(newAirline.makeReservation())
        airlines.insert(newAirline);

    return true;
}

//remove reservation by name 
bool AirlineManager::remove()
{
    string target;
    cout << "Enter the name you would like to remove: ";
    getline(cin, target);

    try
    {
        airlines.remove(target);
    } catch(string&)
    {
        cout << endl << "Reservation not found." << endl;
    }
    catch(...)
    {
        cout << endl << "List is empty." << endl;
    }
    return true;
}

//search reservation by name
bool AirlineManager::search()
{
    string target;
    cout << "Enter the name you would like to search: ";
    getline(cin, target);

    cout << endl;

    try
    {
        airlines.search(target)->display();

    }catch(string&)
    {
        cout << endl << "Reservation not found." << endl;
    }
    catch(...)
    {
        cout << endl << "List is empty." << endl;
    }
    return true;
}


//HotelManager member functions

//constructor
HotelManager::HotelManager()
{
}

//destructor
HotelManager::~HotelManager()
{
}

//displays the list, wrapper function
void HotelManager::display()
{

    if(hotels.empty())
        cout << endl << "Reservation list is empty." << endl;


    display(hotels.begin());

}

//displays the list, recursive function
void HotelManager::display(list<Hotel>::iterator it)
{
    //base case
    if(it == hotels.end())
    {
        return;
    }

    cout << *it << endl;
    display(it++);
}

//insert a new object into the list
bool HotelManager::insert(void)
{
    //create a new object
    Hotel newHotel;

    newHotel.makeReservation();
    hotels.push_back(newHotel);     

    return true;
}

//remove from the list, wrapper function
void HotelManager::remove()
{
    string target;
    cout << "Enter the name you would like to remove: ";
    getline(cin, target);

    if(hotels.empty())
        cout << endl << "Reservation list is empty." << endl;

    else
    {
        try
        {
            remove(hotels.begin(), target); 
        } catch(string&)
        {
            cerr << endl << "Reservation not found." << endl;
        }
    }

}

//remove from the list recursive function
void HotelManager::remove(list<Hotel>::iterator it, string& target)
{
    //base case
    if(*it == target)
    {
        hotels.erase(it);
        return;
    }

    //end of the list, item not found
    if(it == hotels.end() && *it != target)
        throw target;

    it++;
    remove(it, target);
}

//search for item using name, wrapper function
void HotelManager::search()
{
    string target;
    cout << "Enter the name you would like to search: ";
    getline(cin, target);

    cout << endl;

    if(hotels.empty())
        cout << endl << "Reservation list is empty." << endl;

    else
    {
        try
        {
            cout << *(search(hotels.begin(), target)) << endl; 
        } catch(string&)
        {
            cerr  << endl << "Reservation not found." << endl;
        }

    }
}

//search for item using name, returns pointer to item, recursive function
Hotel* HotelManager::search(list<Hotel>::iterator it, string& target)
{
    Hotel* ptr = &*it;
    //base case
    if(*ptr == target)
        return ptr;

    //end of the list, item not found
    if(it == hotels.end() && *ptr != target)
        throw target;

    it++;
    return search(it, target);

}


//CarManager member functions

//constructor
CarManager::CarManager() :size(0)
{
}

//destructor
CarManager::~CarManager()
{
}

//displays reservations
void CarManager::display()
{
    if(size == 0)
        cout << endl << "Reservation list is empty." << endl;
    else
    {
        for(auto i = 0; i < size; ++i)
            cout << cars.at(i) << endl;
    }
}

//inserts a new reservation into the list
bool CarManager::insert()
{
    //create a new object
    Car newCar;
    newCar.makeReservation();
    cars.at(size) = newCar;
    size++;
    return true;
}

//removes reservation by name 
void CarManager::remove()
{
    bool found = false;
    string target;
    cout << "Enter the name you would like to remove: ";
    getline(cin, target);

    if(size == 0)
        cout << endl << "Reservation list is empty." << endl;
    else if(size == 1)
        size--;
    else
    {
        for(auto i = cars.begin(); i != cars.end(); ++i)
        {
            if(*i == target)
            {
                if(i != cars.end())
                {
                    *i = *(i+1);
                }
                size--;
                found = true;
                break;    
            }
        }
        if(found == false)    
            cout << endl << "Reservation not found." << endl;
    }
}



//searchs by name
void CarManager::search()
{
    string target;
    cout << "Enter the name you would like to search: ";
    getline(cin, target);
    bool found = false;

    cout << endl;

    if(size == 0)
        cout << endl << "Reservation list is empty." << endl;
    else
    {
        for(auto i = cars.begin(); i != cars.end(); ++i)
        {
            if(*i == target)
            {
                cout << *i << endl;
                found = true;
                break;
            }
        }
        if(found == false)
            cout << endl << "Reservation not found." << endl;
    }
}


