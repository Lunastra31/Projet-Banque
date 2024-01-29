
#include "compte.hpp"

// Fonction générer DateOuverture
tm Compte::GenererDate() const
{
    time_t t = time(NULL); // Obtenir la date du jour en time_t
    tm* today = localtime(&t); // Conversion de time_t en tm
    tm DateOuverture = *today;
    return DateOuverture;
    #ifdef DEBUG
    // Tester si nous avons récupéré la date correctement
    cout << DateOuverture.tm_mday << "/" << DateOuverture.tm_mon+1 << "/" << DateOuverture.tm_year+1900 << endl;
    #endif
}

// Fonction générer compteID
long int Compte::GenererCompteID() const
{
    srand(time(NULL)); // Initialize random number generator with today's date
    long int compteID = rand() % 900000000000 + 100000000000; // Range from 100000000000 to 999999999999
    return compteID;
}

// Opérateur d'insertion surchargé (<<) pour afficher les informations sur le compte
ostream &operator<<(ostream &out, const Compte &C)
{
    C.AfficherCompte(out);
    return out;
}

void CreerCompte(long int indexClient, Compte &C)
{
    C.OuvrirCompte();
    #ifdef DEBUG
    cout << "Creer compte poly par ref with function OuvrirCompte inside" << endl;
    #endif
}

// Opérateur d'extraction surchargé (>>) pour saisir les informations relatives au compte.
// istream &operator>>(istream &in, Compte &C)
// {
//     C.OuvrirCompte(in); // ça serait utilisé pour la classe dérivé
//     return in;
// }


// Fonction d'ouverture de compte
void Compte::OuvrirCompte()
{   
    #ifdef DEBUG
    cout << "We're inside function OuvrirCompte of classe Compte" << endl;
    #endif
    // //string typeCompte;
    // DateOuverture = GenererDate();
    // compteID = GenererCompteID();

    // time_t t = time(NULL); // Obtenir la date du jour en time_t
    // tm* today = localtime(&t); // Conversion de time_t en tm
    // DateOuverture = *today;
    // // Tester si nous avons récupéré la date correctement
    // cout << DateOuverture.tm_mday << "/" << DateOuverture.tm_mon+1 << "/" << DateOuverture.tm_year+1900 << endl;

    // // Générer un compteID aléatoire composé de 12 chiffres
    // srand(time(NULL)); // Initialize random number generator with today's date
    // compteID = rand() % 900000000000 + 100000000000; // Range from 100000000000 to 999999999999
}

// Constructeur par défaut
Compte::Compte()
{
    montant = 0.0;
    minOuverture = 0.0;
    plafondVirement = 15000.0;
    tauxInteret = 0.0;
    plafondMontant = 0.0;
    DateOuverture = GenererDate();
    compteID = GenererCompteID();
    typeCompte = "vide";
    // DateOuverture = GenererDate();
    // compteID = GetCompteID(); // need to validate if compteID has existed or not, if yes, recreate the rand

    #ifdef DEBUG
    cout << "constructeur compte par défault" << endl;
    #endif
}

// Copier le constructeur
Compte::Compte(const Compte &C)
{
    montant = C.montant;
    minOuverture = C.minOuverture;
    plafondVirement = C.plafondVirement;
    tauxInteret = C.tauxInteret;
    plafondMontant = C.plafondMontant;
    DateOuverture = C.DateOuverture;
    compteID = C.compteID;
    typeCompte=C.typeCompte;

    #ifdef DEBUG
    cout << "constructeur compte par copie" << endl;
    #endif
}

// Constructeur paramétré
Compte::Compte(tm DateOuverture, int long compteID, double montant, double minOuverture, double plafondVirement,
    double tauxInteret, double plafondMontant, string typeCompte)
{
    this->montant = montant;
    this->minOuverture = minOuverture;
    this->plafondVirement = plafondVirement;
    this->tauxInteret = tauxInteret;
    this->plafondMontant = plafondMontant;
    this->DateOuverture = DateOuverture;
    this->compteID = compteID;
    this->typeCompte= typeCompte;
    // DateOuverture = GenererDate();
    // compteID = GenererCompteID();

    #ifdef DEBUG
    cout << "constructeur compte par param" << endl;
    #endif
}

// Destructor
Compte::~Compte()
{
    #ifdef DEBUG
    cout << "destructeur compte" << endl;
    #endif
}

// Assignment operator
Compte &Compte::operator=(const Compte &C)
{
    montant = C.montant;
    minOuverture = C.minOuverture;
    plafondVirement = C.plafondVirement;
    tauxInteret = C.tauxInteret;
    plafondMontant = C.plafondMontant;
    typeCompte=C.typeCompte;
    return *this;
}

// Afficher les informations sur le compte
void Compte::AfficherCompte(ostream &out) const
{
    out << "Type du compte: " << typeCompte<< endl;
    out << "ID du compte: " << compteID<< endl;
    out << "Date d'ouverture: " << DateOuverture.tm_mday << "/" << DateOuverture.tm_mon+1 << "/" << DateOuverture.tm_year+1900 << endl;
    out << "Montant: " << montant << "€" <<endl;
    out << "Minimum montant d'ouverture: " << minOuverture << "€"<<endl;
    out << "Plafond de virement: " << plafondVirement <<"€"<< endl;
    out << "Taux d'intérêt: " << tauxInteret <<"%"<< endl;
    out << "Plafond montant de compte: " << plafondMontant<< "€" << endl;
}

bool Compte::SupCompte()
{
    return false;
}

// Fonction Getter pour montant
double Compte::GetMontant() const
{
    return montant;
}
// Fonction Getter pour minOuverture
double Compte::GetMinOuverture() const
{
    return minOuverture;
}

// Getter function pour plafondVirement
double Compte::GetPlafondVirement() const
{
    return plafondVirement;
}

// Getter function pour tauxInteret
double Compte::GetTauxInteret() const
{
    return tauxInteret;
}

// Getter function pour plafondMontant
double Compte::GetPlafondMontant() const
{
    return plafondMontant;
}

// Getter function pour compteID
long int Compte::GetCompteID() const
{
    return compteID;
}

void Compte::SetMontant(double montant)
{
    this->montant = montant;
}

void Compte::SetMinOuverture(double minOuverture)
{
    this->minOuverture = minOuverture;
}

void Compte::SetPlafondVirement(double plafondVirement)
{
    this->plafondVirement = plafondVirement;
}

void Compte::SetTauxInteret(double tauxInteret)
{
    this->tauxInteret = tauxInteret;
}

void Compte::SetPlafondMontant(double plafondMontant)
{
    this->plafondMontant = plafondMontant;
}

string Compte::GetTypeCompte()
{
    return typeCompte;
}

void Compte::SetTypeCompte(string typeCompte)
{
    this->typeCompte = typeCompte;
}

double Compte::Retirer()
{
    double retrait;
    cout<<"Combien voulez-vous retirer ?"<<endl;
    cin>>retrait;

    montant = montant -retrait;
    return montant;
}

double Compte::Deposer()
{
    // double montantOperation;
    // #ifdef DEBUG
    // cout << "Affichage pédagogique: ici la function Deposer de Compte parent" << endl;
    // #endif
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
    return montant;
}

void Compte::FaireVirementInterne()
{
    #ifdef DEBUG
    cout << "Affichage pédagogique: ici la function FaireVirementInterne de Compte parent" << endl;
    #endif
}

void AjoutOperation(string typeOp, long int compteIDSource, long int compteIDDestination, double montantOperation, long int indexClient, Compte &C)
{
    if (typeOp == "Deposer")
        C.Deposer();        
    if (typeOp == "Retirer")
        C.Retirer();
    if (typeOp == "Virement")
        C.FaireVirementInterne();
}