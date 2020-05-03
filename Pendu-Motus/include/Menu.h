#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
class Menu
{
    public:
        Menu();
        virtual ~Menu();
        int Menu_Principal();
        int Menu_pendu();
        int Menu_pendu_solo();
        string Menu_pendu_multijoueur();
        int Menu_motus();
        int Menu_motus_solo();
        string Menu_motus_multijoueur();
        int Menu_Rejouer();
        void Menu_cree();
    protected:
    private:
};

#endif // MENU_H
