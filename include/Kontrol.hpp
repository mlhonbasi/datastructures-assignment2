#ifndef Kontrol_hpp
#define Kontrol_hpp
#include "Organ.hpp"

class Kontrol
{
    public:
        Kontrol();
        ~Kontrol();
        bool needMutationOrgan(Organ* organ);
        bool needMutationHucre(Hucre* hucre);
};

#endif