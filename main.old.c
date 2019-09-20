
#include "lib/graphics.h"
#include "display/display.h"

#define type_name(expr) \
    (_Generic((expr), \
              char: "char", unsigned char: "unsigned char", signed char: "signed char", \
              short: "short", unsigned short: "unsigned short", \
              int: "int", unsigned int: "unsigned int", \
              long: "long", unsigned long: "unsigned long", \
              long long: "long long", unsigned long long: "unsigned long long", \
              float: "float", \
              double: "double", \
              long double: "long double", \
              void*: "void*", \
              default: "?"))

void splash_screen();

int main() {

	init_graphics(700, 700); /* (largeur, hauteur) */


	splash_screen();

	affiche_auto_off();
	draw_board();

	affiche_all(); //render
	wait_clic();
	return(0);
}
