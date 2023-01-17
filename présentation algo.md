---
title: Équipe AJ, LABYRINTHE 
description: Une présentation sur le projet d'algorithmique portant sur le boardgame "LE LABYRINTHE".
paginate: true
_paginate: false
marp: true
theme: gaia
footer: par Jade PLANTEROSE, Anton ADAM, et Eugène LAMBERT
header: ING1, GR.02
_class: invert
style: |
  #image-id {
    position: absolute;
    bottom: 0;
    right: 0;
  }
  div {
    max-width: 600px;
    overflow: auto;
  }



---
<style>
img[alt~="center"]
{
  display: block;
  margin: 0 auto;
}
</style>
###### Projet d'Algorithmique, Équipe AJ:

<br>
<br>

# Le LABYRINTHE <!-- fit--> 


---
<style>
img[alt~="center"]
{
  display: block;
  margin: 0 auto;
}
</style>
<!-- _class: invert-->
# Structuration du programme



![center](https://imgur.com/EKZCC10.png)
---
---
<!-- _class: invert-->
# Stockage des données
<br>

- Plateau: tableau à double entrées de structures
<br>
- Pions: structures
<br>

- Trésors: chars de tableau à double entrées
---
<!-- _class: invert-->
# Plateau et cartes "trésors"
<br>
<br>
<br>

Tout le plateau est initialisé à part, puis les cartes trésors sont initialisées et distribuées aléatoirement aux joueurs.

![h:190 center](https://imgur.com/KiF2KXY.png)



---
<!-- _class: invert-->


# Tours de jeu / "Rounds"
<br>

- Glissement de rangée par index du tableau
- Déplacement visuel du pion via une overlay d'image (Allegro)

![h:270px center](https://imgur.com/UtkqSNu.png)


---
<!-- _class: invert-->
# Répartition des tâches

<style scoped>
 {
  font-size: 18px;
}
</style>

Anton:
- Allegro
- Affichage du plateau
- Affichage du jeu (création des écrans, des personnages, licence, README etc..) 

Jade:
- Structure du programme
- Stockage des données
- Initialisation du jeu
- Déroulement d’un tour 
<!-- class: lead-->
Eugène:
- Déplacement des
cases 

En groupe:
- Structuration finale
---
<!-- _class: invert-->
<style scoped>
 {
  font-size: 33px;
}
</style>

# Bilan du projet
**Ce qui fonctionne:**
 Initialisation du jeu (écran + données)
 Déplacement de rangée
 Déplacement du pion
 Cartes trésors
 Plateau fonctionnel 

**Ce qui ne fonctionne pas**
• Affichage du plateau mélangé
• Joueur sur la tuile supplémentaire

---
<!-- _class: invert-->
<style scoped>
 {
  font-size: 33px;
}
</style>
# Organisation du projet : retour sur les défauts
<br>

 Pas assez de temps pour un projet fait à deux
 Un dilemme: Commencer et se mettre entièrement à Allegro ou ne pas le faire (prend du temps à prendre en main)
 Ne pas être trop ambitieux

---
<!-- _class: invert-->
# Conclusion
<br>
<br>
Merci pour votre attention

![left:40% bg](https://imgur.com/tzu4baK.png)
