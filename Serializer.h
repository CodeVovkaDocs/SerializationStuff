#pragma once
#include <vector>
#include <fstream>

typedef unsigned char byte;

class S_node
{
	friend class S_tree;
public:
	S_node(int size, byte* loc)
	{
		data_size = size;
		data_loc = loc;
	}

	void add_next(S_node* next_ptr)
	{
		next_.push_back(next_ptr);
	}

private:
	byte* data_loc;
	int data_size;
	std::vector<S_node*> next_;
};

class S_tree
{
public:

	S_tree()
	{
		root = NULL;
	}

	S_node* add_node(int size, byte* loc, byte* root_loc)
	{
		if (root == NULL)
		{
			S_node* n_ptr = new S_node(size,loc);
			root = n_ptr;
			return n_ptr;
		}

		if (find(root, loc) == NULL)
		{
			S_node* n_ptr = new S_node(size, loc);
			S_node* root_of = find(root, root_loc);
			root_of->add_next(n_ptr);
			return n_ptr;
		}

		return NULL;
	}

	void write_tree(std::ofstream& s)
	{
		write_nodes(root, s);
	}

	void read_tree(std::ifstream& s)
	{
		read_nodes(root, s);
	}

private:

	S_node* find(S_node* start, byte* loc)
	{
		if (start->data_loc == loc)
		{
			return start;
		}

		for (auto n : start->next_)
		{
			auto found = find(n, loc);

			if (found != NULL)
			{
				return found;
			}
		}

		return NULL;
	}

	void write_nodes(S_node* start, std::ofstream& s)
	{
		s.write(reinterpret_cast<char*>(start->data_loc), start->data_size);

		for (auto n : start->next_)
		{
			write_nodes(n, s);
		}
	}

	void read_nodes(S_node* start, std::ifstream& s)
	{
		s.read(reinterpret_cast<char*>(start->data_loc), start->data_size);

		for (auto n : start->next_)
		{
			read_nodes(n, s);
		}
	}


	S_node* root;

};


void AddToTree(S_tree& tree, void* data_ptr, int data_size, void* root_ptr)
{
	byte* data_ptr_byte = static_cast<byte*>(data_ptr);
	byte* root_ptr_byte = static_cast<byte*>(root_ptr);
	tree.add_node(data_size, data_ptr_byte, root_ptr_byte);
}