#include <sys/time.h>
#include <time.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <stdio.h>
#include <string>

const int SCREEN_WIDTH = 1350; //Screen dimension constants
const int SCREEN_HEIGHT = 700;

enum KeyPressSurfaces { //Key press surfaces constants
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
	};

bool init(); //Starts up SDL and creates window
bool loadMedia(); //Loads media
void close(); //Frees media and shuts down SDL

SDL_Surface* gPNGSurface2 = NULL; //Current displayed PNG image
SDL_Surface* gPNGSurface = NULL;
SDL_Surface* gPNGSurface3 = NULL;
SDL_Surface* gPNGSurface4 = NULL;
SDL_Surface* loadSurface( std::string path ); //Loads individual image
SDL_Window* gWindow = NULL; //The window we'll be rendering to
SDL_Surface* gScreenSurface = NULL; //The surface contained by the window
SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ][8]; //The images that correspond to a keypress
SDL_Surface* gCurrentSurface = NULL; //Current displayed image

typedef struct {
	SDL_Surface *tiempos[3];
	} _estado;
_estado estados[4];

bool init() {
	bool success = true; //Initialization flag
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) { //Initialize SDL
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
		}
	else {
		gWindow = SDL_CreateWindow( "Caricature Generation Tool", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN ); //Create window
		if( gWindow == NULL ) {
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
			}
		else {
			int imgFlags = IMG_INIT_PNG; //Initialize PNG loading
			if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
				printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
				success = true;
				}
			else {
				gScreenSurface = SDL_GetWindowSurface( gWindow ); //Get window surface
				}
			}
		}
	return success;
	}
bool loadMedia() {
	bool success = true; //Loading success flag
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ][0] = loadSurface( "Resources/black.png" ); //Load default surface
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ] == NULL ) {
		printf( "Failed to load default image!\n" );
		success = false;
		}
gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ][0] = loadSurface( "Resources/U.png" ); //Load up surface
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] == NULL ) {
		printf( "Failed to load up image!\n" );
		success = false;
		}
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ][1] = loadSurface( "Resources/U1.png" ); //Load up surface
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] == NULL ) {
		printf( "Failed to load up image!\n" );
		success = false;
		}
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ][2] = loadSurface( "Resources/U2.png" ); //Load up surface
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] == NULL ) {
		printf( "Failed to load up image!\n" );
		success = false;
		}
gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ][0] = loadSurface( "Resources/DOW.png" ); //Load down surface
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] == NULL ) {
		printf( "Failed to load down image!\n" );
		success = false;
		}
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ][1] = loadSurface( "Resources/DOW1.png" ); //Load down surface
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] == NULL ) {
		printf( "Failed to load down image!\n" );
		success = false;
		}
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ][2] = loadSurface( "Resources/DOW2.png" ); //Load down surface
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] == NULL ) {
		printf( "Failed to load down image!\n" );
		success = false;
		}
gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ][0] = loadSurface( "Resources/LEF.png" ); //Load left surface
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL ) {
		printf( "Failed to load left image!\n" );
		success = false;
		}
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ][1] = loadSurface( "Resources/LEF1.png" ); //Load left surface
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL ) {
		printf( "Failed to load left image!\n" );
		success = false;
		}
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ][2] = loadSurface( "Resources/LEF2.png" ); //Load left surface
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL ) {
		printf( "Failed to load left image!\n" );
		success = false;
		}
gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ][0] = loadSurface( "Resources/RIGH.png" ); //Load right surface
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL ) {
		printf( "Failed to load right image!\n" );
		success = false;
		}
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ][1] = loadSurface( "Resources/RIGH1.png" ); //Load right surface
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL ) {
		printf( "Failed to load right image!\n" );
		success = false;
		}
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ][2] = loadSurface( "Resources/RIGH2.png" ); //Load right surface
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL ) {
		printf( "Failed to load right image!\n" );
		success = false;
		}
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ][3] = loadSurface( "Resources/U3.png" ); //Load right surface
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] == NULL ) {
		printf( "Failed to load right image!\n" );
		success = false;
		}
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ][4] = loadSurface( "Resources/U4.png" ); //Load right surface
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] == NULL ) {
		printf( "Failed to load right image!\n" );
		success = false;
		}
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ][5] = loadSurface( "Resources/U5.png" ); //Load right surface
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ] == NULL ) {
		printf( "Failed to load right image!\n" );
		success = false;
		}
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ][3] = loadSurface( "Resources/DOW3.png" ); //Load right surface
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] == NULL ) {
		printf( "Failed to load right image!\n" );
		success = false;
		}
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ][4] = loadSurface( "Resources/DOW4.png" ); //Load right surface
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] == NULL ) {
		printf( "Failed to load right image!\n" );
		success = false;
		}
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ][5] = loadSurface( "Resources/DOW5.png" ); //Load right surface
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ] == NULL ) {
		printf( "Failed to load right image!\n" );
		success = false;
		}
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ][3] = loadSurface( "Resources/LEF3.png" ); //Load right surface
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL ) {
		printf( "Failed to load right image!\n" );
		success = false;
		}
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ][4] = loadSurface( "Resources/LEF4.png" ); //Load right surface
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL ) {
		printf( "Failed to load right image!\n" );
		success = false;
		}
	gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ][5] = loadSurface( "Resources/LEF5.png" ); //Load right surface
	if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ] == NULL ) {
		printf( "Failed to load right image!\n" );
		success = false;
		}
	
  gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ][3] = loadSurface( "Resources/RIGH3.png" ); //Load right surface
  if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL ) {
		printf( "Failed to load right image!\n" );
		success = false;
		}
        gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ][4] = loadSurface( "Resources/RIGH4.png" ); //Load right surface
        if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL ) {
		printf( "Failed to load right image!\n" );
		success = false;
		}
        gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ][5] = loadSurface( "Resources/RIGH5.png" ); //Load right surface
        if( gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ] == NULL ) {
		printf( "Failed to load right image!\n" );
		success = false;
		}

	return success;
	}
void close() {
	for( int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i ) {//Deallocate surfaces
		for (int y=0;y<3;y++) {
			SDL_FreeSurface( gKeyPressSurfaces[ i ][y] );
			gKeyPressSurfaces[ i ][y] = NULL;
			}
		}
	SDL_DestroyWindow( gWindow ); //Destroy window
	gWindow = NULL;
	IMG_Quit(); //Quit SDL subsystems
	SDL_Quit();
	}
SDL_Surface* loadSurface( std::string path ) {
	SDL_Surface* optimizedSurface = NULL; //The final optimized image
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() ); //Load image at specified path
	if( loadedSurface == NULL ) {
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
		}
	else {
		optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0); //Convert surface to screen format
		if( optimizedSurface == NULL ) {
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
			}
		SDL_FreeSurface( loadedSurface ); //Get rid of old loaded surface
		}
	return optimizedSurface;
	}
int main( int argc, char* args[] ) {
        int tiempo=0,memoria=0,lol=0,ataque=0;
	struct timeval tv_base,tv_actual;
	
	if( !init() ) { //Start up SDL and create window
		printf( "Failed to initialize!\n" );
		}
	else {
		if( !loadMedia() ) { //Load media
			printf( "Failed to load media!\n" );
			}
		else {
			bool quit = false; //Main loop flag
			SDL_Event e; //Event handler
			SDL_Rect srcrect; //While application is running
			srcrect.x = 0;
			srcrect.y = 20;
			srcrect.w = 100;
			srcrect.h = 200;
			if (gCurrentSurface==NULL) {
				gCurrentSurface=gCurrentSurface;
				gettimeofday(&tv_base,NULL);
				tv_base.tv_usec+=100000;
				if (tv_base.tv_usec>=1000000) {
					tv_base.tv_sec++;
					tv_base.tv_usec-=1000000;
					}
				}
			while( !quit ) {
				while( SDL_PollEvent( &e ) != 0 ) { //Handle events on queue
					SDL_BlitSurface( gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ][0], NULL, gScreenSurface,&srcrect); //User requests quit
					if( e.type == SDL_QUIT ) {
						quit = true;
						}
					else if( e.type == SDL_KEYDOWN ) {
						switch( e.key.keysym.sym ) { //Select surfaces based on key press
							case SDLK_UP:
								memoria=KEY_PRESS_SURFACE_UP;
								gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ][tiempo];
								srcrect.y=srcrect.y-100;
								break;
							case SDLK_DOWN:
								memoria=KEY_PRESS_SURFACE_DOWN;
								gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ][tiempo];
								srcrect.y=srcrect.y+100;
								break;
							case SDLK_LEFT:
								memoria=KEY_PRESS_SURFACE_LEFT;
								gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ][tiempo];
								srcrect.x=srcrect.x-100;
								break;
							case SDLK_RIGHT:
								memoria=KEY_PRESS_SURFACE_RIGHT;
								gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ][tiempo];
								srcrect.x=srcrect.x+100;
								break;
							case SDLK_p:
								ataque=1;
                                break;
                            case SDLK_ESCAPE:
                                close();
                                return 0;
                      if(memoria==KEY_PRESS_SURFACE_UP){
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ][lol];
                            }
                      if(memoria==KEY_PRESS_SURFACE_DOWN){
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ][lol];
                            }
                      if(memoria==KEY_PRESS_SURFACE_LEFT){
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ][lol];
                      if(memoria==KEY_PRESS_SURFACE_RIGHT){
                            gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ][lol];
                            }
                      break;
                      default:
                            gCurrentSurface = gKeyPressSurfaces[ memoria ][lol];
                            break;
							}
						}
					}
				gettimeofday(&tv_actual,NULL);
				if ((tv_actual.tv_sec>tv_base.tv_sec+1)||(tv_actual.tv_sec==tv_base.tv_sec&&tv_actual.tv_usec>tv_base.tv_usec)) {
					//printf("cambio de tiempo\n");
					gettimeofday(&tv_base,NULL);
					tiempo++;
					if (tiempo>2)
						tiempo=0;
					tv_base.tv_usec+=100000;
					if (tv_base.tv_usec>=1000000) {
						tv_base.tv_sec++;
						tv_base.tv_usec-=1000000;
						}
                    if (ataque==1&&lol<6){
                    if(lol>0){
                    gCurrentSurface = gKeyPressSurfaces[ memoria ][tiempo+lol];
                    lol++;
                    }
                    else {
                    if(tiempo==0)
                    lol=lol+3;
                    else if(tiempo==1)
                    lol=lol+2;
                    else if(tiempo==2)
                    lol=lol++;
                    }
                    }
                    else{
                    gCurrentSurface = gKeyPressSurfaces[ memoria ][tiempo];
                    lol=0;
                    ataque=0;
                    }
                }
				SDL_BlitSurface( gCurrentSurface, NULL, gScreenSurface,&srcrect); //Apply the PNG image
				SDL_UpdateWindowSurface( gWindow );
				}
			}
		}
	close(); //Free resources and close SDL
	return 0;
	}
