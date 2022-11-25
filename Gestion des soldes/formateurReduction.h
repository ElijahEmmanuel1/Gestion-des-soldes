//
// Created by Elijah Loïc BODIPO OBIANG on 25/11/2022.
//

#ifndef GESTION_DES_SOLDES_FORMATEURREDUCTION_H
#define GESTION_DES_SOLDES_FORMATEURREDUCTION_H
#include <iostream>
#include "Reduction.h"
class formateurReduction{
public:
    virtual std::string reductionFixeFormatee(const reductionFixe& reduc) const;
    virtual std::string reductionPourcentageFormatee(const reductionPourcentage& reduc) const;
};

std::string formateurReduction::reductionFixeFormatee(const reductionFixe &reduc) const {
    return std::to_string(reduc.montant());
}

std::string formateurReduction::reductionPourcentageFormatee(const reductionPourcentage &reduc) const {
    return std::to_string(reduc.pourcentage());
}

class formateurReductionTexte:public formateurReduction{
public:
    formateurReductionTexte(const reduction& reduc);
    virtual std::string reductionFixeFormatee(const reductionFixe& reduc) const override;
    virtual std::string reductionPourcentageFormatee(const reductionPourcentage& reduc) const override;
private:
    reduction d_reduc;
};

formateurReductionTexte::formateurReductionTexte(const reduction &reduc):d_reduc(reduc) {}

std::string formateurReductionTexte::reductionFixeFormatee(const reductionFixe &reduc) const {
    return "Réduction fixe de "+ formateurReduction::reductionFixeFormatee(reduc)+" EUR";
}

std::string formateurReductionTexte::reductionPourcentageFormatee(const reductionPourcentage &reduc) const {
    return "Réduction de pourcentage "+formateurReduction::reductionPourcentageFormatee(reduc)+" %";
}

#endif //GESTION_DES_SOLDES_FORMATEURREDUCTION_H
