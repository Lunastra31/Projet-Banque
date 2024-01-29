#include <iostream>
#include "compte.hpp"

#ifndef VIREMENT_HPP
#define VIREMENT_HPP
using namespace std;
class Virement {
private:
    Compte* sender;  // Sender's account
    Compte* receiver;  // Receiver's account
    double amount;  // Amount to transfer

public:
    Virement(Compte* sender, Compte* receiver, double amount);
    void transferInternal();
    void transferExternal();
};

#endif
