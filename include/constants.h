#pragma once
#include <string>
#include <map>
#include <boost/preprocessor.hpp>
#include "macros.h"
enum User{
	Admin,
	Representative
};

DEFINE_ENUM_WITH_STRING_CONVERSIONS(MembershipCategories, (Classic)(Gold)(Platinum)(No)) //For tests
// enum MembershipCategories{
// 	Classic=1,
// 	Gold=2,
// 	Platinum=3
// };

extern std::map<int, std::string> memberCategoryMap;