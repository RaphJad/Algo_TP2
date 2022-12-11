// Pour tester si votre code est ecrit en C++ standard, copiez le
// contenu de ce fichier sur la page http://geyron.fsg.ulaval.ca

#include "investissement.hpp"

#include <assert.h>
#include <numeric>
#include <iostream>

// Parametres:
//   profits: profits[i][m] = le profit d'investir m dollars dans l'entreprise i
//   montants: le montant que vous voulez investir dans l'entreprise i pour maximiser les profits.
std::vector<std::vector<unsigned int>> update_profits(const std::vector<std::vector<unsigned int> >& profits, std::vector<unsigned int>& montants){
  /*
  mettre à jours le tableau profit:
    pour ce faie, on parcourt le tableau montant, s'il y a une valeur différente de zero
    on supprime la ligne de la compagnie correspondante
  */
  std::vector<std::vector<unsigned int>> updated_profits;
  for(int i = 0; i < montants.size(); i++){
    if(montants[i] == 0){
      updated_profits.push_back(profits[i]);
    }
  }
  return updated_profits;
}

std::vector<std::vector<unsigned int>> update_budget(const std::vector<std::vector<unsigned int> >& profits, int budget){
  std::vector<std::vector<unsigned int>> updated_profits;
  for(int i = 0; i < profits.size(); i++){
    std::vector<unsigned int> temp;
    for(int j = 0; j < budget; j++){
      temp.push_back(profits[i][j]);
    }
    updated_profits.push_back(temp);
  }
  return updated_profits;
}

// Parametres:
//   profits: profits[i][m] = le profit d'investir m dollars dans l'entreprise i
//   montants: parametre de sortie: montants[i] est le montant que vous voulez investir dans l'entreprise i pour maximiser les profits.
void investissement(const std::vector<std::vector<unsigned int> >& profits, std::vector<unsigned int>& montants) {
  assert(profits.size() > 0 && profits.front().size() > 0);
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


  //on met à jours le tableau des profits en fonction de ce que l'on a trouvé précédement
  std::vector<std::vector<unsigned int>> updated_profits = update_profits(profits, montants);
  //on compte ici le nombre de compagnies restantes après avoir ajusté le tableau des profits
  unsigned int nb_compagnies = profits.size();
  //on teste les cas de base de la récurrence
  //si le budget est nul ou qu'il n'y a plus d'investissement possible
  //donc on ne modifie pas le vecteur montant
  if(budget >= 0 && nb_compagnies >= 0){
    //traiter les deux cas de la récurrence:
    if(budget >= profits[0].size()){
      //cas 1 le budget est supérieur au montant maximal à investir
      std::vector<unsigned int> profit_max = find_max_profit(updated_profits, -1);
      std::cout << profit_max[0] << " ," << profit_max[1] << ", " << profit_max[2] << std::endl;
      //on indique cet investissement dans le tableau des montants
      montants[profit_max[1]] = profit_max[0];
      //on update le budget
      updated_profits = update_budget(updated_profits, budget-profit_max[2]);
      investissement(updated_profits, montants);
    }
    else{
      //cas 2 le budget est plus petit que le montant maximal à investir
      std::vector<unsigned int> profit_max = find_max_profit(updated_profits, -1);
      std::cout << profit_max[0] << " ," << profit_max[1] << ", " << profit_max[2] << std::endl;
      //on indique cet investissement dans le tableau des montants
      montants[profit_max[1]] = profit_max[0];
      //on update le budget
      updated_profits = update_budget(updated_profits, budget-profit_max[2]);
      investissement(updated_profits, montants);
    }
  }
  
}

//retourne un vecteur de unsigned int qui contient [profit p, compagnie i, cout m]
std::vector<unsigned int> find_max_profit(const std::vector<std::vector<unsigned int> >& profits, int budget){
  std::vector<unsigned int> max = {0, 0, 0};
  for(int i = 0; i < profits.size(); i++){
    if(budget == -1){
      for(int j = 0; j < profits[i].size(); j++){
        if(profits[i][j] > max[0]){
          max[0] = profits[i][j];
          max[1] = i;
          max[2] = j;
        }
      }
    }else{
      for(int j = 0; j < budget; j++){
        if(profits[i][j] > max[0]){
          max[0] = profits[i][j];
          max[1] = i;
          max[2] = j;
        }
      }
    }
  }
  return max;
}
