#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Graph_lib::Window {
Lines_window(Point xy, int w, int h, const string& title);

// data:
Open_polyline lines;
// widgets:
//Buttons
    
    Menu color_menu;   //létrehozzuk a szín választó menü gombját
    Button menu_button;
    Menu menu_styles;
    Button button_styles;


// add (next_x,next_y) to lines
// end program
void change(Color c) { lines.set_color(c); }//ennek a függvénynek a segítségével tudunk majd színt válatoztatni ha meghívjuk pl pár sorral lentebb
void hide_menu() { color_menu.hide(); menu_button.show(); }
void hide_style_menu(){menu_styles.hide();button_styles.show();}
// actions invoked by callbacks:
    void red_pressed() { change(Color::red); redraw(); }  // amennyiben megnyomják a gombot újra rajzolja a vonalat az adott színnel
    void blue_pressed() { change(Color::blue); redraw(); }
    void black_pressed() { change(Color::black); redraw(); }
void menu_pressed() { menu_button.hide(); color_menu.show(); }

void change_style(Line_style ls){lines.set_style(ls); hide_style_menu(); redraw();}
void style_menu_pressed(){button_styles.hide();menu_styles.show();}


// callback functions:
static void cb_red(Address, Address);
static void cb_blue(Address, Address);
static void cb_black(Address, Address);
static void cb_menu(Address, Address);

static void cb_button_styles(Address,Address);

bool wait_for_button();


private:
    Button next_button;
    Button quit_button;


    In_box next_x;
    In_box next_y;

    Out_box xy_out;

    void next();
    void quit();

};

