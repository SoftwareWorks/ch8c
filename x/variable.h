//
// Created by xgallom on 10/29/18.
//

#ifndef CH8C_VARIABLE_H
#define CH8C_VARIABLE_H

#include "defines.h"

#include <cstdint>
#include <array>
using namespace std;

namespace x
{
#define LIST_FOR_VARIABLE_TYPE(OP) \
    OP(var), OP(var16), OP(arr), OP(spr), OP(const_var), OP(const_var16), OP(const_arr), OP(const_spr)

#define FOR_VARIABLE_TYPE(OP) \
    OP(var) OP(var16) OP(arr) OP(spr) OP(const_var) OP(const_var16) OP(const_arr) OP(const_spr)

#define O(P) P
	enum class variable_type {
    	LIST_FOR_VARIABLE_TYPE(O)
	};
#undef O

	template<variable_type type>
	struct variable_data {
	};

	template<>
	struct variable_data<variable_type::var> {
		uint8_t value;
	};

	template<>
	struct variable_data<variable_type::var16> {
		uint16_t value;
	};

	template<>
	struct variable_data<variable_type::arr> {
		int size;
		array<uint8_t, ARRAY_MAX> value;
	};

	template<>
	struct variable_data<variable_type::spr> {
		int size;
		array<uint16_t, ARRAY_MAX> value;
	};

	template<>
	struct variable_data<variable_type::const_var> {
		const uint8_t value;
	};

	template<>
	struct variable_data<variable_type::const_var16> {
		const uint16_t value;
	};

	template<>
	struct variable_data<variable_type::const_arr> {
		const int size;
		const array<uint8_t, ARRAY_MAX> value;
	};

	template<>
	struct variable_data<variable_type::const_spr> {
		const int size;
		const array<uint16_t, ARRAY_MAX> value;
	};

	struct variable {
		string identifier;
		variable_type type;
		size_t data;
	};
}

#endif //CH8C_VARIABLE_H
