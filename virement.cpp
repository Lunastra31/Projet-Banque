#include "virement.hpp"

Virement::Virement(Compte* sender, Compte* receiver, double amount) {
    this->sender = sender;
    this->receiver = receiver;
    this->amount = amount;
}

void Virement::transferInternal() { //internal transfers within LA, CC and CB
    if (receiver->GetMontant() >= amount) {
        receiver->Retirer(amount);
        sender->Deposer(amount);
        cout << "Transfer successful!" << endl;
    } else {
        cout << "Insufficient funds in the receiver's account." << endl;
    }
}

void Virement::transferExternal() { //external transfers to other people's account
    if (sender->GetMontant() >= amount) {
        sender->Retirer(amount);
        cout << "Transfer successful!" << endl;
    } else {
        cout << "Insufficient funds in the sender's account." << endl;
    }
}
