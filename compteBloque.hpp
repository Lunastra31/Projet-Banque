#include "compte.hpp"
#include <iostream>

#ifndef COMPTEBLOQUE_HPP
#define COMPTEBLOQUE_HPP

class CompteBloque : public Compte {

private:
    double limiteDeRetrait;
public:
    
    CompteBloque(); // constructeur par défaut
    // CompteBloque(const CompteBloque &CB); // constructeur par copie
    virtual ~CompteBloque(); // destructeur
    virtual void OuvrirCompte(istream &in); // override
    virtual double Deposer() override; 
    virtual double Retirer() override; // attention on ne peux pas passer le solde en négatif
    virtual void AfficherCompte(ostream &out) const; // override
    virtual bool SupCompte() override;  
    // void ValiderRetrait(double tempRetrait);
};

#endif // COMPTEBLOQUE_HPP
