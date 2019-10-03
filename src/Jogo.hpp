#ifndef Jogo_hpp
#define Jogo_hpp

namespace Game {

	class Jogo
	{
	private:
		int status_code;
	public:
		void run();
		int getStatus_code() const { return this->status_code; };
	};

}

#endif
