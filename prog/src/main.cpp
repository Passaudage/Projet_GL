#include <iostream>
#include <argp.h>

#include <string>
#include <exception>

#include "Automate.hpp"
#include "symboles/Programme.hpp"
#include "Lexer.hpp"

struct arg_cmd_struct {
	bool afficher;
	bool analyser;
	bool executer;
	bool transformer;

	std::string fichier_lutin;

	int arg_count;
};

void traiter_lutin(arg_cmd_struct* arg_cmd)
{
	try {

		Automate automate(arg_cmd->fichier_lutin);

		// récupération du programme

		Programme* programme = automate.getProgramme();

		if(arg_cmd->transformer) {
			std::cout << "Transformation du code..." << std::endl;
			programme->transformer();
		}

		if(arg_cmd->afficher) {
			// si transformation avant, alors afficher via programme
			// sinon, afficher le fichier lutin de base
			std::cout << "Voici l'affichage du code..." << std::endl;
			if(arg_cmd->transformer) {
				programme->afficher();
			} else {
				//std::cout << automate.getLexer().getCode() << std::endl;
			}
		}

		if(arg_cmd->analyser) {
			std::cout << "Analyse statique en cours..." << std::endl;
		}

		if(arg_cmd->executer) {
			std::cout << "Execution du programme..." << std::endl;
		}

	} catch(std::exception& e) {

	} catch(char const* message) {
		std::cerr << "Une erreur est survenue : " << message << std::endl;
		std::cerr << "Sortie de Farfadet" << std::endl;
	}
}

int parse_opt(int key, char *arg, struct argp_state *state)
{
	arg_cmd_struct* arg_cmd = (arg_cmd_struct*) state->input;

	switch(key)
	{
		case 'p':
			arg_cmd->afficher = true;
			break;
		case 'a':
			arg_cmd->analyser = true;
			break;
		case 'e':
			arg_cmd->executer = true;
			break;
		case 'o':
			arg_cmd->transformer = true;
			break;
		case ARGP_KEY_ARG:
		
			(arg_cmd->arg_count)--;

			if(arg_cmd->arg_count >= 0) {
				// récupérer le nom du fichier lutin ici
				arg_cmd->fichier_lutin = arg;
			}

			break;
		case ARGP_KEY_END:
			if(arg_cmd->arg_count > 0) {
				argp_failure(state, 1, 0, "Pas de fichier lutin passé en argument");
			} else if(arg_cmd->arg_count < 0) {
				argp_failure (state, 1, 0, "Un seul fichier lutin est accepté en argument");
			} else {
				traiter_lutin(arg_cmd);
			}

	}
	return 0;
}

int main(int argc, char* argv[])
{
	struct argp_option options[] = 
	{
		{0, 'p', 0, 0, "Affiche le code du programme lutin"},
		{0, 'a', 0, 0, "Analyse statique du code lutin"},
		{0, 'e', 0, 0, "Execute le programme lutin"},
		{0, 'o', 0, 0, "Transforme et simplifie le code lutin"},
		{ 0 } 
	};

	struct argp argp = {options, parse_opt, "FILE"};
	arg_cmd_struct arg_cmd;

	arg_cmd.arg_count = 1;
	arg_cmd.afficher = false;
	arg_cmd.analyser = false;
	arg_cmd.transformer = false;
	arg_cmd.executer = false;

	argp_parse(&argp, argc, argv, 0, 0, &arg_cmd);

	return 0;
}