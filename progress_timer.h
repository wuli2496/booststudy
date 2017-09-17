#pragma once
#include <boost/progress.hpp>

void test_progress_timer()
{
	boost::progress_timer t;
	for (int i = 0; i < 100; i++)
	{
		std::cout << "i:" << i << " ";
	}
}