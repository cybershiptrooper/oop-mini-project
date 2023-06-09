#pragma once
#include <string>
#include "constants.h"
using namespace std;

class Membership{
	protected:
		const double fees;
		const double discount;
		const MembershipCategory type;
	public:
		Membership(double fees, double discount, MembershipCategory type): 
			fees(fees), discount(discount),type(type){};
		virtual ~Membership(){};
		double getFees(){return fees;};
		double getDiscount(){return discount;};
		MembershipCategory getType(){return type;};
};

class ClassicMembership: public Membership{
	public:
		ClassicMembership(): Membership(2000, 0.05, Classic){};
		~ClassicMembership(){};
};

class GoldMembership: public Membership{
	public:
		GoldMembership(): Membership(5000, 0.10, Gold){};
		~GoldMembership(){};
};

class PlatinumMembership: public Membership{
	public:
		PlatinumMembership(): Membership(10000, 0.15, Platinum){};
		~PlatinumMembership(){};
};

class NoMembership: public Membership{
	public:
		NoMembership(): Membership(0, 0, No){};
		~NoMembership(){};
};

// class StandardMembership: public Membership{
// 	public:
// 		StandardMembership(): Membership(0, 0.0, "Standard"){};
// 		~StandardMembership(){};
// };