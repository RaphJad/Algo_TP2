// Pour tester si votre code est ecrit en C++ standard, copiez le
// contenu de ce fichier sur la page http://geyron.fsg.ulaval.ca

#include "investissement.hpp"

#include <assert.h>
#include <numeric>

using namespace std;
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
