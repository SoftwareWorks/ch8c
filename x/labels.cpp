//
// Created by xgallom on 10/29/18.
//

#include "labels.h"

namespace x
{
	size_t labels::next() const
	{
		return identifiers.size();
	}

	void labels::create(const string &identifier, size_t statement)
	{
		identifiers.push_back(identifier);
		statements.push_back(statement);
	}
}

