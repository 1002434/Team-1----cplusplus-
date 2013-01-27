#ifndef __HEALTH_POTION__H
#define __HEALTH_POTION__H
// Taneli Peltoniemi
class HealthPotion {
private:
	int amount;
public:
	HealthPotion();
	~HealthPotion();
	
	int GetHealAmount();
};
#endif