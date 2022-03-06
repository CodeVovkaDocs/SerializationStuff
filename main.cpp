#include "Socket.h"
#include <thread>
#include <vector>
#include <chrono>
//#include "SimpleTree.h"
#include "Serializer.h"

void calc_printSum(int a, int b)
{
	int c = a + b;
	//cout <<"sum of " << a << " and " << b << " -> result: " << c << endl;
	//this_thread::sleep_for(chrono::seconds(1));
	printf("sum of %d and %d -> %d \n", a, b, c);
}


class test_s
{
public:
	int x;
	int y;
	int* p;
	//void* h;
};

int main()
{
	test_s* tmp = NULL;
	test_s t;
	t.x = 1;
	t.y = 2;
	t.p = new int(100);
	//t.h = NULL;

	//printf("size with null: %d\n", sizeof(t));

	//t.p = new int(1000);
	//t.h = malloc(10);

	//("size with value: %d\n", sizeof(t));

	S_tree s_tree;
	AddToTree(s_tree, &t, sizeof(t), tmp);
	AddToTree(s_tree, &t.p,sizeof(int), &t);

	std::ofstream s("new.txt", std::ios::binary);

	s_tree.write_tree(s);

	s.close();

	t.x = 0;
	t.y = 0;
	t.p = NULL;

	int tpPrintMask = t.p == NULL ? 0 : *t.p;
	printf("Test class: x->%d y->%d *p->%d\n", t.x, t.y, tpPrintMask);




	S_tree s_tree1;
	test_s t2;
	t2.x = 0;
	t2.y = 0;
	t2.p = NULL;

	AddToTree(s_tree1, &t2, sizeof(t), tmp);
	AddToTree(s_tree1, &t2.p, sizeof(int), &t2);

	std::ifstream is("new.txt", std::ios::binary);

	s_tree1.read_tree(is);

	is.close();

	tpPrintMask = t2.p == NULL ? 0 : *t2.p;
	printf("Test class: x->%d y->%d *p->%d\n", t2.x, t2.y, tpPrintMask);





	///////////////////////////////////////////////////////



	/*S_tree tree;

	tree.add_node(5, 0);
	tree.add_node(8, 5);
	tree.add_node(30, 5);
	tree.add_node(20, 8);
	tree.add_node(22, 8);
	tree.add_node(7, 22);
	tree.add_node(1, 20);
	tree.add_node(2, 22);
	tree.add_node(3, 22);
	tree.add_node(70, 5);
	tree.add_node(111, 7);

	tree.print_tree();

	/*const int test_size = 5;

	vector<thread> threadPool;

	for (int i = 0; i < test_size; i++)
	{
		threadPool.push_back(thread(calc_printSum, i, test_size + i));
		//printf("Join on thread %d \n", i);
		//if(i != 2)
			//threadPool[i].join();
	}

	thread t11(calc_printSum, 11, 22);

	threadPool[0].join();
	this_thread::sleep_for(chrono::seconds(2));
	int t_index = 0;
	/*for (auto& t : threadPool)
	{
		printf("Join on thread %d \n",t_index++);
		t.join();
	}*/

	//for (int i = 0; i < 3; i++)
	//{
		//printf("Join on thread %d \n", 2);
		//this_thread::sleep_for(chrono::seconds(2));
		//threadPool[2].join();
	//}


	return 0;
}