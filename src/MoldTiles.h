#ifndef MOLDTILES_H
#define MOLDTILES_H

#include <vector>
#include "Cell.h"

/**
 * @class MoldTiles
 * @brief Classe représentant un modèle de tuiles (grille de cellules).
 *
 * Cette classe gère un tableau dynamique de cellules (`Cell`) pour former une grille ou une structure de tuiles.
 * Elle permet d'initialiser, afficher, et gérer des cellules de manière organisée.
 */
class MoldTiles {
public:

    /* ========= Constructeur & Destructeur ========= */

    /**
     * @brief Constructeur avec initialisation des tuiles.
     * @param tiles Un vecteur de vecteurs d'entiers représentant les tuiles à ajouter au modèle.
     */
    explicit MoldTiles(const std::vector<std::vector<int>>& tiles);

    /**
     * @brief Constructeur de copie pour copier un modèle de tuiles existant.
     * @param other Autre instance de MoldTiles à copier.
     */
    MoldTiles(const MoldTiles& other);

    /**
     * @brief Opérateur d'assignation pour copier un modèle de tuiles existant.
     * @param other Autre instance de MoldTiles à copier.
     * @return Référence vers l'instance actuelle après la copie.
     */
    MoldTiles& operator=(const MoldTiles& other);
    /**
     * @brief Destructeur pour libérer la mémoire allouée pour le modèle de tuiles.
     */
    ~MoldTiles();

    /* ========= Méthode ========= */

    /**
     * @brief Affiche le modèle de tuiles dans la console.
     *        Implémentation détaillée dans le fichier source.
     */
    void displayMold() const;

    /* ========= Getter ========= */

    /**
     * @brief Récupère le modèle de cellules.
     * @return Pointeur vers un tableau bidimensionnel de cellules (`Cell**`).
     */
    [[nodiscard]] Cell** getMold() const;

    /**
     * @brief Récupère la taille de la grille (modèle de tuiles).
     * @return Taille du modèle de tuiles.
     */
    [[nodiscard]] int getSize() const;

private:

    /* ========= Méthodes Privées ========= */
    /**
     * @brief Crée le modèle de tuiles initial, en allouant la mémoire nécessaire.
     */
    void createMold();

    /**
     * @brief Ajoute un ensemble de tuiles au modèle.
     * @param tiles Un vecteur de vecteurs d'entiers représentant les tuiles à ajouter.
     */
    void addTiles(const std::vector<std::vector<int>>& tiles) const;

    /**
     * @brief Ajoute une tuile spécifique à une position donnée dans le modèle.
     * @param x Position x de la tuile.
     * @param y Position y de la tuile.
     */
    void addTile(int x, int y) const;

    /* ========= Attributs Privés ========= */
    Cell **_mold;
    int _size;
};

#endif // MOLDTILES_H
