#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_render.h>
#include <cstdlib>

// random number generator
int generate_random_number(int min, int max){
	int return_value = rand() % max + 1;
	return return_value;
}

int main(){
	printf("Starting...\n");
	SDL_Window *window = NULL;

	int width = 400;
	int height = 400;
	int square_width = 30;
	int square_height = 30;
	int change_in_position = 5;
	int change_in_y_position = 3;
	int delay = 20;
	// colors
	int square_color[3] = {255, 0, 255};
	int background_color[3] = {0, 0, 0};
	//int* color;

	window = SDL_CreateWindow("MP SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);

	int start_position = 30;

	int close = 0;
	int x_position = start_position;
	int y_position = start_position;
	
	// mouse position	
	int x,y;

	SDL_Rect rectangle;
	SDL_Rect background_rectangle;
		background_rectangle.x = 0;
		background_rectangle.y = 0;
		background_rectangle.w = width;
		background_rectangle.h = height;

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	
	// direction of moving
	bool going_right = true;
	bool going_down = true;
	
	// main loop
	while (!close){
		SDL_Event event;
		
		// renderer
		SDL_RenderClear(renderer);

		// background
		SDL_SetRenderDrawColor(renderer, background_color[0], background_color[1], background_color[2], 0);
		SDL_RenderFillRect(renderer, &background_rectangle);
		
		// rectangle
		rectangle.x = x_position;
		rectangle.y = y_position;
		// if you want to the rectangle following your mouse uncoment those 2 lines	
		// rectangle.x = x - (square_width/2);
		// rectangle.y = y - (square_height/2);

		 rectangle.w = square_width;
		 rectangle.h = square_height;
		
		// drawing rectangle
		SDL_SetRenderDrawColor(renderer, square_color[0], square_color[1], square_color[2], 0);
		SDL_RenderFillRect(renderer, &rectangle);


		// getting mouse position
		Uint32 buttons;
		SDL_PumpEvents();
		buttons = SDL_GetMouseState(&x, &y);

		// drawing lines
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		SDL_RenderDrawLine(renderer, 0, 0, x_position + (square_width/2), y_position + (square_height/2));
		SDL_RenderDrawLine(renderer, width, height, x_position + (square_width/2), y_position + (square_height/2));
		SDL_RenderDrawLine(renderer, 0, width, x_position + (square_width/2), y_position + (square_height/2));
		SDL_RenderDrawLine(renderer, height, 0, x_position + (square_width/2), y_position + (square_height/2));

		SDL_RenderPresent(renderer);


		// changing rectangle position
		if (going_right){
			x_position += change_in_position;
		}
		else{
			x_position -= change_in_position;
		}
		if (going_down){
			y_position += change_in_y_position;
		}
		else{
			y_position -= change_in_y_position;
		}

		// changing direction
		if (x_position >= width - square_width){
			going_right = false;
		}
		if (x_position < 0){
			going_right = true;
		}
		// down and up
		if (y_position >= height - square_height){
			going_down = false;
		}
		if (y_position < 0){
			going_down = true;
		}
		// on every wall hit condition
		if (x_position >= width - square_width ||
			x_position < 0 ||
			y_position >= height - square_height ||
			y_position < 0){
			// changing rectangle color
				square_color[0] = generate_random_number(0, 255);
				square_color[1] = generate_random_number(0, 255);
				square_color[2] = generate_random_number(0, 255);
		}


	
		SDL_Delay(delay);
		while (SDL_PollEvent(&event)){
			
			// events
			switch (event.type){
				case SDL_QUIT:
					printf("SDL_QUIT signal received...\n");
					close = 1;
					break;
				
				// mouse clicking
				case SDL_MOUSEBUTTONDOWN:
					printf("Mouse was clicked!\n");
			}
		}
	}

	return 0;
}
