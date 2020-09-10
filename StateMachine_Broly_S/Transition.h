#pragma once
#ifndef TRANSITION_H
#define TRANSITION_H


class Transition
{
	public:

		virtual bool Process(const unsigned int pv, const unsigned int meter, const unsigned int distance)=0;
};

class TransitionIsAlive : public Transition
{
public:

	bool Process(const unsigned int pv, const unsigned int meter, const unsigned int distance);
};

class TransitionMeter : public Transition
{
public :
	
	bool Process(const unsigned int pv, const unsigned int meter, const unsigned int distance);
};

class TransitionIsBlocked : public Transition
{
public:

	TransitionIsBlocked() {};

	bool Process(const unsigned int pv, const unsigned int meter, const unsigned int distance);
};

class TransitionCheckDistance : public Transition
{
private :

	unsigned int min;

public:

	TransitionCheckDistance() {};

	//constructeur
	TransitionCheckDistance(unsigned int mi);

	bool Process(const unsigned int pv, const unsigned int meter, const unsigned int distance);
};

class TransitionCombo : public Transition
{
public:

	bool Process(const unsigned int pv, const unsigned int meter, const unsigned int distance);
};

class TransitionMort : public Transition
{
public:

	bool Process(const unsigned int pv, const unsigned int meter, const unsigned int distance);
};

class TransitionVictoire : public Transition
{
public:

	bool Process(const unsigned int pv, const unsigned int meter, const unsigned int distance);
};

#endif