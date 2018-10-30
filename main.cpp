#include "defines.h"
//#include "parser.h"
#include "program.h"

#include <iostream>

using namespace std;

static const char fname_out_default[] = "a.ch8";

struct config {
	const char *fname_in = nullptr;
	const char *fname_out = fname_out_default;
};

static int parse_args(int argc, char *argv[], config &rv);

int main(int argc, char *argv[])
{
	config cfg;

	if(parse_args(argc, argv, cfg))
		return ERROR_ARGUMENTS;

	// TODO: This
	x::program program;
	//x::parser::parse(program);

	program.create_function("strcpy");
	program.create_variable("n", x::variable_data<x::variable_type::var>{0x40});
	program.create_statement(x::statement_data<x::statement_type::loop>{0});
	program.create_statement(x::statement_data<x::statement_type::block>{2});
	program.create_statement(x::statement_data<x::statement_type::assign>{});
	program.create_statement(x::statement_data<x::statement_type::assign>{});
	program.create_statement(x::statement_data<x::statement_type::ret>{});

	program.create_function("main");
	program.create_variable("str", x::variable_data<x::variable_type::arr>{0x04, {0x15, 0xd3, 0x22, 0x00}});
	program.create_label("forever");
	program.create_statement(x::statement_data<x::statement_type::call>{"strcpy"});
	program.create_statement(x::statement_data<x::statement_type::assign>{});
	program.create_statement(x::statement_data<x::statement_type::jump>{"forever"});

	for(int n = 0; n < program.function_calls.identifiers.size(); ++n)
		cout << "function " << program.function_calls.identifiers[n] << ": "
		<< program.function_calls.statements[n] << endl;
	cout << endl;

	for(int n = 0; n < program.jump_labels.identifiers.size(); ++n)
		cout << "label " << program.jump_labels.identifiers[n] << ": "
		<< program.jump_labels.statements[n] << endl;
	cout << endl;

	for(const auto &stmt : program.code.statements)
		cout << "statement " << static_cast<int>(stmt.type) << endl;
	cout << endl;

	for(const auto &var : program.data.vars)
		cout << "variable " << var.identifier << endl;
	cout << endl;

	return SUCCESS;
}

static bool str_eq(const char *s1, const char *s2);
static void print_usage(const char prog_name[]);

static int parse_args(int argc, char *argv[], config &rv)
{
	for(int n = 1; n < argc; ++n) {
		if(str_eq(argv[n], "--help")) {
			print_usage(argv[0]);
			return SUCCESS;
		}
		else if(str_eq(argv[n], "-o")) {
			if(n == argc - 1) {
				cerr << "Error: Empty option -o\n";
				print_usage(argv[0]);
				return ERROR_ARGUMENTS;
			}

			rv.fname_out = argv[++n];
		}
		else
			rv.fname_in = argv[n];
	}

	if(!rv.fname_in) {
		cerr << "Error: File not specified\n";
		print_usage(argv[0]);
		return ERROR_ARGUMENTS;
	}

	return SUCCESS;
}

static bool str_eq(const char *s1, const char *s2)
{
	while(*s1 || *s2) {
		if((*s1 && !*s2) || (!*s1 && *s2) || *s1 != *s2)
			return false;

		++s1;
		++s2;
	}

	return true;
}

static void print_usage(const char prog_name[])
{
	cout
	<< "Usage: " << prog_name << " [options] input_file\n"
	<< "  options:\n"
	<< "    --help          Print this help\n"
	<< "    -o output_file  Set output file\n";
}

