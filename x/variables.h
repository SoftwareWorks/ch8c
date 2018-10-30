//
// Created by xgallom on 10/29/18.
//

#ifndef CH8C_VARIABLES_H
#define CH8C_VARIABLES_H

#include "variable.h"

#include <vector>

namespace x
{
	struct variables {
		vector<variable> vars;

#define O(P) vector<variable_data<variable_type::P>> P##_data;
		FOR_VARIABLE_TYPE(O)
#undef O

		template<variable_type type>
		size_t next() const;

		template<variable_type type>
		void create(const string &identifier, const variable_data<type> &data);
	};
}

#endif //CH8C_VARIABLES_H
