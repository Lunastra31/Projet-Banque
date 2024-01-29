#include "compteBloque.hpp"
#include <iostream>

CompteBloque::CompteBloque():Compte()
{
    limiteDeRetrait = 500.0;
}

// CompteBloque::CompteBloque(const CompteBloque &CB) : Compte(CB)
// {
//     plafondRetrait = CB.plafondRetrait;     // en anglais : withdrawalLimit
//     retraitHebdo = CB.retraitHebdo; // en anglais : weeklyWithdrawal

// #ifdef DEBUG
//     cout << "Constructeur compte bloqué par copie" << endl;
// #endif
// }

// CompteBloque::CompteBloque(string typeCompte) : CompteCourant(typeCompte)
// {
// #ifdef DEBUG
//     cout << "Constructeur compte bloqué par param" << endl;
// #endif
// }

CompteBloque::~CompteBloque()
{
#ifdef DEBUG
    cout << "Desctructeur compte bloqué" << endl;
#endif
}

void CompteBloque::OuvrirCompte(istream &in)
{
    Compte::OuvrirCompte();
}

double CompteBloque::Deposer()
{
    double montant = Compte::GetMontant();
    double tempMontant;
    cout << "Combien d'argent voulez vous déposer: " << endl; // << typeCompte (take typeCompte)
    cin >> tempMontant;
    montant += tempMontant;
    return tempMontant;
}

double CompteBloque::Retirer()
{
    double montant = Compte::GetMontant();
    double tempRetrait;
    cout << "Combien d'argent voulez-vous retirer?: " << endl;
    cin >> tempRetrait;
    // ValiderRetrait(tempRetrait);

    montant -= tempRetrait;
    return tempRetrait;
}

void CompteBloque::AfficherCompte(ostream &out) const
{
    Compte::AfficherCompte(out);
}

bool CompteBloque::SupCompte()
{
    CompteBloque::~CompteBloque();
    return false;
}

// void CompteBloque::ValiderRetrait(double tempRetrait)
// {
//     static int ctr; // counter

//     if (tempRetrait <= 0)
//     {
//         cout << "Montant invalide. Veuillez entrer un montant positif." << endl;
//     }

//     if (tempRetrait > (plafondRetrait - retraitHebdo))
//     {
//         cout << "Retrait impossible car ça dépasse de limite de retraite 7 jours consécutives." << endl;
//         cout << "Montant restant pour retirer est: " << plafondRetrait - retraitHebdo << endl;
//     }

//     if (joursRestants == 0)
//     {
//         cout << "Retrait impossible. Limite de retrait sur 7 jours consecutifs atteinte." << endl;
//         return;
//     }

//     solde -= montant;
//     limiteRetraitJournalier -= montant;
//     joursRestants--;

//     cout << "Retrait effectue : " << montant << " euros." << endl;
// }