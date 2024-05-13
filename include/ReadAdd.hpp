#ifndef ReadAdd_hpp
#define ReadAdd_hpp
#include "Hucre.hpp"
#include "Doku.hpp"
#include "Organ.hpp"
#include "Sistem.hpp"
#include "Organizma.hpp"
#include "IkiliAramaAgaci.hpp"
#include "Radix.hpp"

class ReadAdd
{
    public:
        ReadAdd();
        ~ReadAdd();
        static void ReadnAdd(Organizma* organism);
};

#endif