//
// Created by xgallom on 10/29/18.
//

#ifndef CH8C_LABELS_H
#define CH8C_LABELS_H

#include <string>
#include <vector>

using namespace std;

namespace x
{
	struct labels {
		vector<string> identifiers;
		vector<size_t> statements;

		size_t next() const;
		void create(const string &identifier, size_t statement);
	};
}

#endif //CH8C_LABELS_H
