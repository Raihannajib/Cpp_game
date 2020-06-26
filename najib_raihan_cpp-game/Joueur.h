//
// Created by NAJIB RAIHAN on 6/24/2020.
//

#ifndef NAJIB_RAIHAN_CPP_GAME_JOUEUR_H
#define NAJIB_RAIHAN_CPP_GAME_JOUEUR_H

#include "Helper.h"
#include "Jeu.h"


class Joueur {

protected:

    Couleur Color;
    string Nom;

public:

    Joueur(){};
    Joueur(string &name){
        Nom=name;
    }
    Joueur(Couleur clr){
        Color = clr;
    }
    virtual ~Joueur(){};

    Couleur getColor() const {
        return Color;
    }

    void setColor(Couleur color) {
        Color = color;
    }

    const string &getNom() const {
        return Nom;
    }

    void setNom(const string &nom) {
        Nom = nom;
    }

    virtual bool jouer(Jeu & ) = 0;

};

class Humain: public Joueur {

public:

    Humain(Couleur clr):Joueur(clr){};
    ~Humain(){
        this->setColor(vide);
        this->setNom("");
    }

    bool jouer(Jeu &jeu) override {
        size_t c=0;
        while (c<1 or c>8) {
            cout << Nom << " entrez numero de colonne entre[1,8]:";
            cin >> c;
            c = size_t(c);
        }
        return jeu.jouer(c-1,Color);
    }
};

class Ordi : public Joueur {

public:
    string name = "Le programme";
    Ordi():Joueur(name){};
    Ordi(Couleur clr):Joueur(clr){};
    ~Ordi(){
        this->setColor(vide);
    }

    bool jouer(Jeu &jeu) override {
        for (size_t i = 0; i <8 ; ++i) {
            if(jeu.jouer(i,Color)){
                cout<<"le programme a joue en "<<i+1<<endl;
                return true;}
        }
        return false;
    }
};

#endif //NAJIB_RAIHAN_CPP_GAME_JOUEUR_H
