/*

  Copyright (c) 2015, 2016 Hubert Denkmair <hubert@denkmair.de>

  This file is part of cangaroo.

  cangaroo is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  cangaroo is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with cangaroo.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <MdiWindow.h>
#include <Backend.h>

namespace Ui {
class LogWindow;
}

class QDomDocument;
class QDomElement;

class LogWindow : public MdiWindow
{
    Q_OBJECT

public:
    explicit LogWindow(QWidget *parent, Backend &backend);
    ~LogWindow();

    virtual bool saveXML(Backend &backend, QDomDocument &xml, QDomElement &root);
    virtual bool loadXML(Backend &backend, QDomElement &el);

public slots:
    void onLogMessage(const QDateTime dt, const log_level_t level, const QString msg);

private:
    Ui::LogWindow *ui;
};

#endif // LOGWINDOW_H
