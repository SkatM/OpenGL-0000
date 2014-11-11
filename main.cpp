/**********************************************************************
	link flags: -lmingw32 -lSDLmain -lSDL -lopengl32 -lglu32
 **********************************************************************/

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

#define TIME_PER_FRAME 16

int main(int argc, char* args[]) {

	// variables
	SDL_Surface * screen;
	SDL_Event e;
	int timer;
	bool quit = false;

	// initialization
	if (-1 == SDL_Init(SDL_INIT_VIDEO)) return -1;
	screen = SDL_SetVideoMode(512, 256, 32, SDL_OPENGL);
	if (!screen) return -1;

	// OpenGL config
	glEnable(GL_DOUBLEBUFFER);
	glClearColor(0.25f, 0.35f, 0.5f, 0.0f);
	glViewport(0, 0, 512, 256);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluPerspective(35.0, ((float)512 / (float)256), 1.0, 512.0);
	glTranslatef(0.0f, -1.0f, -16.0f);
	glColor3f(0.6f, 1.0f, 0.0f);
	glEnable(GL_CULL_FACE);

	// main loop
	while (!quit) {
		timer = SDL_GetTicks();
		while (SDL_PollEvent(&e)) if (SDL_QUIT == e.type) quit = true;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glBegin(GL_TRIANGLES);
			glVertex3f(1.0f, 4.0f, 0.0f);
			glVertex3f(-3.0f, 0.0f, 0.0f);
			glVertex3f(3.0f, -2.0f, 0.0f);
		glEnd();
		SDL_GL_SwapBuffers();
		timer = TIME_PER_FRAME -(SDL_GetTicks() - timer);
		if (timer > 0) SDL_Delay(timer);
	}

	// quitting
	SDL_Quit();
	return 0;
}
