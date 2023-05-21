#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <cstdlib>

// random number generator
int generate_random_number(int min, int max){
	int return_value = rand() % max + 1;
	return return_value;
}

// generating 3 element array of color rbg values
int * get_new_color(){
	int new_color[3] = {1,2,3};
	return new int[3] {new_color[0], new_color[1], new_color[2]};
}

int main(){
	printf("Hello world\n");
	SDL_Window *window = NULL;
	int width = 400;
	int height = 400;
	int square_width = 30;
	int square_height = 30;
	int change_in_position = 5;
	int change_in_y_position = 3;
	int delay = 20;
	int color[3] = {255, 0, 255};
	//int* color;

	window = SDL_CreateWindow("MP SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
	//SDL_Delay(3000);
	//SDL_DestroyWindow(window);
	//SDL_Quit();
	int start_position = 30;

	int close = 0;
	int x_position = start_position;
	int y_position = start_position;
	
	SDL_Rect rectangle;

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	
	// direction of moving
	bool going_right = true;
	bool going_down = true;
	
	// main loop
	while (!close){
		SDL_Event event;
		

		// renderer

		//SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_SetRenderDrawColor(renderer, 0, color[0], color[1], color[2]);
		SDL_RenderClear(renderer);
		
		// trying to draw a rectangle
		//SDL_Rect rectangle ={100,100,30,30};

		 rectangle.x = x_position;
		 rectangle.y = y_position;
		 rectangle.w = square_width;
		 rectangle.h = square_height;
		
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
		if (x_position >= width - square_width ||
				x_position < 0 ||
				y_position >= height - square_height ||
				y_position < 0){
			color[0] = generate_random_number(0, 255);
			color[1] = generate_random_number(0, 255);
			color[2] = generate_random_number(0, 255);
		}

		SDL_Delay(delay);
		SDL_SetRenderDrawColor(renderer, 0, 150, 100, 210);
		//SDL_SetRenderDrawColor(renderer, 0, color[0], color[1], color[2]);

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
