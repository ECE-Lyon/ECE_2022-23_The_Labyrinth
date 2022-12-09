#include <stdio.h>
#include <stdlib.h>     //pour avoir la fct rand() = nbr aléatoire
#include <time.h>       //pour que la fct rand() soit pas tjr la mm

#define longueurPlateau 7
#define largeurPlateau 7
#define nbrTuileABouger 34
#define nbrCarteTresor 24
#define nbrInfosJoueur 4    //couleur, trésor recherché (tableau : nbr et le type), trésors obtenus, emplacement

int joueur = 0;
int infoJoueur[nbrInfosJoueur] = {0};
int carteTresor[nbrCarteTresor] = {0};

typedef struct {int typeCase, orientationCase, theEmperess, theArchDruid, theHauntedSeer, theBurtalWanderer; char tresor;} Case;

typedef struct {int typeCase, orientationCase, tresor, nom, absisse, ordonnee;} placementPion;

int newGame() {
    //demander nbr joueurs, pions (couleur), noms       /\ mininmum 2 joueurs
    //donner des cartes trésors aléatoirement
    //joueur choisi aléatoirement (joueur = x)
    //génération du plateau (sous forme de tableau)
    // [...]
    return 0;
}

int main(void) {
    srand(time(NULL));
    printf("Bienvenue");
    while("pas dédection de partie finie") {    //créer une fct d'arret pour détecter quand un jour gagne
        while(joueur, joueur < 3, joueur++) {
            //faire un tour de jeu :
            //montrer carte trésor cherchée
            //faire glisser une rangée (attention si y'a un pion avec) (utiliser pointeur?)
            //déplacer pion sans traverser mur (retenir position départ le tps de la fin du tour)
        }
        joueur = 0;
    }
    return 0;
}

//créer une fct interruption pour créer une new partie à tt moment
//créer une fct interruption pour stoper la partie

//fct pour savoir le nbr de joueur => en déduire le nbr de carte térsor à distribuer pour ne créer un tableau de trésor recherché avec le bon nbr de case? (peut-etre plus pratique)

int testPourBreak() {
    while (1) {
        printf("Je sers à rien");
        int i = 0;
        i++;
        if (i < 5) {
            printf("Tjr inutile");
        }
        else {
            break;
        }
        printf("indentation");
    }
}
