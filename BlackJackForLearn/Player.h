#pragma once
#include"Person.h"

class Player : public Person
{
public:
	Player(const char* pName);
	virtual ~Player();
	bool Play(Shoe& shoe);	// ƒ^[ƒ“ˆ—
};