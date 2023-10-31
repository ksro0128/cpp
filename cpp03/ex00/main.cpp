#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a("clap"); // 생성

	a.getInfo();
	a.takeDamage(6); // 6대미지를 받음
	a.getInfo();
	a.beRepaired(4); // 수리
	a.getInfo();
	a.beRepaired(4); // 수리 (maxHP 초과 수리)
	a.getInfo();
	a.beRepaired(3); // 수리 (풀피일 때 수리)
	a.getInfo();
	a.attack("target"); // target 공격
	a.getInfo();
	for (int i = 0; i < 7; i++) // energy 전부 소모할 때 까지 공격
		a.attack("target");
	a.takeDamage(5); // 풀피가 아닌 상태로 만듦
	a.getInfo();
	a.beRepaired(5); // energy 전부 소진 됐을 때 수리
	a.getInfo();
	a.attack("target"); // energy 전부 소진 됐을 때 공격
	a.getInfo();
	a.takeDamage(10); // clap을 죽임
	a.getInfo();
	a.beRepaired(5); // 죽었을 때 수리
	a.getInfo();
	a.attack("target"); // 죽었을 때 공격
	a.getInfo();
	a.takeDamage(5); // 죽었을 때 대미지 받기
}