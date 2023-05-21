#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(){
	printf("Hello world\n");
	SDL_Window *window = NULL;

	window = SDL_CreateWindow("SDL EXAMPLE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 200, 200, 0);
	//SDL_Delay(3000);
	//SDL_DestroyWindow(window);
	//SDL_Quit();


	int close = 0;
	while (!close){
	SDL_Event event;
	SDL_Rect location = {100,100, 50, 50};
	while (SDL_PollEvent(&event)){
		switch (event.type){
			case SDL_QUIT:
			printf("SDL_QUIT received...");
			close = 1;
			break;
		}
	}
	}
	return 0;
}
