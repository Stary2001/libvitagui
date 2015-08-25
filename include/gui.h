#pragma once
#include <stdint.h>
#include <vita2d.h>

#ifndef __cplusplus
  #include <gui/gui_c.h>
#else

#include <vector>

typedef uint32_t Color;

class Vec2
{
public:
	Vec2();
	Vec2(int x, int y);
	Vec2& operator+=(const Vec2 &other);
	const Vec2 operator+(const Vec2 &other);
	int x;
	int y;
};

class GUIObject
{
public:
	GUIObject();
	GUIObject(Vec2 pos);
	GUIObject(Vec2 pos, Vec2 size);
	virtual ~GUIObject(); // allows deleting a GUIObject*
	virtual void Render() = 0;
	virtual void Layout() = 0;
	void SetPos(Vec2 p);
	Vec2 GetPos();
	void SetScreenPos(Vec2 p);
	Vec2 GetSize();
protected:
	Vec2 pos;
	Vec2 screen_pos;
	Vec2 size;
};

class GUIContainer
{
public:
	GUIContainer();
	GUIContainer(std::vector<GUIObject*> v);
	void AddChild(GUIObject *o);
        void RemoveChild(GUIObject *o);
	virtual void Render();
protected:
	std::vector<GUIObject*> children;
};

class GUILabel : public virtual GUIObject
{
friend class GUIMenu;
public:
        GUILabel(vita2d_font* font, const char *text, Vec2 pos);
        virtual void Render();
	virtual void Layout();
	static vita2d_font *default_font;
private:
	vita2d_font *font;
        const char *text;
        uint32_t font_size;
	Color color;
};

class GUIPane : public virtual GUIObject, public virtual GUIContainer
{
public:
	GUIPane(Color color, Vec2 pos, Vec2 size);
	virtual ~GUIPane();
	virtual void Render();
	virtual void Layout();
private:
	Color color;
};

class GUIList : public GUIPane, public virtual GUIContainer
{
public:
	GUIList(std::vector<GUIObject*> items, Vec2 pos, Vec2 size);
	virtual void Render();
	virtual void Layout();
	void Scroll(int o);
private:
	std::vector<GUIObject*> render_list;
	int offset;
	int max_offset;
};

class GUIMenu : public GUIObject, public GUIContainer
{
public:
	GUIMenu(const char *name, std::vector<GUIObject*> items, Vec2 pos, Vec2 size);
	~GUIMenu();
        virtual void Render();
	virtual void Layout();
private:
	GUIPane *pane;
	GUILabel label;
};
#endif

extern "C" void gui_init();
extern "C" void gui_finish();
