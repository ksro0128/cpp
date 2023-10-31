#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap d("dia"); // 생성
	d.getInfo();
	d.attack("target"); // 공격 (ScavTrap 함수로 공격 상속)
	d.getInfo();
	d.takeDamage(70); // 공격 받음 (ClapTrap 함수로 공격받음 상속)
	d.getInfo();
	d.beRepaired(50); // 회복 (ClapTrap 함수로 회복 상속)
	d.getInfo();
	d.takeDamage(1000); // 죽임
	d.getInfo();
	d.whoAmI();
}