#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include "operation.hpp"
using namespace std;

#ifndef COMPTE_HPP
#define COMPTE_HPP

class Compte
{
private:
    double montant;                // Solde courant du compte
    double minOuverture;           // Montant minimum d'ouverture requis
    double plafondVirement;        // Limite de transfert
    double tauxInteret;            // Taux d'intérêt
    double plafondMontant;         // Limite de montant

protected:
    // need to add class Operation
    long int compteID;              // Identifiant du compte (12 chiffres)

    //Operation TabOp;

public:
    string typeCompte;
    tm DateOuverture;               // Date et heure d'ouverture du compte
    Compte();                                   // Constructeur par défaut
    Compte(const Compte &C);                    // Copier le constructeur
    Compte(tm DateOuverture, int long compteID, double montant = 0, double minOuverture = 0.0, double plafondVirement = 15000.0,
           double tauxInteret = 0.0, double plafondMontant = 0, string typeCompte = "vide");   // Constructeur paramétré
    virtual ~Compte();
    Compte &operator=(const Compte &C);

    virtual void OuvrirCompte(); // no need istream &in as we don't ask client to fill?           // Ouvrir un compte (nécessite d'ajouter un gestionnaire)
    tm GenererDate() const;
    long int GenererCompteID() const   ;

    virtual double Deposer();           // Déposer de l'argent (sera remplacé par de l'argent virtuel pur après les tests)
    virtual double Retirer();           //
    virtual void FaireVirementInterne();
    virtual void AfficherCompte(ostream &out) const;  // Afficher les détails du compte
    virtual bool SupCompte(); // I THINK no need virtual                      // Fermer le compte (à transformer en compte virtuel pur après les tests)
    
    double GetMontant() const;                        // Obtenir le solde actuel
    double GetMinOuverture() const;                   // Obtenir le montant minimum d'ouverture
    double GetPlafondVirement() const;                // Obtenir la limite de transfert
    double GetTauxInteret() const;                    // Obtenir le taux d'intérêt
    double GetPlafondMontant() const;                 // Obtenir la limite du montant
    long int GetCompteID() const;                     // Obtenir l'identifiant du compte
    void SetMontant(double montant);                        
    void SetMinOuverture(double minOuverture);                   
    void SetPlafondVirement(double plafondVirement);                
    void SetTauxInteret(double tauxInteret);                    
    void SetPlafondMontant(double plafondMontant); 
    string GetTypeCompte();
    void SetTypeCompte(string typeCompte);
};

ostream &operator<<(ostream &out, const Compte &C);   // Opérateur de flux de sortie externe
// istream &operator>>(istream &in, Compte &C);          // Opérateur de flux d'entrée externe

// function polymorphisme by reference (to be called in main)
void CreerCompte(long int indexClient, Compte &C);
void AjoutOperation(string typeOp, long int compteIDSource, long int compteIDDestination, double montantOperation, long int indexClient, Compte &C);

#endif 
