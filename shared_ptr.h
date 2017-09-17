#pragma once
#include <boost/smart_ptr.hpp>

void test_shared_ptr()
{
	boost::shared_ptr<int> sp(new int(10));
	assert(sp.unique());

	boost::shared_ptr<int> sp2 = sp;
	assert(sp == sp2 && sp.use_count() == 2);

	*sp2 = 100;
	assert(*sp == 100);

	sp.reset();
	assert(sp.get() == 0);


}
