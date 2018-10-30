//
// Created by xgallom on 10/29/18.
//

#include "parser.h"
#include "parser.tab.h"

namespace x
{
	namespace parser
	{
		void parse(program &prog)
		{
			parser p{prog};

			p.parse();
		}
	}
}
