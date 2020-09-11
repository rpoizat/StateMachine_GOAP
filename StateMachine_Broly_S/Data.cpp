#pragma once
#include "pch.h"
#include "Data.h"
#include <iostream>


Data::Data()
{
	pv = 10000;
	meter = 0;
	distance = 0;
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
}
void Data::ReduceDistance(bool dash)
{
	if (dash) distance = 0;
	else distance = rand() % distance;
}