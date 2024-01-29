#include "banque.hpp"
#include "client.hpp"
#include "pel.hpp"
#include "livreta.hpp"
#include "compteBloque.hpp"
#include "compteCourant.hpp"
#include <stdlib.h>

int main() 
{

    // // TEST to create PEL
    // pel P;
    // double montant;
    // CreerCompte(123, P);
    // P.AfficherCompte(cout);

    // // TEST deposer and retirer PEL
    // AjoutOperation("Deposer", 123, 123, 100, 111, P);
    // montant = P.GetMontant();
    // cout << "Check if the new balance is correct: " << montant << endl;
    // AjoutOperation("Retirer", 123, 123, 100, 111, P);
    // montant = P.GetMontant();
    // cout << "Check if the new balance is correct: " << montant << endl;

    int choice;
    int subChoice;
    bool exit = false;
    bool exit2 = false;
    bool choixSupprimer;
    int indexClient;
    int indexCompte;
    vector<Compte> TabComptes;
    vector<Client> TabClients;
    Banque DreamTeam("DreamTeam");

    while (exit == false) 
    {
        // Affichage du menu principal
        cout <<"________________________________"<<endl;
        cout <<"\tDreamTeam Bank"<<endl;
        cout <<"________________________________"<<endl;
        cout << "MENU PRINCIPAL :\n";
        cout << "1. CRÉER UN CLIENT\n";
        cout << "2. VISUALISER UN CLIENT\n";
        cout << "3. GÉRER UN CLIENT\n";
        cout << "4. SUPPRIMER LE CLIENT\n";
        cout << "5. QUITTER L'APPLICATION\n\n";
        cout << "Entrez votre choix : ";
        cin >> choice;

        // Traitement du choix de l'utilisateur
        switch(choice) 
        {
            case 1: // Code pour créer un client
                    {
                        cout << "Option 1 : CRÉER UN CLIENT\n";
                        Client C;
                        C.CreerClient();
                        TabClients.push_back(C);
                    }                        break;
            case 2:            
                    {
                        cout << "Option 2 : VISUALISER UN CLIENT\n";
                        indexClient = DreamTeam.rechercheIndexClient(TabClients);
                        if (indexClient != -1)
                        {
                            TabClients[indexClient].AfficherClient();
                        }
                        break;
                    }

            case 3: // Sous-menu pour gérer un client
                    // on choisi sur quel client on va travailler
                    {
                        exit2 == false;
                        indexClient = DreamTeam.rechercheIndexClient(TabClients);
                        TabClients[indexClient].AfficherClient();

                        while (exit2 == false) 
                        {
                            if (TabClients[indexClient].TabComptes.empty())
                            {
                                cout << "_____________________________________________________" << endl;
                                cout << "Ce client n'a pas encore un compte dans cette banque !" << endl;
                            } 
                            // Affichage du sous-menu
                            cout << "Sous-menu : GÉRER UN CLIENT\n";
                            cout << "1. OUVRIR UN COMPTE\n";
                            cout << "2. DÉPOSER\n";
                            cout << "3. RETRAIT\n";
                            cout << "4. CALCULER LES INTÉRÊTS\n";
                            cout << "5. AFFICHER LES COMPTES DU CLIENT\n";
                            cout << "6. VÉRIFIER LE COMPTE À DÉCOUVERT\n";
                            cout << "7. AFFICHER L'ÂGE DU COMPTE\n";
                            cout << "8. REVENIR AU MENU PRINCIPAL\n\n";
                            cout << "Entrez votre choix : ";
                            cin >> subChoice;

                            // Traitement du choix du sous-menu
                            switch (subChoice) 
                            {
                                case 1: // Code pour ouvrir un compte
                                {
                                    int choixTypeCpt;           
                                    cout << "Option 1 : OUVRIR UN COMPTE \n";
                                    do
                                    {
                                        cout << "Tapez le chiffre correspondant pour ouvrir un compte : \n" << "1. COMPTE COURANT \n"
                                            << "2. COMPTE BLOQUE \n" << "3. LIVRET A \n" << "4. PEL \n";
                                        cin >> choixTypeCpt;

                                        // Compte *newCompte; // la classe Compte est abstraite on doit créer un pointeur

                                        switch (choixTypeCpt)
                                        {
                                        case 1: // Compte Courant
                                                {
                                                Compte *ptr;
                                                ptr = new compteCourant;
                                                CreerCompte(indexClient, *ptr);
                                                //ptr->AfficherCompte(cout);
                                                TabClients[indexClient].TabComptes.push_back(*ptr);
                                                delete ptr;
                                                }
                                                break;
                                        case 2: // Compte Bloque
                                                {
                                                Compte *ptr;
                                                ptr = new CompteBloque;
                                                CreerCompte(indexClient, *ptr);
                                                //ptr->AfficherCompte(cout);
                                                TabClients[indexClient].TabComptes.push_back(*ptr);
                                                delete ptr;
                                                }
                                                break;
                                        case 3: // Livret A
                                                {
                                                    Compte *ptr;
                                                    ptr = new LivretA;
                                                    CreerCompte(indexClient, *ptr);
                                                    ptr->AfficherCompte(cout);
                                                    TabClients[indexClient].TabComptes.push_back(*ptr);
                                                    delete ptr;
                                                }
                                                break;
                                        case 4: // PEL
                                                {
                                                    // int sizeTabComptes = TabClients[indexClient].TabComptes.size();
                                                    // TabClients[indexClient].TabComptes[sizeTabComptes+1] *ptr;
                                                    Compte *ptr;
                                                    ptr = new pel;
                                                    CreerCompte(indexClient, *ptr);
                                                    //ptr->AfficherCompte(cout);
                                                    TabClients[indexClient].TabComptes.push_back(*ptr); // NOT SURE IF THIS WORKS
                                                    delete ptr;
                                                }
                                                break;
                                        default:
                                                cout << "Choix invalide. Veuillez réessayer.\n";
                                                break;
                                        }
                                    } while ((choixTypeCpt != 1) && (choixTypeCpt != 2 )&& (choixTypeCpt != 3 )&& (choixTypeCpt != 4));
                                } break;

                                case 2: // Code pour déposer de l'argent
                                {
                                    cout << "Option 2 : DÉPOSER\n";
                                    // double montantDepot;
                                    cout << "check if indexClient est bon: " << indexClient << endl;
                                    indexCompte = TabClients[indexClient].rechercheIndexCompte(TabComptes);
                                    cout << indexCompte;
                                    if (indexCompte >0)
                                        {
                                            // AjoutOperation("Deposer", 0, 0, 0, indexClient, TabComptes[indexCompte]);
                                            TabComptes[indexCompte].Deposer();
                                            // montantDepot=TabComptes[indexCompte].Deposer(); 
                                        }
                                } break;

                                case 3: // Code pour effectuer un retrait
                                {
                                    cout << "Option 3 : RETRAIT\n"; 
                                    indexCompte = TabClients[indexClient].rechercheIndexCompte(TabComptes);
                                    if (indexCompte != -1)
                                        {
                                            AjoutOperation("Retirer", 0, 0, 0, indexClient, TabComptes[indexCompte]);
                                            // TabCompte[indexCompte].Retirer(TabCompte[indexCompte].GetMontant()); 
                                        }
                                }  break;

                                case 4: // Code pour calculer les intérêts
                                {
                                    cout << "Option 4 : CALCULER LES INTÉRÊTS\n";
                                    indexCompte = TabClients[indexClient].rechercheIndexCompte(TabComptes);
                                    if (indexCompte != -1)
                                    {
                                            // TabCompte[indexCompte].Retirer(TabCompte[indexCompte].GetMontant()); 
                                    }
                                } break;

                                case 5: // Code pour afficher des informations sur le compte 
                                {
                                    cout << "Option 5 : AFFICHER DES INFORMATIONS SUR UN COMPTE\n";
                                    TabClients[indexClient].AfficherTTCompte();
                                }   break;
                                          
                                case 6: // Code pour vérifier le compte à découvert et calculer l'AGIOS
                                        cout << "Option 6 : VÉRIFIER LE COMPTE À DÉCOUVERT\n";
                                        break;
                                case 7: // Code pour afficher l'âge du compte
                                        cout << "Option 7 : AFFICHER L'ÂGE DU COMPTE\n";
                                        TabClients[indexClient].AfficherAgeCompte();
                                        break;
                                case 8: // Revenir au menu principal
                                        cout << "Retour au MENU PRINCIPAL\n";
                                        // Sortir de la boucle du sous-menu si l'utilisateur a choisi de revenir au menu principal
                                        exit2 = true;
                                        break;
                                default:
                                    cout << "Choix invalide. Veuillez réessayer.\n";
                                    break;
                            }
                        }
                    }break;

            case 4: // Code pour supprimer le client
                    {
                        cout << "Option 4 : SUPPRIMER LE CLIENT\n";
                        indexClient = DreamTeam.rechercheIndexClient(TabClients);
                        if (indexClient != -1)
                        {
                            TabClients[indexClient].SupClient();
                            #ifdef DEBUG
                            cout << "choix supprimé: " << choixSupprimer << endl;
                            #endif
                            if (choixSupprimer == 0)
                                {
                                    TabClients.erase(TabClients.begin()+indexClient);
                                    cout << "Client supprimé" << endl;
                                }
                        }
                        break;
                    }
            case 5: // Quitter l'application
                    {
                        cout << "Option 5 : QUITTER L'APPLICATION\n";
                        exit = true;
                        break;
                    }
            default:
                    cout << "Choix invalide. Veuillez réessayer.\n";
                    break;
        }
    }
}
