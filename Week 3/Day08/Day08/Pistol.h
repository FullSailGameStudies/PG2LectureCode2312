#pragma once
#include "Weapon.h"
#include <algorithm>
class Pistol : public Weapon
{
public:
	Pistol(int range, int damage, int rounds, int magCap) : 
		Weapon(range, damage),
		rounds_(rounds),
		magCapacity_(magCap)
	{
	}

	int Rounds() { return rounds_; }
	int MagCapacity(){ return magCapacity_; }

	void Rounds(int rounds) { rounds_ = rounds; }
	void MagCapacity(int magCap) { magCapacity_ = magCap; }

	Pistol operator+(Pistol const& otherPistol)
	{
		Pistol newPistol(range(), damage(), rounds_, magCapacity_);
		rounds_ = std::min<int>(magCapacity_, rounds_ + otherPistol.rounds_);
		return newPistol;
	}

	void showMe() override;

private:
	int rounds_, magCapacity_;
};


