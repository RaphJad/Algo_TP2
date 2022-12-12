// Pour tester si votre code est ecrit en C++ standard, copiez le
// contenu de ce fichier sur la page http://geyron.fsg.ulaval.ca

#include "investissement.hpp"

#include <assert.h>
#include <numeric>
#include <iostream>

//méthode qui retourne un vector de int qui contient le profit max du tableau ainsi que ses coordonnées dans le tableau
std::vector<unsigned int> find_max_profit(const std::vector<std::vector<unsigned int> >& profits){
  std::vector<unsigned int> max = {0, 0, 0};
  for(int i = 0; i < profits.size(); i++){
    //lorsqu'une compagnie a déjà donné un max, on met la première valeur de sa ligne à 1 et non plus à 0
    //afin de ne plus prendre de maximum dans cette ligne
    if(profits[i][0] == 0){
      for(int j = 0; j < profits[i].size(); j++){
        if(profits[i][j] > max[0]){
          max = {profits[i][j], i, j};
        }
      }
    }
  }
  return max;
}
/*
cette méthode permet de diminuer la taille du tableau à parcourrir au fur
et à mesure que le budget descend.

Cette méthode permet aussi de mettre la première valeur de la compagnie pour laquelle
on vient de trouver le max à 1 afin de ne plus chercher de max dans cette ligne.
*/
std::vector<std::vector<unsigned int>> update_profits(const std::vector<std::vector<unsigned int> >& profits, int new_budget, int company){
  std::vector<std::vector<unsigned int>> updated_profits;
  for(int i = 0; i < profits.size(); i++){
    std::vector<unsigned int> temp;
    for(int j = 0; j < new_budget; j++){
      temp.push_back(profits[i][j]);
    }
    updated_profits.push_back(temp);
  }
  updated_profits[company][0] = 1;
  return updated_profits;
}

// Parametres:
//   profits: profits[i][m] = le profit d'investir m dollars dans l'entreprise i
//   montants: parametre de sortie: montants[i] est le montant que vous voulez investir dans l'entreprise i pour maximiser les profits.
void investissement(const std::vector<std::vector<unsigned int> >& profits, std::vector<unsigned int>& montants) {
  assert(profits.size() > 0 && profits.front().size() > 0);
  const unsigned int nb_compagnies = profits.size();
  const unsigned int budget = profits.front().size() - 1;
  //on commence par construire le vecteur des montant en le remplissant de 0 si il n'a pas la bonne taille 
  if(montants.size() < nb_compagnies){
    //cas du premier passage dans la méthode
    for(int i = 0; i <= budget; i++){
      montants.push_back(0);
    }
  }
  //on test si les conditions initiales de la récurrences sont respectées
  int count_company = 0;
  for(int i = 0; i < profits.size(); i++){
    if(profits[i][0] == 0){
      count_company += 1;
    }
  }
  std::cout << nb_compagnies << budget << std::endl;
  if(count_company > 0 && budget > 0){
    //si pas on ne rentre pas dans la boucle et on retourne le vecteur profit rempli de 0
    std::vector<unsigned int> max = find_max_profit(profits);
    //on ajoute le montant à investir dans le vecteur montant
    montants[max[1]] = max[2];
    //on calcule le nouveau budget pour choisir le prochain investissement
    int new_budget = budget - max[2];
    /*on met à jour le tableau profits:

          -> on retire les colonnes qui ne rentrent plus dans le budget
          -> on met à 1 la première case de la ligne dans laquelle on 
             vient de trouver le max    
    */
   std::vector<std::vector<unsigned int>> new_profits = update_profits(profits, max[1], new_budget);
   //on appelle recursivement sur le nouveau tableau de profits trouvé
   investissement(new_profits, montants);
  }
}
