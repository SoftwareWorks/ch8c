//
// Created by xgallom on 10/29/18.
//

#ifndef CH8C_PROGRAM_H
#define CH8C_PROGRAM_H

#include "functions.h"
#include "statements.h"
#include "variables.h"
#include "scope.h"
#include "labels.h"

namespace x
{
	struct program {
		scope current_scope;

		functions function_calls;
		statements code;
		labels jump_labels;
		variables data;

		void create_function(const string &identifier);

		template<statement_type type>
		void create_statement(const statement_data<type> &stmt_data = statement_data<type>{});

		void create_label(const string &identifier);

		template<variable_type type>
		void create_variable(const string &identifier, const variable_data<type> &var_data);
	};
}

#endif //CH8C_PROGRAM_H
