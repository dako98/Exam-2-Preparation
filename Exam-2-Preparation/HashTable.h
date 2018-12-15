#ifndef _HASH_TABLE_
#define _HASH_TABLE_

#include <vector>
#include <list>
#include <iostream>


size_t hash(int element, int size)
{
	return element % size;
}

class HashTable
{

public:

	HashTable()
	{
		table.resize(2);
	}

	void Add(int element)
	{
		int index = hash(element, table.size());

		if (table[index].size()>= table.size()/2)
		{
			Rehash();
		}

		index = hash(element, table.size());

		table[index].push_back(element);
	}

	void Remove(int element)
	{
		int index = hash(element, table.size());

		table[index].remove(element);

	}

	int& Find(const int element)
	{
		int index = hash(element, table.size());

		for(int &chainElement : table[index])
			if (chainElement == element)
			{
				return chainElement;
			}
		throw std::invalid_argument("Not found.");
	}


	void Debug_PrintChains() const
	{
		int size = table.size();

		for (int i=0; i<size; ++i)
		{
			std::cout << i << ": ";

			for (int element : table[i])
				std::cout << element << " ";

			std::cout << '\n';
		}
	}

private:


	void Rehash()
	{
		std::vector<std::list<int>> tmp;

		tmp.resize(table.size() * 2);

		for (std::list<int> &chain : table)
		{
			for (int element : chain)
			{
				int index = hash(element, tmp.size());

				tmp[index].push_back(element);
			}
		}
		table = tmp;
	}


	std::vector<std::list<int>> table;
	
};










#endif // !_HASH_TABLE_
