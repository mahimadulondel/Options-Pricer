#pragma once
#include <iostream>
#include <vector>
#include <iomanip>

template <typename T>
class BinaryTree
{

private:
	int _depth;
	std::vector<std::vector<T>> _tree;

public:
	BinaryTree()
	{
		_depth = 0;
	}


	int getDepth()
	{
		return _depth;
	}

	void setDepth(int depth)
	{
		if (depth <= 0)
		{
			std::cout << "Profondeur non valide";
		}
		else if (depth != _depth)
		{
			if (depth < _depth)
			{
				_tree.resize(depth);
				_tree.shrink_to_fit();
			}
			else
			{
				_tree.resize(depth);
				for (int i = _depth; i < depth; i++)
				{
					_tree[i].resize(i + 1);
				}
			}
			_depth = depth;
		}

	}

	void setNode(int n, int i, T newNode)
	{
		if (n < _depth && i <= n)
		{
			if (_tree[n].size() == 0)
			{
				_tree[n].resize(n + 1);
			}
			_tree[n][i] = newNode;
		}
	}

	T getNode(int n, int i)
	{
		if (n < _depth && i <= n)
		{
			return _tree[n][i];
		}
	}

	void display()
	{
		
		for (int n = 0; n < _depth; n++)
		{
			for (int i = 0; i <= n; i++)
			{
				if (i != n)
				{
					std::cout << _tree[n][i] << "\t";
				}
				else
				{
					std::cout << _tree[n][i] << std::endl;
				}
			}
		}
		std::cout << std::endl;

		for (int n = 0; n < _depth; n++)
		{
			int height = (_depth - n)*2;
			if (_tree[n].size() == 1)
			{
				std::cout << std::setw(double(height) * 2 - 1);
				std::cout << _tree[n][0];
				std::cout << std::endl;
			}
			else
			{
				std::cout << std::setw(double(height) * 2);
				bool left = true;
				for (int i = 0; i <= n; i++)
				{
					if (i == 0 || i == n)
					{
						if (left == true)
						{
							std::cout << "/" << "    ";
						}
						else
						{
							std::cout << "\\";
						}
						
						left = !left;
					}
					else
					{
						std::cout << "\\  /    ";
					}
				}
				std::cout << std::endl;
				std::cout << std::setw(double(height) * 2 - 1);
				for (int i = 0; i <= n; i++)
				{
					if (i != 0)
					{
						if (_tree[n][i] < 100)
						{
							std::cout << "      ";
						}
						else
						{
							std::cout << "     ";
						}
					}

					std::cout << _tree[n][i];
				}
				std::cout << std::endl;
			}
		}
	}
};

