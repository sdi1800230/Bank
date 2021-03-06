#ifndef CASHIER_H
#define CASHIER_H

#include <iostream>

using namespace std;

class Cashier 
{
    bool isOpen, isFree;
    int customers_served, L;

    public : 
        Cashier(const int & L) : isOpen(false), isFree(true), customers_served(0), L(L) {} 

        void open(){isOpen = true; customers_served = 0;}
        void close(){isOpen = false;}
        void serve(){isFree = false;}
        
        bool free() // It returns false when the cashier close because it overworked
        {
            isFree = true; 
            customers_served++; 
            if(customers_served == L)
            {
                this->close();
                cout << "The cashier closed because it overworked!" << endl;
                customers_served = 0;
                return false;
            }
            return true;
        }

        bool is_open() const {return isOpen;}
        bool is_free() const {return isFree;}
};

#endif