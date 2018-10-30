//
// Created by xgallom on 10/29/18.
//

#include "program.h"

namespace x
{
	void program::create_function(const string &identifier)
	{
		function_calls.create(identifier, code.next());

		current_scope.scope_data = identifier;
		current_scope.scope_indexes = {identifier.size()};
	}

	template<statement_type type>
	void program::create_statement(const statement_data<type> &stmt_data)
	{
		code.create(stmt_data);
	}

#define O(P) \
	template void program::create_statement<statement_type::P>(const statement_data<statement_type::P> &);
	FOR_STATEMENT_TYPE(O)
#undef O

	void program::create_label(const string &identifier)
	{
		current_scope.scope_data.append("." + identifier);
		current_scope.scope_indexes.push_back(current_scope.scope_data.size());

		jump_labels.create(current_scope.scope_data, code.next());
	}

	template<variable_type type>
	void program::create_variable(const string &identifier, const variable_data<type> &var_data)
	{
		data.create(current_scope.scope_data + "." + identifier, var_data);
	}

#define O(P) \
	template void program::create_variable<variable_type::P>(const string &, const variable_data<variable_type::P> &);
	FOR_VARIABLE_TYPE(O)
#undef O
}