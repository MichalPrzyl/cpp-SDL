#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

int main(){
	printf("Hello world\n");
	SDL_Window *window = NULL;
	int width = 400;
	int height = 400;
	int square_width = 30;
	int square_height = 30;
	int change_in_position = 5;
	int delay = 20;

	window = SDL_CreateWindow("MP SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
	//SDL_Delay(3000);
	//SDL_DestroyWindow(window);
	//SDL_Quit();
	int start_position = 30;

	int close = 0;
	int x_position = start_position;
	
	SDL_Rect rectangle;

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	//
	// direction of moving
	bool going_right = true;

	// main loop
	while (!close){
		SDL_Event event;

		// renderer

		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_RenderClear(renderer);
		//SDL_RenderPresent(renderer);
		
		// trying to draw a rectangle
		//SDL_Rect rectangle ={100,100,30,30};

		 rectangle.x = x_position;
		 rectangle.y = 100;
		 rectangle.w = square_width;
		 rectangle.h = square_height;
		// printf("x_position: %i\n", x_position);
		// printf("rectangle_position: %i\n", rectangle.x);
		
		// adding position
		if (going_right){
			x_position += change_in_position;
		}
		else{
			x_position -= change_in_position;
		}
		// changing direction
		if (x_position >= width-square_width)
			going_right = false;
		if (x_position < 0)
			going_right = true;

		SDL_Delay(delay);
		SDL_SetRenderDrawColor(renderer, 0, 150, 100, 210);

		SDL_RenderDrawRect(renderer, &rectangle);

		SDL_RenderPresent(renderer);

		while (SDL_PollEvent(&event)){
			
			// events
			switch (event.type){
				case SDL_QUIT:
				printf("SDL_QUIT received...\n");
				close = 1;
				break;
			}
		}
		}
	return 0;
}
