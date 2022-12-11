#include "investissement.hpp"

#include <assert.h>
#include <iostream>

// Complexite: Theta(nb_entreprises * budget)
void convertion_en_vecteur(unsigned int* profits, unsigned int nb_entreprises, unsigned int budget, std::vector<std::vector<unsigned int> >& sortie) {
  std::vector<std::vector<unsigned int> > resultat; // Theta(1)
  resultat.reserve(nb_entreprises);		    // Theta(1)
  unsigned int* debut = profits;
  unsigned int* fin;
  for (unsigned int i = 0; i < nb_entreprises; i++) { // Theta(nb_entreprises * budget)
    fin = debut + budget + 1;
    resultat.push_back(std::vector<unsigned int>(debut, fin)); // Theta(budget)
    debut = fin;
  }
  sortie.swap(resultat);	// Theta(1)
}

int main () {
    const unsigned int nb_entreprises = 5;
    const unsigned int budget = 5;
    unsigned int profits[nb_entreprises * (budget + 1)] = {0, 1, 2, 3, 4, 5,  // Entreprise 0
                                0, 2, 3, 3, 3, 3,  // Entreprise 1
                                0, 4, 4, 4, 4, 4,  // Entreprise 2
                                0, 0, 1, 1, 4, 4,  // Entreprise 3
                                0, 2, 2, 3, 3, 4}; // Entreprise 4
    std::vector<std::vector<unsigned int> > vecteur_profits;
    convertion_en_vecteur(profits, nb_entreprises, budget, vecteur_profits);
    std::vector<unsigned int> max = find_max_profit(vecteur_profits);
    std::cout << max[0] << std::endl;
    std::cout << max[1] << std::endl;
    std::cout << max[2] << std::endl;
}