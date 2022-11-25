//
//  main.cpp
//  Gestion des soldes
//
//  Created by Elijah Loïc BODIPO OBIANG on 23/11/2022.
//

#include <iostream>
#include "Reduction.h"
#include "article.h"
#include "formateurReduction.h"


int main() {
    article a("Lubrifiants",6000);
    reductionFixe r(12);
    a.ajouteReduction(reductionPourcentage(4));
    a.ajouteReduction(reductionPourcentage(8));
    a.ajouteReduction(reductionPourcentage(3));
    a.ajouteReduction(reductionFixe(500));
    a.ajouteReduction(reductionFixe(700));
    formateurReductionTexte f(r);


    std::cout<<f.reductionFixeFormatee(r)<<std::endl;
    return 0;
}
