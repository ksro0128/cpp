#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap b("scav"); // 생성
	b.getInfo();
	b.attack("target"); // 공격 (ScavTrap 함수로 공격 오버라이딩)
	b.getInfo();
	b.takeDamage(70); // 공격 받음 (ClapTrap 함수로 공격받음 상속)
	b.getInfo();
	b.beRepaired(50); // 회복 (ClapTrap 함수로 회복 상속)
	b.getInfo();
	b.guardGate(); // ScavTrap의 고유 스킬
	b.getInfo();
	b.takeDamage(1000); // 죽임
	b.getInfo();
	b.guardGate(); // 죽었을 때 스킬
	b.getInfo();
}