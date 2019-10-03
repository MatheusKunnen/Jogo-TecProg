//
//  main.cpp
//  SFML-Test
//
//  Created by Matheus Kunnen Ledesma on 8/22/19.
//  Copyright © 2019 Matheus Kunnen Ledesma. All rights reserved.
//

#include <iostream>
#include "Jogo.hpp"

using Game::Jogo;

int main()
{
	Jogo* main_jogo = new Jogo();
	main_jogo->run();
	
	int exit_code = main_jogo->getStatus_code();
	
	delete(main_jogo);
    
	return exit_code;
}
