#pragma once
#include <boost/progress.hpp>
#include <vector>

void test_progress_display()
{
	std::vector<int> v(100, 10);
	boost::progress_display dis(v.size());
	
	for (size_t i = 0; i < v.size(); i++)
	{
		++dis;
	}
}

