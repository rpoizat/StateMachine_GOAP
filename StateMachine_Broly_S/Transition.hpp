#pragma once

using namespace std;

class Transition
{
	public:

		virtual bool Process(const unsigned int pv, const unsigned int meter, const unsigned int distance)=0;
};

class TransitionIsAlive : public Transition
{
public:

	bool Process(const unsigned int pv, const unsigned int meter, const unsigned int distance)
	{
		if (pv > 0) return true;
		else return false;
	}
};

class TransitionMeter : public Transition
{
public :
	
	bool Process(const unsigned int pv, const unsigned int meter, const unsigned int distance)
	{
		if (meter >= 3)
		{
			return true;
		}
		else return false;
	}
};

class TransitionIsBlocked : public Transition
{
public:

	TransitionIsBlocked() {};

	bool Process(const unsigned int pv, const unsigned int meter, const unsigned int distance)
	{
		unsigned int r = rand() % 1;

		if (r == 1) return true;
		else
		{
			return false;
		}
	}
};

class TransitionCheckDistance : public Transition
{
private :

	unsigned int min;

public:

	TransitionCheckDistance() {};

	//constructeur
	TransitionCheckDistance(unsigned int mi)
	{
		min = mi;
	}

	bool Process(const unsigned int pv, const unsigned int meter, const unsigned int distance)
	{
		if (distance <= min) return true;
		else return false;
	}
};

class TransitionCombo : public Transition
{
public:

	bool Process(const unsigned int pv, const unsigned int meter, const unsigned int distance)
	{
		return true;
	}
};

class TransitionMort : public Transition
{
public:

	bool Process(const unsigned int pv, const unsigned int meter, const unsigned int distance)
	{
		return true;
	}
};

class TransitionVictoire : public Transition
{
public:

	bool Process(const unsigned int pv, const unsigned int meter, const unsigned int distance)
	{
		return true;
	}
};