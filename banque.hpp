#include <iostream>
#include <vector>
#include "client.hpp"

using namespace std;

class Banque
{
private:
    string nom;
    // static int nbClients;
protected:
    vector<Client> TabClients;
public:
    Banque(string nom);
    Banque(const Banque &B);
    //void AfficherClient();
    //void AfficherArgent();
    ~Banque();
    int rechercheIndexClient(const vector<Client> TabClients);
    // int rechercheIndexCompte(const Compte &C); // should this be in classe Client?
};

