/*
Nora Luna
CS 202
Program 2
manager.h

This file contains the function prototypes for the class manager 
functions. Each manager contains the data structure that its
specifc class is using. Airline is using the DLL template class. 
Hotel is using the STL list template class. Car is using the STL
array class. The CarManager also contains a static member to hold
the maximum size of the array and an integer to hold the actual size
of the array.
Each class has the ability to insert, remove, search, and display.
*/

#ifndef MANAGER_H
#define MANAGER_H

#include "reservation.h"
#include "DLL.h"
#include "node.h"
#include <list>
#include <array>


class AirlineManager
{
    protected:
        DLL<Airline> airlines;
    
    public:
        AirlineManager();
        ~AirlineManager();
        bool display();
        bool insert();
        bool remove();
        bool search();

};

class HotelManager 
{
    protected:
        list<Hotel> hotels;

        void display(list<Hotel>::iterator it);
        void remove(list<Hotel>::iterator it, string& target);
        Hotel* search(list<Hotel>::iterator it, string& target);

    public:
        HotelManager();
        ~HotelManager();
        void display();

        bool insert();
        void remove();
        void search();

};

class CarManager 
{
    protected:
        static const int MAX_ARRAY = 100;
        array<Car,MAX_ARRAY> cars;
        int size;

    public:
        CarManager();
        ~CarManager();
        void display();
        bool insert();
        void remove();
        void search();

};

#endif
