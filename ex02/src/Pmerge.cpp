#include "../inc/Pmerge.hpp"

Pmerge::Pmerge(){}
Pmerge::Pmerge(const Pmerge& other){}
Pmerge::~Pmerge(){}
Pmerge& Pmerge::operator=(const Pmerge& other)
{
	return *this;
}
void Pmerge::pmerge(std::string input)
{

}

uint max(uint x, uint y)
{
	if (x > y)
		return x;
	return y;
}

uint min(uint x, uint y)
{
	if (x < y)
		return x;
	return y;
}

void Pmerge::sort_vec(std::vector<uint>& in)
{
	std::vector<uint> bigs;
	std::vector<uint> smalls;

	for (size_t i = 0; i + 1 < in.size(); i += 2)
	{
		bigs.push_back(max(in[i], in[i + 1]));
		smalls.push_back(min(in[i], in[i + 1]));
	}
	if (in.size() % 2 == 1)
		smalls.push_back(in[in.size() - 1]);
	sort_vec(bigs);
	in.clear();
	in = bigs;
	for (size_T i = 0; i < smalls.size(); i++)
	{
		
	}
}

void Pmerge::sort_que(std::deque<uint>& in)
{

}