#include "Helper.h"
#include <typeinfo>
#include "Jeu.h"
#include "Joueur.h"
#include "Partie.h"

int main() {
Partie p(new Ordi(rouge), new Humain(jaune));
p.lancer();
p.vider();
return 0;
}