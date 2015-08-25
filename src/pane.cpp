#include <gui.h>
#include <debugnet.h>


GUIPane::GUIPane(Color color, Vec2 pos, Vec2 size) : GUIObject(pos, size), color(color)
{
	debugNetPrintf(DEBUG, "aa %i %i\n", size.x, size.y);
}

GUIPane::~GUIPane() {}

void GUIPane::Render()
{
	vita2d_draw_rectangle(screen_pos.x, screen_pos.y, size.x, size.y, color);
}

void GUIPane::Layout() {}
