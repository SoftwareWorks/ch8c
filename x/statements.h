//
// Created by xgallom on 10/28/18.
//

#ifndef CH8C_STATEMENTS_H
#define CH8C_STATEMENTS_H

#include "statement.h"

#include <vector>
using namespace std;

namespace x
{
	struct statements {
		vector<statement> statements;

		size_t next() const;

		template<statement_type type>
		void create(const statement_data<type> &data = statement_data<type>{});
	};
}

#endif //CH8C_STATEMENTS_H
