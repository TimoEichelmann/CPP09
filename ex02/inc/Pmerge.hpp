#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <vector>
#include <iostream>
#include <deque> 
#include <string>
#include <cstdlib>
#include <algorithm>

class Pmerge {

	public:
		Pmerge();
		Pmerge(const Pmerge& other);
		~Pmerge();
		Pmerge& operator=(const Pmerge& other);
		void pmerge(int argc, char *argv[]);
	private:
		std::vector<unsigned int> vec;
		std::deque<unsigned int> que;
		void sort_vec(std::vector<unsigned int>& in);
	//	void sort_que(std::deque<unsigned int>& in);
};

#endif