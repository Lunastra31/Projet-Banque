#include <iostream>
#include <string>
#include "compte.hpp"
#ifndef LIVRETA_HPP
#define LIVRETA_HPP

using namespace std;

class LivretA :public Compte
{
private:
    double minMontant;

public:
    LivretA();
    LivretA(const LivretA &LA);
    virtual ~LivretA();
    LivretA &operator=(const LivretA &LA);
    virtual void OuvrirCompte() override;
    virtual double Deposer() override;
    virtual double Retirer();
    virtual double CalculInteret(double tauxInteret, double montant);
    virtual bool SupCompte();
    virtual void AfficherCompte(ostream &out) const override;
    
};
#endif