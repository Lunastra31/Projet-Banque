
#include "compte.hpp"
#include <deque>
#include <ctime>
#ifndef COMPTE_COURANT_HPP
#define COMPTE_COURANT_HPP

class compteCourant : public Compte
{
private:
    double decouvertAutorise; // Découvert autorisé
    double agios;             // AGIOS forfaitaire ou proportionnel
    // bool hasChequeBook; // Présence d'un chéquier
    // bool hasCard; // Présence d'une carte de crédit ou de retrait
    // double guaranteeLimit; // Limite de garantie
    double limiteDeRetrait;   // Limite de retrait
    deque<pair<time_t, double>> historiqueRetrait; // Historique des retraits (paire de timestamp et montant)

public:
    // compteCourant(const long int &compteID, double decouvertAutorise, double agios,
    //               /*bool hasChequeBook, bool hasCard, double guaranteeLimit,*/ double limiteDeRetrait);
    compteCourant(); // constructeur par defaut
    virtual ~compteCourant();
    virtual void OuvrirCompte() override; 
    virtual double Deposer() override;
    virtual double Retirer() override;
    virtual void AfficherCompte(ostream &out) const; // override
    virtual bool SupCompte(); // override
    virtual void CalculerAgios(); // a coder s'il reste un peu de temps
    double getRetraitHebdo() const; // Getter pour le montant total des retraits de la semaine
};

#endif // COMPTE_COURANT_HPP
