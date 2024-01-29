#include "banque.hpp"

Banque::Banque(string nom)
{
    nom = "DreamTeam Bank";
    // nbClients++;
}

Banque::Banque(const Banque &B)
{
    nom = B.nom;
    // nbClients = B.nbClients;
}
Banque::~Banque()
{
    #ifdef DEBUG
    cout <<"clap clap THANOS"<<endl;
    #endif
}

int Banque::rechercheIndexClient(const vector<Client> TabClients)
{
    string nomClientRecherche;
    string prenomClientRecherche;
    long int ClientIDRecherche;
    int choixDeRecherche;
    int tailleTabClients;
    int indexClient = 0;
    bool trouve = false;
    // tailleTabClients = TabClients.size();
    
    do
    {
        cout << "Voulez-vous chercher le client par: " << endl << "1. Nom et prenom du client" << endl
        << "2. ID du client" << endl;
        cin >> choixDeRecherche;
        
        switch (choixDeRecherche)
        {
        case 1:
        {   
            getchar();
            cout << "Veuillez saisir le nom du client: " << endl;
            getline(cin, nomClientRecherche);
            cout << "Veuillez saisir le prénom du client: " << endl;
            getline(cin, prenomClientRecherche);
            for (auto it = TabClients.cbegin(); it != TabClients.cend(); ++it)
            {
                // LIMITATION : s'il y a le même nom et prénom du client, cela va prendre le premier trouvé
                if ((it->getNomClient() == nomClientRecherche) && (it->getPrenom() == prenomClientRecherche))
                {
                    trouve = true;
                    return indexClient;
                }
                indexClient++;
            }
            if (trouve == false)
            {
                cout << "Ce client n'est pas enregistré dans la banque" << endl;
                return -1;
            }
            break;
        }
        case 2:
        {   
            cout << "Veuillez saisir l'ID du client: " << endl;
            cin >> ClientIDRecherche;
            for (auto it = TabClients.cbegin(); it != TabClients.cend(); ++it)
            {                
                if (it->getClientID() == ClientIDRecherche) // error due to nomClient private, try get? or put in public?
                {
                    return indexClient;
                    trouve = true;
                }
                indexClient++;
            }
            if (trouve == false)
            {
                cout << "Ce client n'est pas enregistré dans la banque" << endl;
                return -1;
            }
            break;
        }
        default:
            cout << "Vous n'avez pas bien saisir le chiffre, veuillez resaisir" << endl;
            break;
        }
    } while (choixDeRecherche != 1 || choixDeRecherche !=2);
    return -1;
}
