#include "client.hpp"
#include <iostream>

Client::Client()
{
    nomClient = "DOE";
    prenom = "John";
    adresse = "2 rue des Licornes 31200 Denoraive";
    clientID = 000000000;
}

Client::Client(string nomClient, string prenom, string adresse, int clientID)
{
    this->nomClient = nomClient;
    this->prenom = prenom;
    this->adresse = adresse;
    this->clientID = clientID;
}
Client::Client(const Client &Cl)
{
    nomClient = Cl.nomClient;
    prenom = Cl.prenom;
    adresse = Cl.adresse;
    clientID = Cl.clientID;
}
Client &Client::operator=(const Client &Cl)
{
    this->nomClient = Cl.nomClient;
    this->prenom = Cl.prenom;
    this->adresse = Cl.adresse;
    this->clientID = Cl.clientID;
    return *this;
}
void Client::CreerClient()
{
    getchar(); // pour capter le enter en tapant le choix du menu
    cout << "Saisir le nom du client :" << endl;
    getline(cin, nomClient);
    // #ifdef DEBUG
    //     cout << nomClient << endl;
    // #endif

    cout << "Saisir le prénom du client :" << endl;
    getline(cin, prenom);
    // #ifdef DEBUG
    //     cout << prenom << endl;
    // #endif

    cout << "Saisir l'adresse du client :" << endl;
    getline(cin, adresse);
    // #ifdef DEBUG
    //     cout << adresse << endl;
    // #endif

    srand(time(NULL));                         // initialise random by taking from today's date
    clientID = rand() % 900000000 + 100000000; // range 100000000 to 900000000
    // #ifdef DEBUG
    //     cout << clientID << endl;
    // #endif
}

void Client::AfficherTTCompte()
{
    int indexCompte = 0;
    for (auto it = TabComptes.cbegin(); it != TabComptes.cend(); ++it)
    {
        cout << "Compte" << indexCompte + 1 << endl;
        cout << "----------------------------------------" << endl;
        TabComptes[indexCompte].AfficherCompte(cout);
        indexCompte++;
    }
    // int choix;
    // string nomClientRecherche;
    // string prenomClientRecherche;
    // int ClientIDRecherche;
    // bool trouve;
    // vector <Client> TabClients;
    // int indexClient =0;
    // int tailleTabClient;
    // vector <Compte> TabCompte;
    // cout << "Voulez-vous chercher le client par: " << endl << "1. Nom et prenom du client" << endl
    //     << "2. ID du client" << endl;
    //     cin >> choix;
    //         switch (choix)
    //     {
    //     case 1:
    //     {
    //         getchar();
    //         cout << "Veuillez saisir le nom du client: " << endl;
    //         getline(cin, nomClientRecherche);
    //         cout << "Veuillez saisir le préno du client: " << endl;
    //         getline(cin, prenomClientRecherche);
    //         for (auto it = TabClients.cbegin(); it != TabClients.cend(); ++it)
    //         {
    //             // LIMITATION : s'il y a le même nom et prénom du client, cela va prendre le premier trouvé
    //             if ((it->getNomClient() == nomClientRecherche) && (it->getPrenom() == prenomClientRecherche))
    //             {
    //                 return indexClient;
    //                 trouve = true;
    //                 TabClients[indexClient].AfficherClient();

    //             }
    //             indexClient++;
    //         }
    //         if (trouve == false)
    //         {
    //             cout << "Ce client n'est pas enregistré dans la banque" << endl;
    //             return -1;
    //         }
    //         break;
    //     }
    //     case 2:
    //     {
    //         cout << "Veuillez saisir l'ID du client: " << endl;
    //         cin >> ClientIDRecherche;
    //         for (auto it = TabClients.cbegin(); it != TabClients.cend(); ++it)
    //         {
    //             if (it->getClientID() == ClientIDRecherche) // error due to nomClient private, try get? or put in public?
    //             {
    //                 return indexClient;
    //                 trouve = true;
    //             }
    //             indexClient++;
    //             TabClients[indexClient].AfficherClient();
    //         }
    //         if (trouve == false)
    //         {
    //             cout << "Ce client n'est pas enregistré dans la banque" << endl;
    //             return -1;
    //         }
    //         break;
    //     }
    //     default:
    //         cout << "Vous n'avez pas bien saisi le chiffre, veuillez resaisir" << endl;
    //         break;
    //     }
    // while (choix != 1 || choix !=2);
    // return -1;
}
void Client::ModifierClient(Client &Cl)
{
    cout << "Entrer la nouvelle adresse du client" << endl;
    cin >> adresse;
    this->adresse = Cl.adresse;
}
void Client::AfficherClient()
{
    cout << "Nom du client: " << nomClient << endl;
    cout << "Prénom du client: " << prenom << endl;
    cout << "L'adresse du client: " << adresse << endl;
    cout << "L'identifiant du client: " << clientID << endl;
}
void Client::AfficherAgeCompte()
{
int indexCompte = 0;
int ctrCompte = 0;
time_t today = time(NULL);
tm *DateToday = localtime(&today);
for (auto it = TabComptes.cbegin(); it != TabComptes.cend(); ++it)
{
cout << "Compte" << indexCompte + 1 << ": " << TabComptes[ctrCompte].GetCompteID() << " Age ==>" << DateToday->tm_year - TabComptes[indexCompte].DateOuverture.tm_year << endl;
ctrCompte++;
}
}
bool Client::SupClient()
{
    string reponse;
    do
    {
        cout << "Voulez vous supprimer le client ? O/N" << endl;
        cin >> reponse;

        if (reponse == "O" || reponse == "o" || reponse == "oui" || reponse == "Oui")
        {
// Client::~Client();
#ifdef DEBUG
            cout << "destrcuteur" << endl;
#endif

            return true;
        }
        else if (reponse == "N" || reponse == "n" || reponse == "non" || reponse == "Non")
        {
            cout << "Bien reçu votre commande de ne pas supprimer ce compte" << endl;
            return false;
        }
        else
            cout << "Vous n'avez pas bien saisi la bonne réponse, merci de taper O ou N" << endl;

    } while (reponse != "O" && reponse != "N" && reponse != "o" && reponse != "n" && reponse != "oui" && reponse != "non" && reponse != "Oui" && reponse != "Non");
    return false;
}

Client::~Client()
{
#ifdef DEBUG
    cout << "clap clap THANOS" << endl;
#endif
}

int Client::getClientID() const
{
    return clientID;
}
string Client::getNomClient() const
{
    return nomClient;
}
string Client::getPrenom() const
{
    return prenom;
}
string Client::getAdresse() const
{
    return adresse;
}

int Client::rechercheIndexCompte(const vector<Compte> TabComptes)
{
    long int CompteIDRecherche;
    int choixDeRecherche;
    int indexCompte = 0;
    bool trouve = true;

    cout << "Veuillez saisir l'ID du compte : " << endl;
    cin >> CompteIDRecherche; // can be filled automatically
    cout << "check size of tab: " << this->TabComptes.size() << endl;

    for (auto it = TabComptes.cbegin(); it != TabComptes.cend(); ++it) // why this code doesn't run?
    {
        cout << it->GetCompteID();
    }

    for (auto it = TabComptes.cbegin(); it != TabComptes.cend(); ++it)
    {
        if (it->GetCompteID() == CompteIDRecherche) // error due to nomClient private, try get? or put in public?
        {
            trouve = true;
            return indexCompte;
        }
        indexCompte++;
    }
    if (trouve == false)
    {
        cout << "Ce compte n'est pas enregistré sous ce client." << endl;
        return -1;
    }

    // for (vector<Compte>::iterator it = TabComptes.begin(); it != TabComptes.end(); ++it)
    // {
    //     cout << "affichage to test it->GetCompteID" << it->GetCompteID() << endl;
    //     cout << "affichage to test it->GetCompteID" << CompteIDRecherche << endl;
    //     if (it->GetCompteID() == CompteIDRecherche)
    //     {
    //         trouve = true;
    //         return indexCompte;
    //     }
    //     indexCompte++;
    // }
    // if (trouve == false)
    // {
    //     cout << "Ce compte n'est pas enregistré sous ce client." << endl;
    //     return -1;
    // }
    return -1;
}
