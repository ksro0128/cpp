#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <vector>
# include <list>

class PmergeMe
{
	public:
		static int stringToInt(std::string str);
		static std::vector< std::pair<int, int> > caseVector(std::vector< std::pair<int, int> > v);
		static std::list< std::pair<int, int> > caseList(std::list< std::pair<int, int> > l);
	private:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& rhs);
		PmergeMe &operator=(const PmergeMe& rhs);
		std::vector< std::pair<int, int> > v;
		std::list< std::pair<int, int> > l;
		static void printVector(std::vector< std::pair<int, int> > v, std::string str);
		static std::vector< std::pair<int, int> > copyChainVector(std::vector< std::pair<int, int> > v);
		static std::vector< std::pair<int, int> > reorderVector(std::vector< std::pair<int, int> > a, std::vector< std::pair<int, int> > b);
		static bool binarySearchVector(std::vector< std::pair<int, int> >& a, std::pair<int, int> x, int end);
		static void printList(std::list< std::pair<int, int> > l, std::string str);
		static std::list< std::pair<int, int> > copyChainList(std::list< std::pair<int, int> > l);
		static std::list< std::pair<int, int> > reorderList(std::list< std::pair<int, int> > a, std::list< std::pair<int, int> > b);
		static bool binarySearchList(std::list< std::pair<int, int> >& a, std::pair<int, int> x, int end); 
};


#endif