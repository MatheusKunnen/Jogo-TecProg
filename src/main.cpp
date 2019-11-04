//
//  main.cpp
//  Jogo-SFML
//
//  Created by Matheus Kunnen Ledesma on 8/22/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include <iostream>
#include "Jogo/Jogo.hpp"

using Game::Jogo;

int main(int argc, char** argv)
{
	Jogo* main_jogo = Game::Jogo::getInstance();
	main_jogo->run();
	
	int exit_code = main_jogo->getStatusCode();

	delete(main_jogo);
    
	return exit_code;
}
