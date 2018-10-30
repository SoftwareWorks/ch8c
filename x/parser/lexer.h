//
// Created by xgallom on 10/29/18.
//

#ifndef CH8C_LEXER_H
#define CH8C_LEXER_H

#include "parser.tab.h"

namespace x
{
	namespace parser
	{
		symbol_type yylex(program &prog);
	}
}

#endif //CH8C_LEXER_H
