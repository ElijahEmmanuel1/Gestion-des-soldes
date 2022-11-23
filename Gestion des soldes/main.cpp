//
//  main.cpp
//  Gestion des soldes
//
//  Created by Elijah Loïc BODIPO OBIANG on 23/11/2022.
//

#include <iostream>
#include "Reduction.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    reductionPourcentage r(12);
    std::cout<<r.montantReduction(1000);
    return 0;
}
