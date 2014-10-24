#include "ShortcutManager.h"

void ShortcutManager::setMainWindow(QMainWindow *main)
{
	QShortcut *shOpen = createShortcut(main, QKeySequence("Ctrl+O"));
	QObject::connect(shOpen, SIGNAL(activated()), main, SLOT(openFile()));
	
	QShortcut *shNew = createShortcut(main, QKeySequence("Ctrl+N"));
	QObject::connect(shNew, SIGNAL(activated()), main, SLOT(newFile()));

	QShortcut *shDraw = createShortcut(main, QKeySequence("Ctrl+D"));
	QObject::connect(shDraw, SIGNAL(activated()), main, SLOT(setDrawMode()));
		
	QShortcut *shMesh = createShortcut(main, QKeySequence("Ctrl+M"));
	QObject::connect(shMesh, SIGNAL(activated()), main, SLOT(setMeshMode()));

	QShortcut *shResult = createShortcut(main, QKeySequence("Ctrl+R"));
	QObject::connect(shResult, SIGNAL(activated()), main, SLOT(setResultMode()));
}

void ShortcutManager::setWidget(QWidget * widget)
{
	QShortcut *shEscape = createShortcut(widget, QKeySequence("Escape"));
	QObject::connect(shEscape, SIGNAL(activated()), widget, SLOT(escapePressed()));

	QShortcut *shEnter = createShortcut(widget, QKeySequence("CTRL+E"));
	QObject::connect(shEnter, SIGNAL(activated()), widget, SLOT(enterPressed()));
}

QShortcut* ShortcutManager::createShortcut(QWidget *widget, QKeySequence keySeq)
{
	QShortcut *sh = new QShortcut(keySeq, widget);
	sh->setContext(Qt::ApplicationShortcut);

	return sh;
}