#include "PmergeMe.hpp"
#include <sys/time.h>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Usage : <" << argv[0] << "> <positive integer> ..." << std::endl;
		return 1;
	}
	// vector
	struct timeval start_v, end_v;
	gettimeofday(&start_v, NULL);
	std::vector< std::pair<int, int> > v;
	for (int i = 1; i < argc; i++)
	{
		int x = PmergeMe::stringToInt(argv[i]);
		if (x < 1)
		{
			std::cout << "Invalid value input" << std::endl;
			return 1;
		}
		v.push_back(std::pair<int, int>(x, i - 1));
	}
	std::vector< std::pair<int, int> > sorted_v = PmergeMe::caseVector(v);
	// for (size_t i = 0; i < sorted_v.size(); i++)
	// {
	// 	std::cout << sorted_v[i].first << " ";
	// }
	// std::cout << std::endl;
	gettimeofday(&end_v, NULL);
	long seconds_v = end_v.tv_sec - start_v.tv_sec;
    long microseconds_v = end_v.tv_usec - start_v.tv_usec;
    double elapsed_v = seconds_v + microseconds_v * 1e-6;


	// list
	struct timeval start_l, end_l;
	gettimeofday(&start_l, NULL);

	std::list< std::pair<int, int> > l;
	for (int i = 1; i < argc; i++)
	{
		int x = PmergeMe::stringToInt(argv[i]);
		if (x < 1)
		{
			std::cout << "Invalid value input" << std::endl;
			return 1;
		}
		l.push_back(std::pair<int, int>(x, i - 1));
	}
	std::list< std::pair<int, int> > sorted_l = PmergeMe::caseList(l);
	// std::list< std::pair<int, int> >::iterator iter = sorted_l.begin();
	// while (iter != sorted_l.end())
	// {
	// 	std::cout << iter->first << " ";
	// 	iter++;
	// }
	// std::cout << std::endl;
	gettimeofday(&end_l, NULL);
	long seconds_l = end_l.tv_sec - start_l.tv_sec;
    long microseconds_l = end_l.tv_usec - start_l.tv_usec;
    double elapsed_l = seconds_l + microseconds_l * 1e-6;
	std::cout << "Before: ";
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i].first << " ";
	std::cout << std::endl;
	std::cout << "After: ";
	for (size_t i = 0; i < sorted_v.size(); i++)
		std::cout << sorted_v[i].first << " ";
	std::cout << std::endl;
	std::cout << std::fixed << "Time to process a range of " << argc - 1 << " elements with std::vector : " << elapsed_v << " sec" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::list   : " << elapsed_l << " sec" << std::endl;
}