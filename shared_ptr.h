#pragma once
#include <boost/smart_ptr.hpp>

class shared
{
private:
	boost::shared_ptr<int> p;
public:
	shared(boost::shared_ptr<int> p_) : p(p_) {}
	void print()
	{
		std::cout << "count: " << p.use_count() << " v = " << *p << endl;
	}
};

void print_func(boost::shared_ptr<int> p)
{
	std::cout << "count: " << p.use_count() << " v = " << *p << std::endl;
}
void test_shared_ptr()
{
	/*
	boost::shared_ptr<int> sp(new int(10));
	assert(sp.unique());

	boost::shared_ptr<int> sp2 = sp;
	assert(sp == sp2 && sp.use_count() == 2);

	*sp2 = 100;
	assert(*sp == 100);

	sp.reset();
	assert(sp.get() == 0);
	*/

	/*
	boost::shared_ptr<int> spi(new int);
	assert(spi);
	*spi = 253;
	std::cout << spi.get() << std::endl;
	*/

	boost::shared_ptr<int> sp(new int(10));
	assert(sp.unique());

	boost::shared_ptr<int> sp2 = sp;
	assert(sp == sp2 && sp.use_count() == 2);
	*sp2 = 100;
	assert(*sp == 100);
	sp.reset();
	assert(!sp);

	boost::shared_ptr<int> p(new int(100));
	shared s1(p), s2(p);

	s1.print();
	s2.print();
	*p = 20;
	print_func(p);
	s1.print();
}

struct Node
{
	boost::shared_ptr<Node> _pre;
	boost::shared_ptr<Node> _next;

	~Node()
	{
		std::cout << "~Node()" << this << std::endl;
	}

	int data;
};

void testRecursiveSharedPtr()
{
	boost::shared_ptr<Node> node1(new Node());
	boost::shared_ptr<Node> node2(new Node());
	//node1->_next = node2;
	//node2->_pre = node1;

	std::cout << "node1.use_count():" << node1.use_count() << std::endl;
	std::cout << "node2.use_count():" << node2.use_count() << std::endl;
}

boost::shared_ptr<int> get(boost::shared_ptr<int> p)
{
	std::cout << "use_count1:" << p.use_count() << std::endl;
	boost::shared_ptr<int> q(p);
	std::cout << "use_count2:" << p.use_count() << std::endl;
	return q;
}

void testCopy()
{
	boost::shared_ptr<int> sp1(new int(10));
	std::cout << "use_count:" << sp1.use_count() << std::endl;
	std::cout << get(sp1).use_count() << std::endl;
}


