#pragma once
#include "Alive.h"
class IAttacker
{
	virtual void ApplyDamage(Alive *a_target) = 0;
};

