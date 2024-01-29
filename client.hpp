#include "compte.hpp"
#include <vector>

#ifndef CLIENT_HPP
#define CLIENT_HPP

class Client
{
private:
    string nomClient;
    string prenom;
    string adresse;
protected:
    int clientID;

public:
    vector <Compte> TabComptes;
    Client();
    Client(string nomClient, string prenom, string adresse, int clientID);
    Client(const Client &Cl);
    Client &operator=(const Client &Cl);
    ~Client();
    void AfficherAgeCompte();

    void CreerClient();
    void ModifierClient(Client &Cl);
    void AfficherClient();
    bool SupClient();
    void AfficherTTCompte();
    int rechercheIndexCompte(const vector<Compte> TabComptes);

    int getClientID() const;
    string getNomClient() const;
    string getPrenom() const;
    string getAdresse() const;
};
#endif
