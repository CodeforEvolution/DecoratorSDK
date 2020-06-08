/*
 * Copyright 2010-2015, Haiku, Inc.
 * Distributed under the terms of the MIT License.
 *
 * Authors:
 *		Clemens Zeidler <haiku@clemens-zeidler.de>
 */
#ifndef SAT_DECORATOR_H
#define SAT_DECORATOR_H


#include "DecorManager.h"
#include "DefaultDecorator.h"
#include "DefaultWindowBehaviour.h"
#include "StackAndTile.h"


class Desktop;


class SATDecorator : public DefaultDecorator {
public:
			enum {
				HIGHLIGHT_STACK_AND_TILE = HIGHLIGHT_USER_DEFINED
			};

public:
								SATDecorator(DesktopSettings& settings,
									BRect frame, Desktop* desktop);

protected:
	virtual	void				UpdateColors(DesktopSettings& settings);
	virtual	void				GetComponentColors(Component component,
									uint8 highlight, ComponentColors _colors,
									Decorator::Tab* tab = NULL);

private:
				rgb_color		fHighlightTabColor;
				rgb_color		fHighlightTabColorLight;
				rgb_color		fHighlightTabColorBevel;
				rgb_color		fHighlightTabColorShadow;
};


class SATWindowBehaviour : public DefaultWindowBehaviour {
public:
								SATWindowBehaviour(Window* window,
									StackAndTile* sat);

protected:
	virtual bool				AlterDeltaForSnap(Window* window, BPoint& delta,
									bigtime_t now);

private:
			StackAndTile*		fStackAndTile;
};


#endif
