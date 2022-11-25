//
//  main.cpp
//  Gestion des soldes
//
//  Created by Elijah Loïc BODIPO OBIANG on 23/11/2022.
//

#include <iostream>
#include "Reduction.h"


int main() {
    reductionFixe r(10);
    std::cout<<r.prixReduit(500);
    return 0;
}
