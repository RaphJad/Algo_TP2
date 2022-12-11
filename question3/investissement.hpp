// ATTENTION: NE PAS MODIFIER CE FICHIER

#ifndef INVESTISSEMENT
#define INVESTISSEMENT

#include <vector>

// Paremetres:
//   profits: profits[i][m] = le profit d'investir m dollars dans l'entreprise i
//   montants: parametre de sortie: montants[i] est le montant que vous pensez devoir investir dans l'entreprise i pour maximiser les profits.
void investissement(const std::vector<std::vector<unsigned int> >& profits, std::vector<unsigned int>& montants);
//méthode qui retourne un vector de int qui contient le profit max du tableau ainsi que ses coordonnées dans le tableau
std::vector<unsigned int> find_max_profit(const std::vector<std::vector<unsigned int> >& profits);

#endif
