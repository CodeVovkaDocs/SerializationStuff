#pragma once
#include <vector>



class S_node
{
	friend class S_tree;
public:
	S_node(int data)
	{
		this->data = data;
	}

	void add_next(S_node* next_ptr)
	{
		next_.push_back(next_ptr);
	}

private:
	int data;
	std::vector<S_node*> next_;
};





class S_tree
{
public:

	S_tree()
	{
		root = NULL;
	}

	S_node* add_node(int data, int root_data)
	{
		if (root == NULL)
		{
			S_node* n_ptr = new S_node(data);
			root = n_ptr;
			return n_ptr;
		}

		if (find(root, data) == NULL)
		{
			S_node* n_ptr = new S_node(data);
			S_node* root_of = find(root, root_data);
			root_of->add_next(n_ptr);
			return n_ptr;
		}

		return NULL;
	}

	void print_found(int data)
	{
		S_node* n_ptr = find(root, data);
		if (n_ptr == NULL)
			printf("data not found\n");
		else
			printf("data: %d\n", n_ptr->data);
	}


	void print_tree()
	{
		print_nodes(root, 0);
	}

private:

	S_node* find(S_node* start, int data)
	{
		if (start->data == data)
		{
			return start;
		}

		for (auto n : start->next_)
		{
			auto found = find(n, data);

			if (found != NULL)
			{
				return found;
			}
		}

		return NULL;
	}

	void print_nodes(S_node* start, int level)
	{
		for (int i = 0; i < level; i++)
		{
			printf("    ");
		}

		printf("data: %d\n", start->data);

		for (auto n : start->next_)
		{
			print_nodes(n, level + 1);
		}

	}


	S_node* root;

};