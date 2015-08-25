#include <gui.h>
#include <gui/color.h>
#include <debugnet.h>

// todo: theming

GUIList::GUIList(std::vector<GUIObject*> items, Vec2 pos, Vec2 size) : GUIObject(pos, size), GUIContainer(items), GUIPane(COLOR_WHITE, pos, size), offset(0)
{}

void GUIList::Render()
{
	GUIPane::Render();
	for(GUIObject *o : render_list)
	{
		o->Render();
	}
}

void GUIList::Layout()
{
	int total_y = 0;
	render_list.clear();

	for(GUIObject *o : children)
	{
		if((total_y - offset) < size.y && total_y + o->GetSize().y >= offset)
		{
                	render_list.push_back(o);
		}

		Vec2 p = o->GetPos();
		p.y = total_y;
		total_y += o->GetSize().y;
		o->SetPos(p);
	}

	max_offset = total_y - size.y;
	

	for(GUIObject *o : render_list)
	{
		o->SetScreenPos(o->GetPos() + Vec2(pos.x, pos.y - offset));
	}
}

void GUIList::Scroll(int o)
{
	o += offset;
	if(o > 0)
	{
		if(o > max_offset) { o = max_offset; }
	}
	else { o = 0; }

	offset = o;
	Layout();	
}
