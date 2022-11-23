//
//  Reduction.h
//  Gestion des soldes
//
//  Created by Elijah Loïc BODIPO OBIANG on 23/11/2022.
//

#ifndef Reduction_h
#define Reduction_h
#include <iostream>

class reduction{
public:
    virtual ~reduction()=default;
    virtual double montantReduction(const double& prix) const;
    double prixReduit(const double& prix) const;
};
double reduction::prixReduit(const double& prix) const{
    return prix-montantReduction(prix);
};

class reductionPourcentage:public reduction{
public:
    reductionPourcentage(const double& pourcentage);
    virtual double montantReduction(const double& prix) const override;
    double pourcentage() const;
private:
    double d_pourcentage;
};

reductionPourcentage::reductionPourcentage(const double& pourcentage):d_pourcentage(pourcentage){};
double reductionPourcentage::montantReduction(const double& prix) const{
    return (prix*d_pourcentage)/100;
}
double reductionPourcentage::pourcentage() const{
    return d_pourcentage;
}

#endif /* Reduction_h */
