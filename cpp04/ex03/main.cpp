#include "main.hpp"

void leaks(void)
{
	system("leaks a.out");
}

int main()
{
	atexit(leaks);
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;


	// 여러 예외처리 테스트
	// IMateriaSource* s = new MateriaSource(); 
	// s->createMateria("ice"); // 아무것도 배우지 않고 ice를 생성 
	// s->learnMateria(new Ice());
	// s->learnMateria(new Ice());
	// s->learnMateria(new Ice());
	// s->learnMateria(new Ice());
	// s->learnMateria(new Ice()); // ice 4개 초과 배움
	// ICharacter* m = new Character("m");
	// AMateria* t;
	// t = s->createMateria("cure"); // 배우지 않은 스킬 생성 0이 반환
	// m->equip(t); // 0을 장착
	// t = s->createMateria("ice");
	// m->equip(t);
	// m->use(0, *m);
	// m->use(1, *m); // 없는 인덱스의 스킬을 사용
	// m->unequip(0);
	// m->unequip(1); // 없는 인덱스의 스킬을 해제
	// m->use(0, *m); // 해제한 인덱스의 스킬을 사용
	// delete m;
	// delete s;

	// 딥 카피 테스트
	// IMateriaSource* s = new MateriaSource();
	// s->learnMateria(new Ice());
	// Character m = Character("surkim");
	// AMateria *t;
	// t = s->createMateria("ice");
	// m.equip(t);
	// m.use(0, m);
	// Character n;
	// n = m;
	// m.unequip(0);
	// // m.use(0, n);
	// n.use(0, m);
	// delete s;

}