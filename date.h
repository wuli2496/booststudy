#pragma once
#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>

using namespace boost::gregorian;

void test_date()
{
	date d1;
	std::cout << d1 << std::endl;
}