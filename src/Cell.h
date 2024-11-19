#ifndef CELL_H
#define CELL_H

/**
 * @class Cell
 * @brief Classe représentant une cellule de jeu avec un statut d'occupation, un identifiant de joueur,
 *        et des bonus optionnels.
 */
class Cell {
public:
    /**
     * @brief Constructeur par défaut initialisant la cellule comme non utilisée et sans bonus.
     */
    Cell();
    /**
* @brief Constructeur de copie.
* @param other L'objet `Cell` à copier.
*/
 Cell(const Cell& other);

 /**
  * @brief Opérateur d'affectation par copie.
  * @param other L'objet `Cell` à copier.
  * @return Référence à l'instance actuelle après la copie.
  */
 Cell& operator=(const Cell& other);
    /* ========= Getter ========= */

    /**
     * @brief Vérifie si la cellule est utilisée.
     * @return true si la cellule est utilisée, sinon false.
     */
    [[nodiscard]] bool getIsUsed() const;

    /**
     * @brief Vérifie si la cellule appartient à un joueur (tuile joueur).
     * @return true si la cellule est une tuile du joueur, sinon false.
     */
    [[nodiscard]] bool getIsTilesPlayer() const;

    /**
     * @brief Vérifie si la cellule a un bonus d'échange de tuile.
     * @return true si un bonus d'échange de tuile est actif, sinon false.
     */
    [[nodiscard]] bool getBonusTileExchange() const;

    /**
     * @brief Vérifie si la cellule contient un bonus de pierre.
     * @return true si un bonus de pierre est présent, sinon false.
     */
    [[nodiscard]] bool getBonusStone() const;

    /**
     * @brief Vérifie si la cellule contient un bonus de vol.
     * @return true si un bonus de vol est actif, sinon false.
     */
    [[nodiscard]] bool getBonusRobbery() const;

    /**
     * @brief Récupère l'identifiant du joueur propriétaire de la cellule.
     * @return ID du joueur associé à cette cellule.
     */
    [[nodiscard]] int getIDPlayer() const;

    /* ========= Setter ========= */

    /**
     * @brief Définit l'état d'utilisation de la cellule.
     * @param isUsed true si la cellule est utilisée, sinon false.
     */
    void setUsed(bool isUsed);

    /**
     * @brief Définit l'identifiant du joueur pour cette cellule.
     * @param idPlayer ID du joueur propriétaire de la cellule.
     */
    void setIdPlayer(int idPlayer);

    /**
     * @brief Définit si la cellule est une tuile du joueur.
     * @param isTilesPlayer true si la cellule est une tuile de joueur, sinon false.
     */
    void setTilesPlayer(bool isTilesPlayer);

    /**
     * @brief Active ou désactive le bonus d'échange de tuile pour cette cellule.
     * @param bonusTileExchange true pour activer le bonus, sinon false.
     */
    void setBonusTileExchange(bool bonusTileExchange);

    /**
     * @brief Active ou désactive le bonus de pierre pour cette cellule.
     * @param bonusStone true pour activer le bonus, sinon false.
     */
    void setBonusStone(bool bonusStone);

    /**
     * @brief Active ou désactive le bonus de vol pour cette cellule.
     * @param bonusRobbery true pour activer le bonus, sinon false.
     */
    void setBonusRobbery(bool bonusRobbery);

private:
    bool _isUsed;
    bool _isTilesPlayer;
    int _idPlayer{};

    /**
     * @struct Bonus
     * @brief Structure contenant les bonus associés à la cellule.
     */
    struct Bonus {
        bool tileExchange = false;
        bool stone = false;
        bool robbery = false;
    } _bonus;
};

#endif
