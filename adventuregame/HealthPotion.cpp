#include "HealthPotion.h"

HealthPotion::HealthPotion() {
	amount = 5;
}
HealthPotion::~HealthPotion() {

}

int HealthPotion::GetHealAmount() {
	return amount;
}