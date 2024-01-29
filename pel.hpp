// JULIE LE SCAO
#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <cstring>
using namespace std;

#include "compte.hpp"

#ifndef PEL_HPP
#define PEL_HPP

class pel : public Compte // should we put virtual here?
{
        private:// double tauxInteret; // attribut dans parent // le taux d'interet pour la rémunération du PEL, une fois par ans le 31 décembre en point
        double virementMin; // le montant minimum du virement = 10
        int dureeDepot; // la durée de déposit en mois
        double montantDepot; // montant de dépot par rapport au durée (lié à dureeDepot)
        // int minOuverture; // attribut dans parent // le montant minimum à verser sur le compte pour l'ouverture
        // double plafondMontant; // attribut dans parent // la montant max que l'on peu déposer sur le compte

        public: 
        pel(); // constructeur par defaut
        pel(tm DateOuverture, long int compteID, double montant, double plafondVirement, double tauxInteret, int dureeDepot, 
        double montantDepot, double virementMin = 10.0, double minOuverture = 225.0, double plafondMontant = 61200.0, string typeCompte="PEL"); // constructeur par parametre
        // note cut from param : double montant, double plafondVirement, tm DateOuverture, double tauxInteret,
        pel(const pel &P); // constructeur par copie
        virtual ~pel(); // destructeur

        pel &operator=(const pel &P); // affectation

        virtual void OuvrirCompte() override; // 
        virtual double Deposer() override; // override on ne peut que déposer de l'argent sur le PEL, pas retirer, sauf à la cloture
        virtual double Retirer() override;
        virtual bool SupCompte(); // override
        virtual void AfficherCompte(ostream &out) const; // override
        // int Age(); // desactive pour le moment
        // 2% taux d'intérêts si PEL ouvert avant et après 1 janvier 2023
        // 1% pour ceux ouverts entre 1 aout 2016 - 1 janvier 2023
        // 0.5% avant 1 aout 2016
        // double CalculInteret(); // ça va retourner la valeur d'intérêt
        // double CalculMontantDepot();
	double GetVirementMin() const; 
        int GetDureeDepot() const;
        double GetMontantDepot() const;
        void SetVirementMin(double virementMin);
        void SetDureeDepot(int dureeDepot);
        void SetMontantDepot(double montantDepot);
};

#endif

