//
// Created by xgallom on 10/28/18.
//

#include "statements.h"

namespace x
{
	size_t statements::next() const
	{
		return statements.size();
	}

	template<statement_type type>
	void statements::create(const statement_data<type> &data)
	{
		statements.push_back(statement{type, data});
	}

#define O(P) template void statements::create<statement_type::P>(const statement_data<statement_type::P> &);
	FOR_STATEMENT_TYPE(O)
#undef O
}
