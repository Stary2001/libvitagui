#include <gui.h>
#include <debugnet.h>

GUIObject::GUIObject() { pos = screen_pos = size = Vec2(0,0); }

GUIObject::GUIObject(Vec2 pos)
{ this->pos = pos; screen_pos = pos; size = Vec2(0,0); }

GUIObject::GUIObject(Vec2 pos, Vec2 size) : pos(pos), screen_pos(pos), size(size)
{  this->pos = pos; screen_pos = pos; this->size = size;}

GUIObject::~GUIObject() {}

void GUIObject::SetPos(Vec2 p)
{
	pos = p;
}

Vec2 GUIObject::GetPos()
{
	return pos;
}

void GUIObject::SetScreenPos(Vec2 p)
{
	screen_pos = p;
}

Vec2 GUIObject::GetSize()
{
	return size;
}

GUIContainer::GUIContainer()
{}

GUIContainer::GUIContainer(std::vector<GUIObject*> v) : children(v) 
{}

void GUIContainer::Render()
{
	std::vector<GUIObject *>::iterator it = children.begin();
	for(; it != children.end(); it++)
	{
		(*it)->Render();
	}
}

extern "C" void gui_init()
{
	GUILabel::default_font = vita2d_load_font_file("cache0:/VitaDefilerClient/Documents/DejaVuSans.ttf");
}

extern "C" void gui_finish()
{
	vita2d_free_font(GUILabel::default_font);
}

vita2d_font *GUILabel::default_font = NULL;
