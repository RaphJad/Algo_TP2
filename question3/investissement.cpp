// Pour tester si votre code est ecrit en C++ standard, copiez le
// contenu de ce fichier sur la page http://geyron.fsg.ulaval.ca

#include "investissement.hpp"

#include <assert.h>
#include <numeric>

// Parametres:
//   profits: profits[i][m] = le profit d'investir m dollars dans l'entreprise i
//   montants: parametre de sortie: montants[i] est le montant que vous voulez investir dans l'entreprise i pour maximiser les profits.
void investissement(const std::vector<std::vector<unsigned int> >& profits, std::vector<unsigned int>& montants) {
  assert(profits.size() > 0 && profits.front().size() > 0);
  const unsigned int nb_compagnies = profits.size();
  const unsigned int budget = profits.front().size() - 1;
  // for (std::vector<std::vector<unsigned int> >::const_iterator i = profits.begin(); i != profits.end(); i++) {
  //   // Note: Lorsque l'on compile avec l'option -O3, les assertions ne
  //   // sont pas incluses dans le code compile. Les boucles qui ne font
  //   // rien sont egalement retiree du code. Cette boucle ne se retrouve
  //   // donc pas dans le code compile et ne devrait pas etre analysee.
  //   //
  //   // Pour les utilisateurs de Visual Studio, la compilation en mode
  //   // "release" est ce qui s'approche le plus de l'option -O3 avec g++
  //   assert(i->size() == budget + 1);
  // }
  

}

//retourne un vecteur de unsigned int qui contient [profit p, compagnie i, cout m]
std::vector<unsigned int> find_max_profit(const std::vector<std::vector<unsigned int> >& profits){
  std::vector<unsigned int> max = {0, 0, 0};
  for(int i = 0; i < profits.size(); i++){
    for(int j = 0; j < profits[i].size(); j++){
      if(profits[i][j] > max[0]){
        max[0] = profits[i][j];
        max[1] = i;
        max[2] = j;
      }
    }
  }
  return max;
}
