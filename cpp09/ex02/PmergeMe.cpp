#include "PmergeMe.hpp"

int PmergeMe::stringToInt(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]) == 0)
			return -1;
	}
	while (str[0] == '0')
	{
		if (str.length() == 1)
			break ;
		str.erase(0, 1);
	}
	if (str.length() > 10)
		return -1;
	unsigned int tmp = strtol(str.c_str(), NULL, 10);
	if (tmp > 2147483647)
		return -1;
	return static_cast<int>(tmp);
}

std::vector< std::pair<int, int> > PmergeMe::caseVector(std::vector< std::pair<int, int> > v)
{
	std::vector< std::pair<int, int> > main_chain;
	std::vector< std::pair<int, int> > sub_chain;
	std::vector< std::pair<int, int> > copy_chain;
	std::vector< std::pair<int, int> > ordered_chain;
	std::pair<int, int> remain;

	if (v.size() == 1)
		return v;
	for (size_t i = 1; i < v.size(); i += 2)
	{
		if (v[i - 1] < v[i])
		{
			main_chain.push_back(v[i]);
			sub_chain.push_back(v[i - 1]);
		}
		else
		{
			main_chain.push_back(v[i - 1]);
			sub_chain.push_back(v[i]);
		}
	}
	if (v.size() % 2 == 1)
		remain = v[v.size() - 1];
	copy_chain = copyChainVector(main_chain);

	// std::cout << "----------before----------\n";
	// printVector(main_chain, "main : ");
	// printVector(sub_chain, "sub  : ");
	// if (v.size() % 2 == 1)
	// 	std::cout << "remain : " << remain.first << std::endl;
	// std::cout << "--------------------------\n";
	if (main_chain.size() > 1)
	{
		ordered_chain = caseVector(copy_chain);
		main_chain = reorderVector(main_chain, ordered_chain);
		sub_chain = reorderVector(sub_chain, ordered_chain);
		// std::cout << "-----------binarysearch before----------\n";
		// printVector(ordered_chain, "ordered : ");
		// printVector(sub_chain, "sub     : ");
		// if (v.size() % 2 == 1)
		// 	std::cout << "remain  : " << remain.first << std::endl;
		// std::cout << "----------------------------------------\n";
		// std::cout << "first insertion" << std::endl;
		main_chain.insert(main_chain.begin(), sub_chain[0]);
		// printVector(main_chain, "main: ");
		// printVector(sub_chain, "sub : ");
		size_t cnt = sub_chain.size() - 1;
		size_t k = 2;
		size_t tmp = 1;
		size_t end = 2;
		size_t idx = (static_cast<int>(pow(2, k + 1)) + static_cast<int>(pow(-1, k))) / 3 - 1;
		while (cnt > 0)
		{
			if (idx > sub_chain.size() - 1)
			{
				idx--;
				end--;
				continue ;
			}
			// std::cout << "sub idx : " << idx << " value : " << sub_chain[idx].first << " search section : ~ " << end << std::endl;
			if (binarySearchVector(main_chain, sub_chain[idx], end) == true)
				end--;
			// printVector(main_chain, "main: ");
			// printVector(sub_chain, "sub : ");
			idx--;
			cnt--;
			if (tmp > idx)
			{
				tmp = (static_cast<int>(pow(2, k + 1)) + static_cast<int>(pow(-1, k))) / 3;
				k++;
				idx = (static_cast<int>(pow(2, k + 1)) + static_cast<int>(pow(-1, k))) / 3 - 1;
				end = static_cast<int>(pow(2, k)) - 2;
			}
		}
		if (v.size() % 2 == 1)
			binarySearchVector(main_chain, remain, main_chain.size() - 1);

	}
	else
	{
		main_chain.insert(main_chain.begin(), sub_chain[0]);
		if (v.size() % 2 == 1)
			binarySearchVector(main_chain, remain, main_chain.size() - 1);
		// std::cout << "-----------binarysearch after----------\n";
		// printVector(main_chain, "main : ");
		// std::cout << "--------------------------\n";
		return main_chain;
	}
	// std::cout << "---------------------------------------\n";
	// if (v.size() % 2 == 1)
	// 	std::cout << "remain : " << remain.first << std::endl;
	// std::cout << "-----------binarysearch after----------\n";
	// printVector(main_chain, "main    : ");
	// std::cout << "---------------------------------------\n";

	return main_chain;
}

void PmergeMe::printVector(std::vector< std::pair<int, int> > v, std::string str)
{
	std::cout << str;
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i].first << " ";
	std::cout << std::endl;
}

std::vector< std::pair<int, int> > PmergeMe::copyChainVector(std::vector< std::pair<int, int> > v)
{
	std::vector< std::pair<int, int> > ret;

	for (size_t i = 0; i < v.size(); i++)
		ret.push_back(std::pair<int, int>(v[i].first, i));
	return ret;
}

std::vector< std::pair<int, int> > PmergeMe::reorderVector(std::vector< std::pair<int, int> > a, std::vector< std::pair<int, int> > b)
{
	std::vector< std::pair<int, int> > ret;

	for (size_t i = 0; i < a.size(); i++)
		ret.push_back(a[b[i].second]);
	return ret;
}

bool PmergeMe::binarySearchVector(std::vector< std::pair<int, int> >& a, std::pair<int, int> x, int end)
{
	int s = 0;
	int e = end;
	
	while (s <= e)
	{
		int mid = (s + e) / 2;
		if (a[mid].first > x.first)
			e = mid - 1;
		else
			s = mid + 1;
	}
	a.insert(a.begin() + s, x);
	if (s > end)
		return true;
	else
		return false;
}

std::list< std::pair<int, int> > PmergeMe::caseList(std::list< std::pair<int, int> > l)
{
	std::list< std::pair<int, int> > main_chain;
	std::list< std::pair<int, int> > sub_chain;
	std::list< std::pair<int, int> > copy_chain;
	std::list< std::pair<int, int> > ordered_chain;
	std::pair<int, int> remain;
	if (l.size() == 1)
		return l;
	for (size_t i = 1; i < l.size(); i += 2)
	{
		std::list< std::pair<int, int> >::iterator prev = l.begin();
		std::list< std::pair<int, int> >::iterator it = l.begin();
		std::advance(prev, i - 1);
		std::advance(it, i);
		if (prev->first < it->first)
		{
			main_chain.push_back(*it);
       		sub_chain.push_back(*prev);
		}
		else
		{
			main_chain.push_back(*prev);
        	sub_chain.push_back(*it);
		}
	}
	if (l.size() % 2 == 1)
    	remain = *l.rbegin();
	copy_chain = copyChainList(main_chain);
	// std::cout << "----------before----------\n";
	// printList(main_chain, "main : ");
	// printList(sub_chain, "sub  : ");
	// if (l.size() % 2 == 1)
	// 	std::cout << "remain : " << remain.first << std::endl;
	// std::cout << "--------------------------\n";
	if (main_chain.size() > 1)
	{
		ordered_chain = caseList(copy_chain);
		main_chain = reorderList(main_chain, ordered_chain);
		sub_chain = reorderList(sub_chain, ordered_chain);
		// std::cout << "-----------binarysearch before----------\n";
		// printList(ordered_chain, "ordered : ");
		// printList(sub_chain, "sub     : ");
		// if (l.size() % 2 == 1)
		// 	std::cout << "remain  : " << remain.first << std::endl;
		// std::cout << "----------------------------------------\n";
		// std::cout << "first insertion" << std::endl;
		main_chain.push_front(*sub_chain.begin());
		// printList(main_chain, "main: ");
		// printList(sub_chain, "sub : ");
		size_t cnt = sub_chain.size() - 1;
		size_t k = 2;
		size_t tmp = 1;
		size_t end = 2;
		size_t idx = (static_cast<int>(pow(2, k + 1)) + static_cast<int>(pow(-1, k))) / 3 - 1;
		while (cnt > 0)
		{
			if (idx > sub_chain.size() - 1)
			{
				idx--;
				end--;
				continue ;
			}
			std::list< std::pair<int, int> >::iterator siter = sub_chain.begin();
			std::advance(siter, idx); 
			// std::cout << "sub idx : " << idx << " value : " << siter->first << " search section : ~ " << end << std::endl;
			if (binarySearchList(main_chain, *siter, end) == true)
				end--;
			// printList(main_chain, "main: ");
			// printList(sub_chain, "sub : ");
			idx--;
			cnt--;
			if (tmp > idx)
			{
				tmp = (static_cast<int>(pow(2, k + 1)) + static_cast<int>(pow(-1, k))) / 3;
				k++;
				idx = (static_cast<int>(pow(2, k + 1)) + static_cast<int>(pow(-1, k))) / 3 - 1;
				end = static_cast<int>(pow(2, k)) - 2;
			}
		}
		if (l.size() % 2 == 1)
			binarySearchList(main_chain, remain, main_chain.size() - 1);
	}
	else
	{
		main_chain.push_front(*sub_chain.begin());
		if (l.size() % 2 == 1)
			binarySearchList(main_chain, remain, main_chain.size() - 1);
		// std::cout << "-----------binarysearch after----------\n";
		// printList(main_chain, "main : ");
		// std::cout << "--------------------------\n";
		return main_chain;
	}
	// std::cout << "---------------------------------------\n";
	// if (l.size() % 2 == 1)
	// 	std::cout << "remain : " << remain.first << std::endl;
	// std::cout << "-----------binarysearch after----------\n";
	// printList(main_chain, "main    : ");
	// std::cout << "---------------------------------------\n";
	return main_chain;
}

void PmergeMe::printList(std::list< std::pair<int, int> > l, std::string str)
{
	std::cout << str;
	for (std::list< std::pair<int, int> >::iterator it = l.begin(); it != l.end(); ++it)
	{
		std::cout << it->first << " ";
	}
	std::cout << std::endl;
}

std::list< std::pair<int, int> > PmergeMe::copyChainList(std::list< std::pair<int, int> > l)
{
	std::list< std::pair<int, int> > ret;
	std::list< std::pair<int, int> >::iterator iter = l.begin();
	int idx = 0;
	while (iter != l.end())
	{
		ret.push_back(std::pair<int, int>(iter->first, idx));
		idx++;
		iter++;
	}
	return ret;
}

std::list< std::pair<int, int> > PmergeMe::reorderList(std::list< std::pair<int, int> > a, std::list< std::pair<int, int> > b)
{
	std::list< std::pair<int, int> > ret;
	std::list< std::pair<int, int> >::iterator biter = b.begin();

	for (size_t i = 0; i < a.size(); i++)
	{
		int idx = biter->second;
		biter++;
		std::list< std::pair<int, int> >::iterator aiter = a.begin();
		std::advance(aiter, idx);
		ret.push_back(*aiter);
	}
	return ret;
}


bool PmergeMe::binarySearchList(std::list< std::pair<int, int> >& a, std::pair<int, int> x, int end)
{
	int s = 0;
	int e = end;
	
	while (s <= e)
	{
		int mid = (s + e) / 2;
		std::list< std::pair<int, int> >::iterator iter = a.begin();
		std::advance(iter, mid);
		if (iter->first > x.first)
			e = mid - 1;
		else
			s = mid + 1;
	}
	std::list< std::pair<int, int> >::iterator iter = a.begin();
	std::advance(iter, s);
	a.insert(iter, x);
	if (s > end)
		return true;
	else
		return false;
}