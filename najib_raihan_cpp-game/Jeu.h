//
// Created by NAJIB RAIHAN on 6/24/2020.
//

#ifndef NAJIB_RAIHAN_CPP_GAME_JEU_H
#define NAJIB_RAIHAN_CPP_GAME_JEU_H

#include "Helper.h"

enum Couleur {vide =0, rouge, jaune };

class Jeu {

private:
    vector< vector<Couleur>> grille;

//protected:
//    unsigned int compte(Couleur, size_t, size_t, int, int) const {} ;

public:

    Jeu(size_t taille = 8){ // size of color hold any array index

        for (size_t  i = 0; i <taille ; ++i) {
            vector<Couleur > v1;
            for (size_t j = 0; j <taille ; ++j) {
                v1.push_back(vide);
            }
            grille.push_back(v1);
        }
       
    };


    bool jouer(size_t i ,Couleur c){
        for (size_t j = 0; j < 8; ++j) {
            if(grille[i][j] == vide){
                grille[i][j] = c;
                return true;
            }
        }
        cout<<"passez a autre colonne"<<endl;
        return false;
    };

    Couleur  gagnant() const {

        int count_D = 1;
        int count_H = 1;
        int count_V = 1;

        for (size_t i = 0; i <8 ; ++i) {
            for (size_t j = 0; j <8  ; ++j) {

                if (grille[i][j] != vide){

                    for (size_t k = 0; k <8; ++k) {

                        if(grille[i][j] == grille[k][j]){
                            count_H++;
                            if (count_H == 5){
                                return grille[i][j];
                            }
                        }else{
                            count_H =1;
                        }

                        if(grille[i][j] == grille[i][k]){
                            count_V++;
                            if (count_V == 5){
                                return grille[i][j];
                            }
                        }else{
                            count_V =1;
                        }

                        if( i+k<8 and i+j<8){
                        if(grille[i][j] == grille[i+k][j+k]){
                            count_D++;
                            if (count_D == 5){
                                return grille[i][j];
                            }
                        }else{
                            count_D =1;
                        }
                        }

                    }
            }

                 count_D = 1;
                 count_H = 1;
                 count_V = 1;
        }}

        return vide;
    };

    bool fini( Couleur& c) const {
        return gagnant() == c;
    };

    size_t getTaille() const {
        return grille.size();
    };

    ostream& afficher(ostream& out) const {

        for( size_t i = 0; i < 8; ++i) {
            out<<(i+1)<<"|";
            for (size_t j = 0; j < 8; ++j) {
                if(grille[i][j] == jaune){
                    out<<("#");
                }else if(grille[i][j] == vide){
                    out<<(" ");
                }else{
                    out<<("O");
                };
            }
            out<<("\n");
        }
        out<<("- --------\n");

        return out;
    };

    void setGrille(const vector<vector<Couleur>> &Grille) {
        Jeu::grille = Grille;
    }
};

#endif //NAJIB_RAIHAN_CPP_GAME_JEU_H
