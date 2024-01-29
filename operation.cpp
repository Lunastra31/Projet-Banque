#include "operation.hpp"

// Operation::Operation(const string& type, double amount)
// {
//     this->type = type;
//     this->amount = amount;
// }

// string Operation::GetType() const
// {
//     return type;
// }

// double Operation::GetAmount() const
// {
//     return amount;
// }






/* #include "operation.hpp"

Operation::Operation(string type, double amount, int clientID)
    : typeOp(type), montantOp(amount), clientID(clientID) {}

string Operation::GetType() const {
    return typeOp;
}

double Operation::GetAmount() const {
    return montantOp;
}

int Operation::GetClientID() const {
    return clientID;
}

void Compte::Compte(double initialAmount) : montant(initialAmount) {}

void Compte::Deposit(double amount) {
    montant += amount; // Add the deposited amount to the total
    operations.push_back(Transaction("Deposit", amount)); // Add a new deposit transaction to the vector
}

void Compte::Withdraw(double amount) {
    if (amount <= montant) { // Check if there are sufficient funds in the account
        montant -= amount; // Subtract the withdrawn amount from the total
        operations.push_back(Transaction("Withdraw", amount)); // Add a new withdrawal transaction to the vector
    } else {
        cout << "Insufficient funds." << endl; // Display an error message if there are insufficient funds
    }
}

void Compte::DisplayLastoperations(int numoperations) const 
{
    int size = operations.size(); // Get the total number of operations
    int start = (size > numoperations) ? size - numoperations : 0; // Calculate the starting index for displaying the last N operations
    for (int i = start; i < size; i++) // Iterate over the operations from the starting index to the end
    { 
        cout << "Transaction " << i + 1 << ": " << operations[i].GetType() << " - "
                  << operations[i].GetAmount() << endl; // Display the transaction type and amount
    }
}

 */




























/* void Operation::AjouterOp(const Operation &O, MesOperations)
    {            
            MesOperations.push_back(O);
    } */

    
    
/* #include "compte.hpp"

Transaction::Transaction(string type, double amount) : typeOp(type), montantOp(amount) {}

string Transaction::GetType() const {
    return typeOp;
}

double Transaction::GetAmount() const {
    return montantOp;
}

Compte::Compte(double initialAmount) : montant(initialAmount) {}

void Compte::Deposit(double amount) {
    montant += amount; // Add the deposited amount to the total
    operations.push_back(Transaction("Deposit", amount)); // Add a new deposit transaction to the vector
}

void Compte::Withdraw(double amount) {
    if (amount <= montant) { // Check if there are sufficient funds in the account
        montant -= amount; // Subtract the withdrawn amount from the total
        operations.push_back(Transaction("Withdraw", amount)); // Add a new withdrawal transaction to the vector
    } else {
        cout << "Insufficient funds." << endl; // Display an error message if there are insufficient funds
    }
}

void Compte::DisplayLastoperations(int numoperations) const {
    int size = operations.size(); // Get the total number of operations
    int start = (size > numoperations) ? size - numoperations : 0; // Calculate the starting index for displaying the last N operations
    for (int i = start; i < size; i++) { // Iterate over the operations from the starting index to the end
        cout << "Transaction " << i + 1 << ": " << operations[i].GetType() << " - "
                  << operations[i].GetAmount() << endl; // Display the transaction type and amount
    }
}
 */