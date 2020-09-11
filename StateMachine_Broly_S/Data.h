#pragma once
#ifndef DATA_H
#define DATA_H

class Data
{
private:
	unsigned int pv;
	unsigned short int meter;
	unsigned short int distance;

public:
	Data();

	 unsigned int GetPv() const;
	 unsigned short int GetMeter() const;
	 unsigned short int GetDistance() const;

	void TakeDamage();
	void AddMeter();
	void ReduceDistance(bool dash);
};

#endif // !DATA_H
