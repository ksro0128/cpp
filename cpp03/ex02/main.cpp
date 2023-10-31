#include "FragTrap.hpp"

int main(void)
{
	FragTrap c("frag"); // 생성
	c.getInfo();
	c.attack("target"); // 공격 (ClapTrap 함수로 공격 상속)
	c.getInfo();
	c.takeDamage(70); // 공격 받음 (ClapTrap 함수로 공격받음 상속)
	c.getInfo();
	c.beRepaired(50); // 회복 (ClapTrap 함수로 회복 상속)
	c.getInfo();
	c.highFivesGuys(); // FravTrap의 고유 스킬
	c.getInfo();
	c.takeDamage(1000); // 죽임
	c.getInfo();
	c.highFivesGuys(); // 죽었을 때 스킬
	c.getInfo();
}