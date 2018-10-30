//
// Created by xgallom on 10/29/18.
//

#include "variables.h"

namespace x
{
#define O(P) template<> size_t variables::next<variable_type::P>() const { return P##_data.size(); }
 	FOR_VARIABLE_TYPE(O)
#undef O

#define O(P) \
	template<> \
	void variables::create<variable_type::P>(const string &identifier, const variable_data<variable_type::P> &data) \
	{ vars.push_back({identifier, variable_type::P, next<variable_type::P>()}); P##_data.push_back(data); }
	FOR_VARIABLE_TYPE(O)
#undef O
}

