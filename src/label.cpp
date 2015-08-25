#include <gui.h>
#include <gui/color.h>

#include <debugnet.h>

// todo: theming

GUILabel::GUILabel(vita2d_font* f, const char *text, Vec2 pos) : GUIObject(pos), text(text), font_size(20), color(COLOR_BLACK)
{
	if(f != NULL)
	{
		font = f;
	}
	else
	{
		font = default_font;
	}
	size.x = vita2d_font_text_width(font, font_size, text);
	size.y = vita2d_font_text_height(font, font_size, text);
}

void GUILabel::Render()
{
//	debugNetPrintf(DEBUG, "rendering label %i %i %i %s\n", screen_pos.x, screen_pos.y, font_size, text);
	vita2d_font_draw_text(font, screen_pos.x, screen_pos.y, color, font_size, text);
}

void GUILabel::Layout() {}
