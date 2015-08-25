#include <gui.h>
#include <gui/color.h>

// todo: theming!

GUIMenu::GUIMenu(const char *name, std::vector<GUIObject*> v, Vec2 pos, Vec2 size) : GUIObject(pos, size), GUIContainer(v), label(NULL, name, pos)
{
	pane = new GUIPane(COLOR_WHITE, pos, size); 
	Vec2 label_pos = pos;
	label_pos.x = pos.x + size.x / 2 - vita2d_font_text_width(label.font, 20, name) / 2;
	label.SetPos(label_pos);
}

GUIMenu::~GUIMenu()
{
	delete pane;
}

void GUIMenu::Render()
{
	pane->Render();
	label.Render();
	GUIContainer::Render();
}
