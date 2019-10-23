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

#ifndef PROFILE4_HPP
#define PROFILE4_HPP

#include <Core/Parents/Profile.hpp>

class QJsonObject;

namespace PokeFinderCore
{
    class Profile4 : public Profile
    {
    public:
        Profile4();
        Profile4(const QString &profileName, Game version, u16 tid, u16 sid, Game dual = Game::Blank,
                 int radio = 0, Language language = Language::English, bool radar = false, bool swarm = false);
        Profile4(QJsonObject data);
        QString getDualSlotString() const;
        Game getDualSlot() const;
        QString getRadioString() const;
        int getRadio() const;
        bool getRadar() const;
        bool getSwarm() const;
        QJsonObject getJson() const;
        static QVector<Profile4> loadProfileList();
        void saveProfile() const;
        void deleteProfile() const;
        void updateProfile(const Profile4 &original) const;
        friend bool operator==(const Profile4 &left, const Profile4 &right);
        friend bool operator!=(const Profile4 &left, const Profile4 &right);

    private:
        Game dual;
        int radio;
        bool radar;
        bool swarm;
    };

    bool operator==(const Profile4 &left, const Profile4 &right);
    bool operator!=(const Profile4 &left, const Profile4 &right);
}

#endif // PROFILE4_HPP
