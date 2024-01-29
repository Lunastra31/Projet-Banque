#include "pel.hpp"

pel::pel():Compte()
{
    virementMin = 10.0; 
    dureeDepot = 0;
    montantDepot = 0.0;
    Compte::SetPlafondMontant(61200.0); // plafondMontant est privé
    Compte::SetMinOuverture(225.0); // plafondMontant est privé
    typeCompte = "PEL";
}

pel::pel(tm DateOuverture, long int compteID, string typeCompte, double montant, double plafondVirement, double tauxInteret, 
int dureeDepot, double montantDepot, double virementMin, double minOuverture, double plafondMontant):Compte(DateOuverture, compteID, 
montant, minOuverture, plafondVirement, tauxInteret, plafondMontant)
{
    // Compte::SetMinOuverture(minOuverture); // besoin de modifier la valeur dans le constructeur de Compte
    // Compte::SetPlafondMontant(plafondMontant); // besoin de modifier la valeur dans le constructeur de Compte
    // Compte::SetMontant(montant);
    // Compte::SetPlafondVirement(plafondVirement);
    // Compte::SetTauxInteret(tauxInteret); 
    this->DateOuverture = DateOuverture;
    this->compteID = compteID;
    this->dureeDepot = dureeDepot;
    this->montantDepot = montantDepot;
    this->typeCompte= typeCompte;
    
    #ifdef DEBUG
        cout <<"constructeur par parametre"<<endl; // affichage pédagogique
    #endif
}

pel::pel(const pel &P):Compte(P)
{
    // récupère et affecte avec Get et Set car ce sont des attributs privés
    double montant = P.GetMontant();
    double plafondVirement = P.GetPlafondVirement();
    double minOuverture = P.GetMinOuverture();
    double plafondMontant = P.GetPlafondMontant();
    double tauxInteret = P.GetTauxInteret();
    this->SetMontant(montant);
    this->SetPlafondVirement(plafondVirement);
    this->SetMinOuverture(minOuverture);
    this->SetPlafondMontant(plafondMontant);
    this->SetTauxInteret(tauxInteret);
    this->DateOuverture = P.DateOuverture; // possible car c'est protected
    // attributs privés dans PEL
    this->virementMin = P.virementMin;
    this->dureeDepot = P.dureeDepot;
    this->montantDepot = P.montantDepot;        
}

pel::~pel()
{
    #ifdef DEBUG
    cout <<"destructeur"<<endl; // affichage pédagogique
    #endif
}
pel &pel::operator=(const pel &P)
{   
    Compte *C;
    const Compte *C1;
    C = this;
    C1 = &P;
    *C = *C1;
    this->virementMin = P.virementMin;
    this->dureeDepot = P.dureeDepot;
    this->montantDepot = P.montantDepot;
    this->typeCompte = P.typeCompte;
    return *this;
}

void pel::OuvrirCompte()
{   
    // I THINK SHOULD'T CREATE OBJECT PEL HERE BUT HOW COULD I USE THE IN??? CAUSE IN PEL FOR EXAMPLE WE ONLY NEED MINOUVERTURE
    // THE REST COULD STAY AT DEFAULT VALUE
    // MAYBE DONT USE ISTREAM AND USE DIRECTLY CONST COMPTE &C???
    pel(); // put constucteur here and recuperate all default value in PEL and Compte
    int choixOuverture;
    double montantOuverture;

    do
    {
        cout << "Pour ouvrir compte PEL, il faut minimum " << Compte::GetMinOuverture() << "euro. Combien d'argent voulez-vous mettre?" << endl;
        cin >> montantOuverture;
    } while(montantOuverture < 225.0 || montantOuverture > 61200.0); // minOuverture 225 and plafondMontant 61200

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

    int faconDepot;
    // P.OuvrirCompte(in);
    
    do
    {
        cout << "Quel type de dépot que vous voulez?" << endl
        << "1. Dépot par mois : 45€" << endl
        << "2. Dépot par trimestre : 135€" << endl
        << "3. Dépot par semestre : 270€" << endl
        << "4. Dépot par an : 540€" << endl;
        cin >> faconDepot;

        switch (faconDepot)
        {
        case 1:
            dureeDepot = 1;
            montantDepot = 45.0;
            break;
        case 2:
            dureeDepot = 3;
            montantDepot = 135.0;
            break;
        case 3:
            dureeDepot = 6;
            montantDepot = 270.0;
            break;
        case 4:
            dureeDepot = 12;
            montantDepot = 540.0;
            break;    
        default:
            cout << "Vous n'avez pas saisir le bon numéro" << endl;
            break;
        }
    } while ((faconDepot != 1) && (faconDepot != 2) && (faconDepot != 3) && (faconDepot != 4));

    // temporairement utilise 2% pour tauxInteret
    Compte::SetTauxInteret(0.02);
    this->dureeDepot = dureeDepot;
    this->montantDepot = montantDepot;
}

// NOT CHECKED YET
double pel::Deposer()
{
    double montantOperation;
    double montant = Compte::GetMontant();
    cout << "Combien voulez-vous déposer ?" << endl;
    cin >> montantOperation;
    if ((montant + montantOperation) > Compte::GetPlafondMontant())
        cout << " Le dépôt n'est pas possible car le plafond est dépassé. \n";
    else 
        {   
            cout << "Le dépôt a été effectué.";
            // il faut fair eun truc avec le vector pour incrementer les operations
            montant = montant + montantOperation;
            Compte::SetMontant(montant);
            cout<<"Nouveau montant :"<< Compte::GetMontant() <<"€"<<endl;
        }
    return montantOperation;
}

double pel::Retirer()
{
    double montantOperation;
    montantOperation = Compte::GetMontant();

// retrait interdit avant la date échéance du PEL
// durée minimale de 4 ans, peut être prolongée pendant 10 ans max
    int choixEcheancePEL;
    time_t today = time(NULL);
    tm *DateToday = localtime(&today);

    if ((DateToday->tm_year - DateOuverture.tm_year) < 4)
    {
        cout << "Vous ne pouvez que retirer l'argent du PEL après la date d'échéance" << endl;
        cout << "La date d'échéance de votre PEL est ==>" << DateOuverture.tm_mday 
        << "/" << DateOuverture.tm_mon + 1 << DateOuverture.tm_year + 1900 + 4 << endl; // can only withdraw after 4 years
    }

    if (((DateToday->tm_year - DateOuverture.tm_year) == 4))
    {
        do
        {
            cout << "Votre PEL atteint la date d'échéance. Quel type de procédure?" << endl 
            << "1. Retirer l'argent et votre compte sera supprimé automatiquement" << endl 
            << "2. Prolonger la période du PEL pour 10 ans" << endl;
            switch (choixEcheancePEL)
            {
                case 1:
                    cout << "Votre montant à retirer est: " << montantOperation<<"€"<<endl << "Merci d'être client chez nous" << endl;
                    SupCompte(); // this function does not function yet
                    break;

                case 2:
                    DateToday->tm_year = DateOuverture.tm_year += 6;
                    #ifdef DEBUG
                    cout << "Affichage péda pour nouveau Date d'échéance:" << DateToday->tm_year + 6 << endl;
                    #endif
                    break;

                default:
                    break;
            }
        } while (choixEcheancePEL != 1 && choixEcheancePEL != 2);
    }

    // if (((DateToday->tm_year - DateOuverture.tm_year) > 4) && (DateToday->tm_mon - DateOuverture.tm_mon < 10))

    return montantOperation;
}

bool pel::SupCompte()
{    
    int reponse;
    double montant = Compte::GetMontant();
    cout << "Votre compte va être fermé, il reste : "<< montant << "€." << endl;
    cout << "Quelle operation vous voulez effectuer en fermant ce compte?: " << endl;
    do
    {   
        cout << "1. Clôturer" << endl << "2. Retirer l'argent et clôturer" << endl;
        cin >> reponse;

        switch (reponse)
        {
            case 1 : // retire l'argent en espèce et clôturer
            {
                pel::~pel();
                cout << "Le compte PEL est supprimé"<<endl;
            }    
                break;
            case 2 :
            {    // on déplace le montant dans le compte courant
                // récupère le montant
                // fonction Virement qui doit être public soit dans le main ou classe Banque
                // appel fonction rechercheIndexClient puis faire le virement de compte source à destination
                double montant = Compte::GetMontant();
                Retirer();
                // comment faire pour incremeter le vector pour les operations
                // cout <<"Vous avez retirer : "<< montant << "€." << endl;
                //Compte::AjoutOp();// ATTENTION FAUT LA FAIRE CELLE LA  appel fonction AjoutOp (il faut avoir cout dans cette fonction déjà)
                pel::~pel(); // supprime dès tous les données sont récupérées
            }
                break;
            default :
            {
                cout << "Vous n'avez pas saisi le bon chiffre";
                break;
            }
        }
    } while ((reponse != 1) || (reponse != 2));
    return false;
}

void pel::AfficherCompte(ostream &out) const
{
    Compte::AfficherCompte(out);
    out << "Le minimum de virement peut être effectué : " << virementMin << "€" << endl;
    out << "Le durée de dépôt choisi : " << dureeDepot << "€" << endl;
    out << "Le montant de dépot par rapport à la durée choisi: " << montantDepot << "€" << endl;
}

// CREATE WHEN WE HAVE TIME
// int pel::Age()
//     {
//         int annee;
//         time_t actuel = time(0);
//         tm *ptr = localtime(&actuel);
//         annee = 1900 + ptr>tm_year;
//         return ((this->DateOuverture.tm_year+1900)-annee); // il faut savoir comment gérer la date
//     }


// 2% taux d'intérêts si PEL ouvert avant et après 1 janvier 2023
// 1% pour ceux ouverts entre 1 aout 2016 - 1 janvier 2023
// CREATE WHEN WE HAVE TIME
// 0.5% avant 1 aout 2016
// double pel::CalculInteret()
//     {
//         time_t tOuverture = mktime(&DateOuverture);
//         time_t 
//     }

double pel::GetVirementMin() const
{
    return virementMin;
}

int pel::GetDureeDepot() const
{
    return dureeDepot;
}

double pel::GetMontantDepot() const
{
    return montantDepot;
}

void pel::SetVirementMin(double virementMin)
{
    this->virementMin = virementMin;
}

void pel::SetDureeDepot(int dureeDepot)
{
    this->dureeDepot = dureeDepot;
}

void pel::SetMontantDepot(double montantDepot)
{
    this->montantDepot = montantDepot;
}


