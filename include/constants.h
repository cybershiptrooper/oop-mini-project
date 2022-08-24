#pragma once
#include <string>
#include <map>
#include "macros.h"
enum User{
	Admin,
	Representative
};

DEFINE_ENUM_WITH_STRING_CONVERSIONS(MembershipCategory, (No)(Classic)(Gold)(Platinum)) //For tests
// enum MembershipCategories{
// 	Classic=1,
// 	Gold=2,
// 	Platinum=3
// };

extern std::map<int, std::string> memberCategoryMap;

#define DAY 86400;
#define WEEK 7*DAY;
