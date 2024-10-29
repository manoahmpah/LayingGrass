# Laying Grass - Jeu de Plateau en Ligne de Commande (CLI)

## Sommaire
- [Description](#description)
- [Règles du Jeu](#règles-du-jeu)
- [Déroulement du Jeu](#déroulement-du-jeu)
  - [Début](#début)
  - [Tours de Jeu](#tours-de-jeu)
  - [Fin du Jeu](#fin-du-jeu)
  - [Cases Bonus](#cases-bonus)
- [Exemple d’Utilisation](#exemple-dutilisation)
- [Installation et Exécution](#installation-et-exécution)
- [Contraintes et Règles](#contraintes-et-règles)
- [Contribution](#contribution)
- [Auteurs](#auteurs)

## Description
Ce projet est une adaptation du jeu "Laying Grass", inspiré de l'émission de télé-réalité Netflix *The Devil's Plan* (épisode 8). Dans ce jeu de stratégie, les joueurs doivent étendre leur territoire en plaçant des tuiles d'herbe sur une grille. L'objectif est de créer le plus grand territoire carré.

## Règles du Jeu
1. **But du jeu** : Créer le plus grand territoire carré possible.
2. **Nombre de joueurs** : De 2 à 9.
   - Pour 2 à 4 joueurs : grille de 20x20 cases.
   - Pour 5 à 9 joueurs : grille de 30x30 cases.
3. **Conditions de victoire** : Le joueur avec le plus grand carré couvert (ex: 7x7) est le gagnant. En cas d'égalité, celui avec le plus grand nombre de cases d'herbe dans son territoire gagne.

## Déroulement du Jeu
### Début
- Chaque joueur entre un nom et choisit une couleur.
- Une tuile de départ de 1x1 est attribuée à chaque joueur, ainsi qu’un coupon d'échange de tuile.

### Tours de Jeu
1. **Réception de Tuiles** : À chaque tour, un joueur reçoit une tuile d'herbe dans l’ordre défini de la file d'attente.
   - Les tuiles peuvent être tournées et retournées mais ne doivent pas se superposer ou toucher le territoire d'un autre joueur.
2. **Placement des Tuiles** :
   - La première tuile doit toucher la tuile de départ du joueur.
   - Les tuiles suivantes doivent être adjacentes au territoire du joueur.
   - Si une tuile ne peut pas être placée, le joueur la défausse et passe son tour.
3. **Coupons d'échange** : Les joueurs peuvent utiliser leurs coupons d'échange pour choisir une tuile parmi les cinq suivantes de la file d'attente.

### Fin du Jeu
- Le jeu se termine après 9 tours.
- Les joueurs peuvent utiliser leurs coupons d'échange pour acheter une tuile d'herbe de 1x1 et la placer où ils le souhaitent.

### Cases Bonus
1. **Échange de Tuile** : Donne un coupon d’échange supplémentaire.
2. **Pierre** : Permet de placer une tuile de pierre, bloquant la position.
3. **Vol** : Permet de voler une tuile du territoire d’un autre joueur et de l’ajouter à son propre territoire.

Les bonus sont distribués aléatoirement et doivent être utilisés immédiatement.

## Exemple d’Utilisation
Ce jeu utilise une interface en ligne de commande (CLI) et ne nécessite pas d’interface graphique. Les joueurs peuvent naviguer et saisir des commandes pour placer leurs tuiles et gérer leurs actions.

## Installation et Exécution
1. **Cloner le dépôt** :
   ```bash
   git clone https://github.com/mpahmanoah/LayingGrass.git
   cd LayingGrass
   ```

2. **Exécuter le programme** :
   ```bash
   g++ -o main.cpp
   ```

## Contraintes et Règles
- **Aucune triche** : Copier un code existant ou partager des informations avec d'autres groupes est interdit.
- **Respect des instructions de rendu** : Le non-respect des règles de livraison entraînera une note de 0.

## Contribution
Les contributions sont les bienvenues pour améliorer le jeu. Veuillez soumettre une pull request avec des explications sur vos modifications.

## Auteurs
Projet réalisé par des étudiants dans le cadre d’un cours d'algorithmie et de programmation.
