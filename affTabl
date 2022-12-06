#include <stdio.h>
#include <stdlib.h>     //pour avoir la fct rand() = nbr aléatoire
#include <time.h>       //pour que la fct rand() soit pas tjr la mm

#define LONGUEURPLATEAU 7
#define LARGEURPLATEAU 7
#define LONGUEURCASE 5
#define LARGEURCASE 3
#define nbrInfosPlateau 4    //int typeCase, orientationCase; char tresor, pion;
#define nbrInfosJoueur 4    //couleur, trésor recherché (tableau : nbr et le type), trésors obtenus, emplacement
#define nbrCarteTresor 24
#define nbrTuileABouger 34
#define CHARACTERE 219

int joueur = 0;
int infoJoueur[nbrInfosJoueur] = {0};
int carteTresor[nbrCarteTresor] = {0};
int tableau[LARGEURPLATEAU][LONGUEURPLATEAU][nbrInfosPlateau] = {{0}};

typedef struct {int typeCase, orientationCase, tresor, couleur, absisse, ordonnee;} placementPion;

void AfficherPlateau () {
    for(int i = 0; i < LARGEURPLATEAU; i++) {
        for(int l = 0; l < LARGEURCASE; l++) {
            for (int j = 0; j < LONGUEURPLATEAU; j++) {
                for (int k = 0; k < LONGUEURCASE; k++) {
                    printf("%c ", CHARACTERE);
                }
                printf("  ");
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main(void) {
    srand(time(NULL));
    AfficherPlateau();
    return 0;
}
