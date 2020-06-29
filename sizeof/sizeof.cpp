#include <iostream>
#include <array>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <forward_list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main()
{
	array<int, 0> array_cont;
	cout << "sizeof(array)=" << sizeof(array_cont) << endl;

	vector<int> vector_cont;
	cout << "sizeof(vector)=" << sizeof(vector_cont) << endl;

	priority_queue<int> priority_queue_cont;
	cout << "sizeof(priority_queue)=" << sizeof(priority_queue_cont) << endl;

	list<int> list_cont;
	cout << "sizeof(list)=" << sizeof(list_cont) << endl; 

	forward_list<int> forward_list_cont;
	cout << "sizeof(forward_list)=" << sizeof(forward_list_cont) << endl;

	deque<int> deque_cont;
	cout << "sizeof(deque)=" << sizeof(deque_cont) << endl;

	stack<int> stack_cont;
	cout << "sizeof(stack)=" << sizeof(stack_cont) << endl;

	queue<int> queue_cont;
	cout << "sizeof(queue)=" << sizeof(queue_cont) << endl; 

	set<int> set_cont;
	cout << "sizeof(set)=" << sizeof(set_cont) << endl;

	map<int, int> map_cont;
	cout << "sizeof(map)=" << sizeof(map_cont) << endl;

	multiset<int> multiset_cont;
	cout << "sizeof(multiset)=" << sizeof(multiset_cont) << endl;

	multimap<int, int> multimap_cont;
	cout << "sizeof(multimap)=" << sizeof(multimap_cont) << endl;

	unordered_set<int> unordered_set_cont;
	cout << "sizeof(unordered_set)=" << sizeof(unordered_set_cont) << endl;

	unordered_map<int, int> unordered_map_cont;
	cout << "sizeof(unordered_map)=" << sizeof(unordered_map_cont) << endl;
}
