#include "livreta.hpp"
#include "compte.hpp"

LivretA::LivretA():Compte()
{
    Compte::SetMinOuverture(10.0);
    Compte::SetTauxInteret(0.03);
    Compte::SetPlafondMontant(22950.0);
    minMontant = 10;
    typeCompte = "Livret A";
}
LivretA::LivretA(const LivretA &LA)
{
    // minOuverture = LA.minOuverture;
    // tauxInteret = LA.tauxInteret;
    // plafondMontant = LA.plafondMontant;ty
    typeCompte = LA.typeCompte;
}

LivretA::~LivretA()
{
    #ifdef DEBUG
    cout <<"clap clap THANOS"<<endl;
    #endif
}
LivretA &LivretA::operator=(const LivretA &LA)
{
    this->typeCompte= typeCompte;
    return *this;
}
void LivretA::OuvrirCompte()
{
    LivretA();
    int choixOuverture;
    double montantOuverture;
    do
    {
        cout << "Pour ouvrir un Livret A, il faut minimum " << Compte::GetMinOuverture() << "€. Combien d'argent voulez-vous mettre?" << endl;
        cin >> montantOuverture;
    } while(montantOuverture < 10.0 || montantOuverture > 22950.0); // minOuverture 225 and plafondMontant 61200
do
    {    
        cout << "Comment voulez-vous procéder?" << endl;
        cout << "1. Déposer l'argent" << endl << "2. Faire un virement de compte courant" << endl;
        cin >> choixOuverture;

        switch (choixOuverture)
        {
        case 1:
        {    
            // montantOuverture = Compte::GetMinOuverture();
            Compte::SetMontant(montantOuverture);
        }
            break;

        case 2:
        {    
            // montantOuverture = Compte::GetMinOuverture();
            // ATTENTION, à priori besoin function Virement qui débite le montant de CC et mets sur montant PEL
            Compte::SetMontant(montantOuverture); // temporairement utilise SetMontant
        }
            break;

        default:
            cout << "Vous n'avez pas saisi le bon choix" << endl;
            break;
        }
    } while(choixOuverture != 1 && choixOuverture != 2);
    #ifdef DEBUG
    double montant = Compte::GetMontant();
    cout << "Affichage pédagogique to check if the amount is added: " << montant << endl;
    #endif
}

double LivretA::Deposer()
{
    double montantOperation;
    double montant = Compte::GetMontant();
    cout << "Combien voulez-vous déposer ?" << endl;
    cin >> montantOperation;
    if (montant + montantOperation < 22950)
    {
        return montant+montantOperation;
    }
    else
    {
        cout<<"Dépôt refusé : plafond atteint"<<endl;
    }
    return montantOperation;
}

double LivretA::Retirer()
{
    double retrait;
    cout<<"Combien voulez-vous retirer ?"<<endl;
    cin>>retrait;
    double montant = GetMontant();
    if (montant - retrait < 10)
    {
        cout<<"Retrait refusé : solde insuffisant. Il faut avoir 10€ minimum dans votre livret A"<<endl;
        return retrait;
    }
    else
    {
        SetMontant(montant-retrait);
        return retrait;
    }
}

bool LivretA::SupCompte() // check after
{
    double montant = Compte::GetMontant();
    do
    {
        double retrait;
        cout<<"Combien voulez-vous retirer ?"<<endl;
        cin>> retrait;
        montant = montant - retrait;
    } while (montant !=0);
    LivretA::~LivretA();
    cout<<"Compte supprimé"<<endl;
    return false;
}
double LivretA::CalculInteret(const double tauxInteret, double montant)
{
    return montant*1.03;
}
void LivretA::AfficherCompte(ostream &out) const
{
    //Compte::AfficherCompte(out);
    out << minMontant << endl;
    // double taux;
    // taux = (tauxInteret -1)*100;
    // Compte::AfficherCompte(out);
    // cout<<"Informations Livret A :"<<endl;
    // cout<<"_______________________"<<endl;
    // cout<<"Minimum d'ouverture :"<<minOuverture<<endl;
    // cout<<"Taux d'intérêt :"<<taux<<endl;
    // cout<<"Plafond montant ;"<<plafondMontant<<endl;
}
