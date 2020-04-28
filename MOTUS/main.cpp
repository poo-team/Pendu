#include <iostream>
#include <Motus.h>
#include <ctype.h>
using namespace std;
int niveau;
string word;
int score=0 , fin=0, choix ;
string motpropose;
int mode;
bool Rejouer = false;



int main()
{
do
   {

    cout<<"Motus:"<<endl;
    cout<<"1-jouer solo"<<endl;
    cout<<"2-jouer avec ami(e)"<<endl;
    cin>>mode;
    if(mode==1){
        cout<<"choisir le niveau:"<<endl;
        cout<<"1-normal"<<endl;
        cout<<"2-difficile"<<endl;
        cin>>niveau;
        Motus m1(niveau);
        cout<<"vous avez 6 essais"<<endl;
        m1.resultat();

        }
    else {
         cout<<"Saisie Votre Mot Joueur 1:"<<endl;
        cin>>motpropose;
        Motus m2(motpropose);
        cout<<"vous avez 6 essais"<<endl;
        m2.resultat();



    }

	cout << "Voulez vous rejouer : " << endl;
	cout << "1_Oui" << endl;
	cout << "2_Non" << endl;
	cout << "Votre choix : "<< endl ;
	cin >> choix;
	switch (choix)
	{
	case 1 :
		Rejouer = true;
		break;
	default:
		Rejouer = false;
		break;
	}

   }while (	Rejouer);

}


