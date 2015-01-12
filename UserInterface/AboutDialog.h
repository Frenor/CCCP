#pragma once
#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include "ui_aboutDialog.h"

//! Controller for the about dialog box used to show the history and information about this program. 
/*!
	For now all information is hard coded into the .ui-file, creating this controller for future expansion
*/
class AboutDialog : public QDialog
{
public:
	AboutDialog(QDialog *parent = 0);

private:
	Ui::AboutDialog ui;
};

#endif //ABOUTDIALOG_H