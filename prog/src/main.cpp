#include <iostream>
#include <argp.h>

int parse_opt(int key, char *arg, struct argp_state *state)
{
	int* arg_count = (int*) state->input;

	switch(key)
	{
		case 'p':
			// activer le flag correspondant
			std::cout << "Voici le programme affiché..." << std::endl;
			break;
		case 'a':
			// activer le flag correspondant
			std::cout << "Analyse statique en cours..." << std::endl;
			break;
		case 'e':
			// activer le flag correspondant
			std::cout << "Execution du programme..." << std::endl;
			break;
		case 'o':
			// activer le flag correspondant
			std::cout << "Transformation du code..." << std::endl;
			break;
		case ARGP_KEY_ARG:
			
			(*arg_count)--;

			if(*arg_count >= 0) {
				// récupérer le nom du fichier lutin ici
				std::cout << "Fichier lutin demandé : " << arg << std::endl;
			}

			break;
		case ARGP_KEY_END:
			if(*arg_count > 0) {
				argp_failure(state, 1, 0, "Pas de fichier lutin passé en argument");
			}
			else if(*arg_count < 0) {
				argp_failure (state, 1, 0, "Un seul fichier lutin est accepté en argument");
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

	int arg_count = 1;

	argp_parse(&argp, argc, argv, 0, 0, &arg_count);

	return 0;
}