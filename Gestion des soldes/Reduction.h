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
    reduction(){};
    virtual ~reduction()=default;
    virtual double montantReduction(const double& prix) const;
    double prixReduit(const double& prix) const;
};

double reduction::montantReduction(const double &prix) const {return 0;}
double reduction::prixReduit(const double &prix) const {return prix- montantReduction(prix);}



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
    return prix*d_pourcentage/100;
}

double reductionPourcentage::pourcentage() const{
    return d_pourcentage;
}

class reductionFixe:public reduction{
public:
    reductionFixe(const double& montant);
    virtual double montantReduction(const double &prix) const override;
    double montant() const;
protected:
    double d_montant;
};
reductionFixe::reductionFixe(const double &montant) :d_montant(montant){};
double reductionFixe::montantReduction(const double &prix) const {
    if (d_montant >= prix) { return 0; }
    else { return d_montant; }
}
double reductionFixe::montant() const{return d_montant;}

#endif /* Reduction_h */
