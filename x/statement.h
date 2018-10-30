//
// Created by xgallom on 10/28/18.
//

#ifndef CH8C_STATEMENT_H
#define CH8C_STATEMENT_H

#include <string>
#include <variant>

using namespace std;

namespace x
{
#define LIST_FOR_STATEMENT_TYPE(OP) \
    OP(block), OP(cond), OP(loop), OP(jump), OP(call), OP(ret), OP(assign), OP(nop)

#define FOR_STATEMENT_TYPE(OP) \
    OP(block) OP(cond) OP(loop) OP(jump) OP(call) OP(ret) OP(assign) OP(nop)

#define O(P) P
	enum class statement_type {
		LIST_FOR_STATEMENT_TYPE(O),
		size
	};
#undef O

	template<statement_type>
	struct statement_data {
	};

	template<>
	struct statement_data<statement_type::block> {
		size_t size;
	};

	template<>
	struct statement_data<statement_type::cond> {
		size_t expr;
	};

	template<>
	struct statement_data<statement_type::loop> {
		size_t expr;
	};

	template<>
	struct statement_data<statement_type::jump> {
		string label;
	};

	template<>
	struct statement_data<statement_type::call> {
		string function;
	};

	struct statement {
		statement_type type;

#define O(P) statement_data<statement_type::P>
		variant<LIST_FOR_STATEMENT_TYPE(O) > data;
#undef O
	};
}
#endif //CH8C_STATEMENT_H
