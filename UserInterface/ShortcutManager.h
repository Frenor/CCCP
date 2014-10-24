#pragma once

#include <qshortcut.h>
#include <qobject.h>
#include "mainwindow.h"

//!	Container for all keyboard shortcuts supported by the application.
class ShortcutManager
{
public:
	ShortcutManager::ShortcutManager(){}
	/*!
		Sets shortcuts that connects to the main window.
	*/
	static void setMainWindow(QMainWindow *);
	/*!
		Sets shortcuts that connects directly to the GraphicsView
	*/
	static void setWidget(QWidget *);

private:
	/*!
		Creates a keyboard shortcut with the given key sequence, on the given widget
	*/
	static QShortcut* createShortcut(QWidget*, QKeySequence);
};