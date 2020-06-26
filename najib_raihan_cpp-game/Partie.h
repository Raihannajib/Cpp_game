//
// Created by NAJIB RAIHAN on 6/24/2020.
//

#ifndef NAJIB_RAIHAN_CPP_GAME_PARTIE_H
#define NAJIB_RAIHAN_CPP_GAME_PARTIE_H

#include "Helper.h"
#include "Joueur.h"

class Partie {

protected:
        Joueur *vs[2];
        Jeu table;

public:

    Partie(Ordi *O , Humain *H){
        table = Jeu(); //as dependency injection
        vs[0] = O;
        vs[1] = H;
    };
    ~Partie(){
        delete vs[1];
    }

    void lancer() {
        Couleur x = vs[0]->getColor();
        Couleur y = vs[1]->getColor();

        string name;
        cout << "Entrez votre nom:";
        cin >> name;
        vs[1]->setNom(name);


        while ((!table.fini(x) and !table.fini(y)) ){


            vs[0]->jouer(table);
            table.afficher(cout);
            while (!vs[1]->jouer(table)) {};


            if (table.fini(x)){
                cout<<"le vainqeur est le programme"<<endl;
            }
            if (table.fini(y)){
                cout<<"le vainqeur est "<<vs[1]->getNom()<<endl;
            }

        }
    };

    void vider(){


        vector<vector<Couleur >> T;
        for (size_t  i = 0; i <8 ; ++i) {
            vector<Couleur> t;
            for (size_t j = 0; j <8 ; ++j) {
                t.push_back(vide);
            }
            T.push_back(t);
        }
        table.setGrille(T);

    };

};
#endif //NAJIB_RAIHAN_CPP_GAME_PARTIE_H
