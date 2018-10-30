//
// Created by xgallom on 10/28/18.
//

#include "functions.h"

namespace x
{
	size_t functions::create(const string &identifier, size_t statement)
	{
		auto rv = identifiers.size();

		identifiers.push_back(identifier);
		statements.push_back(statement);

		return rv;
	}
}
