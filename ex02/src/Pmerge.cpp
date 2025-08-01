#include "../inc/Pmerge.hpp"

Pmerge::Pmerge(){}
Pmerge::Pmerge(const Pmerge& other){
	(void)other;
}
Pmerge::~Pmerge(){}
Pmerge& Pmerge::operator=(const Pmerge& other)
{
	(void)other;
	return *this;
}
void Pmerge::pmerge(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++)
	{
		this->vec.push_back(atoi(argv[i]));
	}
	sort_vec(this->vec);
	for (size_t i = 0; i < this->vec.size(); i++)
	{
		std::cout << this->vec[i] << std::endl;
	}
}

unsigned int max(unsigned int x, unsigned int y)
{
	if (x > y)
		return x;
	return y;
}

unsigned int min(unsigned int x, unsigned int y)
{
	if (x < y)
		return x;
	return y;
}

size_t find_index(size_t index, std::vector<unsigned int>& bigs, std::vector<unsigned int>& sorted)
{
	size_t i;
	for (i = 0; i < sorted.size(); i++)
	{
		if (bigs[index] == sorted[i])
			return i;
	}

	return i ;
}

void	insert_small(size_t begin, size_t pair_index, std::vector<unsigned int>& sorted, unsigned int small)
{
	size_t mid = begin + (pair_index - begin) / 2;
	if (begin >= pair_index)
	{
		std::vector<unsigned int>::iterator i = sorted.begin();
		for (size_t j = 0; j < pair_index; j++)
			i++;
		// if (sorted[pair_index] < small)
		// 	i++;
		sorted.insert(i, small);
	}
	else if (sorted[mid] > small)
		insert_small(0, mid, sorted, small);
	else if (sorted[mid] < small)
		insert_small(mid + 1, pair_index, sorted, small);
}

std::vector<size_t> generate_jacobsthal_indices(size_t n) {
    std::vector<size_t> indices;
    std::vector<size_t> j_seq;

    // Generate the Jacobsthal numbers until we exceed n
    j_seq.push_back(1); // J(1)
    j_seq.push_back(3); // J(2)
    size_t j = 2;
    while (true) {
        size_t next = j_seq[j - 1] + 2 * j_seq[j - 2];
        if (next >= n)
		{
			break;
		}
		j_seq.push_back(next);
        ++j;
    }
    // Add Jacobsthal indices in reverse order
    for (int i = j_seq.size() - 1; i >= 0; --i) {
        if (j_seq[i] < n) {
            indices.push_back(j_seq[i]);
        }
    }
    // Fill in remaining indices not in the sequence
	for (int i = n - 1; i >= 1; --i) {
		if (std::find(indices.begin(), indices.end(), i) == indices.end()) {
			indices.push_back(i);
		}
}
	for (size_t i = 0; i < indices.size(); i++)
		std::cout << indices[i] << std::endl;
	std::cout << "----------";
    return indices;
}


void Pmerge::sort_vec(std::vector<unsigned int>& in)
{
	std::vector<unsigned int> bigs;
	std::vector<unsigned int> smalls;
	int	uneven = 0;

	if (in.size() >= 2)
	{
		std::cout << "at this level :" << std::endl;
		for (size_t i = 0; i + 1 < in.size(); i += 2)
		{
			bigs.push_back(max(in[i], in[i + 1]));
			smalls.push_back(min(in[i], in[i + 1]));
		}
		if (in.size() % 2 == 1)
		{
			smalls.push_back(in[in.size() - 1]);
			uneven = 1;
		}
		// 		for (size_t i = 0; i < bigs.size(); i++)
		// 	std::cout << bigs[i] << std::endl;
		// std::cout << "----" << std::endl;
		// for (size_t i = 0; i < smalls.size(); i++)
		// 	std::cout << smalls[i] << std::endl;
		// std::cout << "----" << std::endl;
		std::vector<unsigned int> unsorted_bigs(bigs);
		sort_vec(bigs);
		in.clear();
		in = bigs;
		in.insert(in.begin(), smalls[0]);
		std::vector<size_t> indices = generate_jacobsthal_indices(smalls.size());
		for (size_t i = 0; i < smalls.size() - uneven; i++)
		{
			size_t pair_index = find_index(indices[i], unsorted_bigs, in);
			insert_small(0, pair_index, in, smalls[indices[i]]);
		}
		if (uneven)
			insert_small(0, in.size(), in, smalls[smalls.size() - 1]);
	}
	return ;
}

// void Pmerge::sort_que(std::deque<unsigned int>& in)
// {

// }