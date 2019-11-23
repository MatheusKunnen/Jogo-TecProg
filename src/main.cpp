//
//  main.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 8/22/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Jogo/Jogo.hpp"

using Game::Jogo;

int main(int argc, char** argv){
    // Atualiza random seed
    srand((int)time(0));
    // Instacia classe principal Jogo
	Jogo* main_jogo = (argc > 1) ? Game::Jogo::getInstance(argv[1]) : Game::Jogo::getInstance();
	main_jogo->run();
	// Verifica codigo de saida de Jogo
	int exit_code = main_jogo->getStatusCode();
    // Desaloca classe principal
	delete(main_jogo);
    // Retorna codigo de estado
	return exit_code;
}
