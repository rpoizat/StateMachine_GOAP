#include "Ville.h"


void Ville::setNombreVillageoisTotaux(int unNombreDeVillageois)
{

	nombreVillageoisTotaux = unNombreDeVillageois;

}

void Ville::setNombreVillageoisBois(int unNombreDeVillageois)
{

	nombreVillageoisBois = unNombreDeVillageois;

}

void Ville::setNombreVillageoisLibre(int unNombreDeVillageois)
{

	nombreVillageoisLibre = unNombreDeVillageois;

}

void Ville::setBoisTotal(int unNombreDeRessource)
{

	boisTotal = unNombreDeRessource;

}

int Ville::getBoisTotal() const {

	return boisTotal;

}

int Ville::getNombreVillageoisBois() const {

	return nombreVillageoisBois;

}

int Ville::getNombreVillageoisTotaux() const {

	return nombreVillageoisTotaux;

}

int Ville::getNombreVillageoisLibre() const {

	return nombreVillageoisLibre;

}

void Ville::addNombreVillageoisTotaux(int unNombreDeVillageois)
{

	nombreVillageoisTotaux = nombreVillageoisTotaux + unNombreDeVillageois;

}

void Ville::addNombreVillageoisBois(int unNombreDeVillageois)
{

	nombreVillageoisBois = nombreVillageoisBois + unNombreDeVillageois;

}

void Ville::addNombreVillageoisLibre(int unNombreDeVillageois)
{

	nombreVillageoisLibre = nombreVillageoisLibre + unNombreDeVillageois;

}

void Ville::addBoisTotal(int unNombreDeRessource)
{

	boisTotal = boisTotal + unNombreDeRessource;

}

