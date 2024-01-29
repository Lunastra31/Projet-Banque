#include "compteCourant.hpp"
#include <iostream>
using namespace std;

compteCourant::compteCourant():Compte()
{
    decouvertAutorise = 500.0; 
    agios = 0.1;
    limiteDeRetrait = 500.0;
    //Compte::SetTauxIntere(0); TauxInteret est privé
}
    // compteCourant::compteCourant(tm DateOuverture, long int compteID, double montant, double plafondVirement, 
    //                             double tauxInteret, double plafondMontant, double agios, /*bool hasChequeBook, bool hasCard, double guaranteeLimit, */double limiteDeRetrait)
    //     :Compte(compteID), decouvertAutorise(decouvertAutorise), agios(agios),/*
    //       hasChequeBook(hasChequeBook), hasCard(hasCard), guaranteeLimit(guaranteeLimit),*/
    //       limiteDeRetrait(limiteDeRetrait) {}

compteCourant::~compteCourant() {}


void compteCourant::OuvrirCompte()
{   
    compteCourant(); 
}


double compteCourant::Deposer() 
{   
    double montant = Compte::GetMontant();
    double depot;
    cout<<"Combien voulez-vous déposer ?"<<endl;
    cin>>depot;
    montant = montant+depot;
    SetMontant(montant);
    return montant;
}

double compteCourant::Retirer() 
{
    double montant;
    time_t currentTime = time(nullptr); // Obtient le timestamp actuel

    // Supprime les retraits datant de plus de 7 jours
    while (!historiqueRetrait.empty() && currentTime - historiqueRetrait.front().first >= 7 * 24 * 60 * 60)
    {
        historiqueRetrait.pop_front();
    }

    // Calcule le montant total des retraits effectués au cours des 7 derniers jours
    double totalRetrait = 0.0;
    for (const auto& retrait : historiqueRetrait)
    {
        totalRetrait += retrait.second;
    }

    if (montant <= GetMontant() + decouvertAutorise && montant <= limiteDeRetrait && totalRetrait + montant <= 500.0) {
        montant = Compte::Retirer(); // ApcompteCourantle la fonction de retrait de la classe de base
        return montant;
        // Ajoute le retrait actuel à l'historique
        historiqueRetrait.push_back(make_pair(currentTime, montant));
    } else {
        cout << "Le montant du retrait dépasse la limite autorisée ou la limite de retrait hebdomadaire." << endl;
        return montant;
    }
}

void compteCourant::AfficherCompte(ostream &out) const
{
    Compte::AfficherCompte(out);
    out << "Le découvert autorisé est de : " << decouvertAutorise << "€" << endl;
    out << "Les AGIOS sont à : " << agios << "€" << endl;
    out << "Le montant limite de retrait est de " << limiteDeRetrait << "€" << endl;
}

bool compteCourant::SupCompte()
{    
    int reponse;
    double montant = Compte::GetMontant();
    cout << "Votre compte va être fermé, il reste : "<< montant << "€." << endl;
    cout << "Quelle opération vous voulez effectuer ?: " << endl;
    do
    {   
        cout << "1. Clôturer" << endl << "2. Retirer l'argent et clôturer" << endl;
        cin >> reponse;

        switch (reponse)
        {
            case 1 : // clôturer
            {
                compteCourant::~compteCourant();
                cout << "Le compte courant est supprimé."<<endl;
            }    
                break;
            case 2 :
            {   
                double montant = Compte::GetMontant();
                cout << "Vous allez retirer :" << montant << endl;
                montant = 0;
                compteCourant::~compteCourant(); 
                cout << "L'argent a été retiré et le compte courant est supprimé."<<endl;
            }
                break;
            default :
            {
                cout << "Vous n'avez pas saisi le bon chiffre, merci de recommencer.";
                break;
            }
        }
    } while ((reponse != 1) || (reponse != 2));
    return false;
}


double compteCourant::getRetraitHebdo() const
{
    time_t currentTime = time(nullptr); // Obtient le timestamp actuel

    // Supprime les retraits datant de plus de 7 jours
    deque<pair<time_t, double>> tempHistory = historiqueRetrait;
    while (!tempHistory.empty() && currentTime - tempHistory.front().first >= 7 * 24 * 60 * 60)
    {
        tempHistory.pop_front();
    }

    // Calcule le montant total des retraits effectués au cours des 7 derniers jours
    double totalRetrait = 0.0;
    for (const auto& retrait : tempHistory)
    {
        totalRetrait += retrait.second;
    }

    return totalRetrait;
}
void compteCourant::CalculerAgios()
    {
        cout << "Pour le moment, les AGIOS sont offerts ! "<< endl;
    }






