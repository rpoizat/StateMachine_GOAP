#include <iostream>
#include <string>
#include "Libele.h"
#include "Ville.h"

class Effet
{

	protected :

		libele unLibele;

	public :

		Effet();

		Effet(libele unLibele);

		~Effet();

		virtual void lancerEffet(Ville& uneVille) const;
		virtual bool testPrerequis(Ville& uneVille) const;

};

class effetCreerVillageois : public Effet
{

public:

	effetCreerVillageois();

	effetCreerVillageois(libele unLibele);

	~effetCreerVillageois();

	virtual void lancerEffet(Ville& uneVille) const;
	virtual bool testPrerequis(Ville& uneVille) const;

};

class effetAssignerAuBois : public Effet
{

public:

	effetAssignerAuBois();

	effetAssignerAuBois(libele unLibele);

	~effetAssignerAuBois();

    virtual void lancerEffet(Ville& uneVille) const;
	virtual bool testPrerequis(Ville& uneVille) const;

};

class effetCouperBois : public Effet
{
public:

	effetCouperBois();

	effetCouperBois(libele unLibele);

	~effetCouperBois();

    virtual void lancerEffet(Ville& uneVille) const;
	virtual bool testPrerequis(Ville& uneVille) const;

};

class effetAllumerFeu : public Effet
{
public:

	effetAllumerFeu();

	effetAllumerFeu(libele unLibele);

	~effetAllumerFeu();

	virtual void lancerEffet(Ville& uneVille) const;
	virtual bool testPrerequis(Ville& uneVille) const;

};

