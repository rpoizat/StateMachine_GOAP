#include "Effet.h"
#include "Ville.h"

effetCreerVillageois::effetCreerVillageois(libele leLibele) {
    unLibele = leLibele;
}

effetAssignerAuBois::effetAssignerAuBois(libele leLibele) {
    unLibele = leLibele;
}

effetCouperBois::effetCouperBois(libele leLibele) {
    unLibele = leLibele;
}

effetAllumerFeu::effetAllumerFeu(libele leLibele) {
    unLibele = leLibele;
}

void effetCreerVillageois::lancerEffet(Ville& uneVille) const
{

    uneVille.addNombreVillageoisTotaux(1);
    uneVille.addNombreVillageoisLibre(1);


}

void effetAssignerAuBois::lancerEffet(Ville& uneVille) const
{
    uneVille.addNombreVillageoisBois(1);
    uneVille.addNombreVillageoisLibre(-1);
}

void effetCouperBois::lancerEffet(Ville& uneVille) const
{

    uneVille.addBoisTotal(50);

}

void effetAllumerFeu::lancerEffet(Ville& uneVille) const
{
    uneVille.addBoisTotal(-100);
}



bool effetAllumerFeu::testPrerequis(Ville& uneVille) const
{
    if (uneVille.getBoisTotal() >= 100) {
        return true;
    }

    else {
        return false;
    }
}

bool effetCouperBois::testPrerequis(Ville& uneVille) const
{
    if (uneVille.getNombreVillageoisBois() >= 1) {
        return true;
    }

    else {
        return false;
    }
}

bool effetAssignerAuBois::testPrerequis(Ville& uneVille) const
{
    if (uneVille.getNombreVillageoisLibre() >= 1) {
        return true;
    }
}

bool effetCreerVillageois::testPrerequis(Ville& uneVille) const
{
    return true;
} 



