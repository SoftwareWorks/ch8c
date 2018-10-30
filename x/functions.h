//
// Created by xgallom on 10/28/18.
//

#ifndef CH8C_FUNCTION_H
#define CH8C_FUNCTION_H

#include <string>
#include <vector>

using namespace std;

namespace x
{
	struct functions {
		vector<string> identifiers;
		vector<int> statements;

		size_t create(const string &identifier, size_t statement);
	};
}

#endif //CH8C_FUNCTION_H
