#pragma once
#include "IceCream.h"
class ChocolateChipIceCream : public IceCream
{
	int amountOfChips = 12;
	void lick() override;
};

