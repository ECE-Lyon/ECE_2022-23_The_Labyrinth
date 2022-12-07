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
#define nbrTuileABouger 34    //sur 49 tuiles
#define CHARACTERE 219      // █

int joueur = 0;
int infoJoueur[nbrInfosJoueur] = {0};
int carteTresor[nbrCarteTresor] = {0};

typedef struct {int typeCase, orientationCase; char tresor, pion;} Case;

typedef struct {int typeCase, orientationCase, tresor, couleur, absisse, ordonnee;} placementPion;

void AfficherPlateau () {
    for(int lap = 0; lap < LARGEURPLATEAU; lap++) {
        int m = 0;
        for(int lac = 0; lac < LARGEURCASE; lac++) {
            for (int lop = 0; lop < LONGUEURPLATEAU; lop++) {
                if(m == 0) {
                    //début d'une case
                }
                for (int loc = 0; loc < LONGUEURCASE; loc++) {
                    printf("%c ", CHARACTERE);
                }
                printf("  ");
            }
            m += 1;
            printf("\n");
        }
        printf("\n");
    }
}

int main(void) {
    srand(time(NULL));
    Case tableau[LONGUEURPLATEAU][LARGEURPLATEAU] = {{0}};
    AfficherPlateau();
    return 0;
}
