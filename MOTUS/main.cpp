#include <iostream>
#include <Motus.h>
#include <ctype.h>
using namespace std;
int niveau;
string word;
int score=0 , fin=0;
string motproposee;
int mode;



int main()
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
        Motus m(niveau);
        cout<<"vous avez 6 essais"<<endl;
        m.resultat();


    }


        return 0;

}


