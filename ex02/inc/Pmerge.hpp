#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <vector>
#include <iostream>
#include <deque> 

class Pmerge {

	public:
		Pmerge();
		Pmerge(const Pmerge& other);
		~Pmerge();
		Pmerge& operator=(const Pmerge& other);
		void pmerge(std::string input);
	private:
		std::vector<uint> vec;
		std::deque<uint> que;
		void sort_vec(std::vector<uint>& in);
		void sort_que(std::deque<uint>& in);
};

#endif