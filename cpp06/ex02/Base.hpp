#ifndef BASE_HPP
#define BASE_HPP

class Base 
{
	public:
		Base();
		virtual ~Base();
		Base(const Base &rhs);
		Base&	operator=(const Base& rhs);
	private:
};

#endif