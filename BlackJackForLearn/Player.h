#pragma once
#include"Person.h"

class Player : public Person
{
public:
	Player(const char* pName);
	virtual ~Player();
    void PlayBase(Shoe& shoe) override;	// ƒ^[ƒ“ˆ—
};