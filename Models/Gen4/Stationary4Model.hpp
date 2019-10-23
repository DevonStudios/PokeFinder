/*
 * This file is part of PokéFinder
 * Copyright (C) 2017-2019 by Admiral_Fish, bumba, and EzPzStreamz
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

#ifndef STATIONARY4MODEL_HPP
#define STATIONARY4MODEL_HPP

#include <Models/TableModel.hpp>

namespace PokeFinderCore
{
    class Frame4;
    enum Method;
}

namespace PokeFinderModels
{
    class Stationary4Model : public TableModel<PokeFinderCore::Frame4>
    {
        Q_OBJECT
    public:
        Stationary4Model(QObject *parent, PokeFinderCore::Method method);
        void setMethod(PokeFinderCore::Method method);
        int columnCount(const QModelIndex &parent = QModelIndex()) const override;
        QVariant data(const QModelIndex &index, int role) const override;
        QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    private:
        PokeFinderCore::Method method;

        QStringList header1 =
        {
            tr("Frame"), tr("Call"), tr("Chatot"), tr("PID"), "!!!", tr("Nature"), tr("Ability"), tr("HP"),
            tr("Atk"), tr("Def"), tr("SpA"), tr("SpD"), tr("Spe"), tr("Hidden"), tr("Power"), tr("Gender")
        };
        QStringList header2 =
        {
            tr("Frame"), tr("Chatot"), tr("PID"), "!!!", tr("Nature"), tr("Ability"), tr("HP"),
            tr("Atk"), tr("Def"), tr("SpA"), tr("SpD"), tr("Spe"), tr("Hidden"), tr("Power"), tr("Gender")
        };
        QStringList header3 =
        {
            tr("Frame"), tr("Call"), tr("Chatot"), tr("PID"), "!!!", tr("Nature"), tr("Ability"),
            tr("HP"), tr("Atk"), tr("Def"), tr("SpA"), tr("SpD"), tr("Spe"), tr("Hidden"), tr("Power"), tr("Gender")
        };
        QStringList header4 =
        {
            tr("Frame"), tr("Call"), tr("Chatot"), tr("HP"), tr("Atk"), tr("Def"), tr("SpA"), tr("SpD"), tr("Spe"), tr("Hidden"), tr("Power")
        };
    };
}

#endif // STATIONARY4MODEL_HPP
