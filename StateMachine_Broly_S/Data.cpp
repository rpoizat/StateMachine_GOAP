#pragma once
#include "pch.h"
#include "Data.h"
#include <iostream>
#include <random>

Data::Data()
{
	pv = 10000;
	meter = 0;
	distance = 10;
}

unsigned int Data::GetPv() const
{
	return pv;
}

unsigned short int Data::GetMeter() const
{
	return meter;
}

unsigned short int Data::GetDistance() const
{
	return distance;
}

void Data::TakeDamage()
{
	pv -= 2500;
	
}

void Data::AddMeter()
{
	meter++;

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 10);

	distance = dist6(rng);
}
void Data::ReduceDistance(bool dash)
{

	std::cout << "Distance de depart : " << distance;

	if (dash) distance = 1;

	else
	{
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 10);

		distance = dist6(rng);
	}

	std::cout << " Distance actuelle : " << distance << std::endl;
}