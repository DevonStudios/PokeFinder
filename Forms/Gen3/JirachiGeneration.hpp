/*
 * This file is part of PokéFinder
 * Copyright (C) 2017 by Admiral_Fish, bumba, and EzPzStreamz
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef JIRACHIGENERATION_HPP
#define JIRACHIGENERATION_HPP

#include <QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QString>
#include <QChar>
#include <PokeFinderCore/RNG/LCRNG.hpp>

typedef uint32_t u32;

namespace Ui
{
    class JirachiGeneration;
}

class JirachiGeneration : public QMainWindow
{
    Q_OBJECT

protected:
    void changeEvent(QEvent *);

private:
    Ui::JirachiGeneration *ui;
    QStandardItemModel *model = new QStandardItemModel(this);

    void setupModels();
    void genListOut(u32 seed);
    QString calcProbable(u32 seed);

private slots:
    void on_pushButtonGenerate_clicked();

public:
    explicit JirachiGeneration(QWidget *parent = 0);
    ~JirachiGeneration();

    QString flip(QString text);

};

#endif // JIRACHIGENERATION_HPP
