//
// Created by Elijah Loïc BODIPO OBIANG on 25/11/2022.
//

#ifndef GESTION_DES_SOLDES_ARTICLE_H
#define GESTION_DES_SOLDES_ARTICLE_H
#include <iostream>
#include <vector>
#include <string>
#include "Reduction.h"



class article{
public:
    article(const std::string& description,const double& prix);
    article()= default;
    std::string description() const;
    double prix() const;
    double prixReduit() ;
    void ajouteReduction(const reduction& reduc);
private:
    std::vector<std::unique_ptr<double>> tableauDeReduction;
    double d_prix;
    std::string d_description;
};
article::article(const std::string &description,const double& prix):d_description(description),d_prix(prix) {}

void article::ajouteReduction(const reduction& reduc) {
     tableauDeReduction.push_back(std::make_unique<double>(reduc.montantReduction(d_prix)));
}

double article::prixReduit()  {
    double prixReduit=d_prix;
    for(auto& i:tableauDeReduction){
        prixReduit-=*i;
        std::cout<<prixReduit<<std::endl;
    }
    return prixReduit;
}
double article::prix() const {return d_prix;};
std::string article::description() const {return d_description;}

#endif //GESTION_DES_SOLDES_ARTICLE_H
