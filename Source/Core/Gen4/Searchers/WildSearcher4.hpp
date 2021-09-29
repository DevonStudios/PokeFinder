/*
 * This file is part of PokéFinder
 * Copyright (C) 2017-2021 by Admiral_Fish, bumba, and EzPzStreamz
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

#ifndef WILDSEARCHER4_HPP
#define WILDSEARCHER4_HPP

#include <Core/Gen4/EncounterArea4.hpp>
#include <Core/Parents/Searchers/WildSearcher.hpp>
#include <Core/Gen4/States/WildState4.hpp>
#include <Core/RNG/RNGCache.hpp>
#include <mutex>

class WildSearcher4 : public WildSearcher
{
public:
    WildSearcher4() = default;
    WildSearcher4(u16 tid, u16 sid, u8 genderRatio, Method method, const StateFilter &filter);
    void setEncounterArea(const EncounterArea4 &encounterArea);
    void setDelay(u32 minDelay, u32 maxDelay);
    void setState(u32 minAdvance, u32 maxAdvance);
    void startSearch(const std::array<u8, 6> &min, const std::array<u8, 6> &max);
    void cancelSearch();
    std::vector<WildState4> getResults();
    int getProgress() const;

private:
    RNGCache cache;
    EncounterArea4 encounterArea;
    u32 minDelay;
    u32 maxDelay;
    u32 minAdvance;
    u32 maxAdvance;
    u8 thresh, suctionCupThresh;
    u16 rock;

    bool searching;
    int progress;
    std::vector<WildState4> results;
    std::mutex mutex;

    std::vector<WildState4> search(u8 hp, u8 atk, u8 def, u8 spa, u8 spd, u8 spe) const;
    std::vector<WildState4> searchMethodJ(u8 hp, u8 atk, u8 def, u8 spa, u8 spd, u8 spe) const;
    std::vector<WildState4> searchMethodK(u8 hp, u8 atk, u8 def, u8 spa, u8 spd, u8 spe) const;
    std::vector<WildState4> searchChainedShiny(u8 hp, u8 atk, u8 def, u8 spa, u8 spd, u8 spe) const;
    std::vector<WildState4> searchInitialSeeds(const std::vector<WildState4> &results) const;

    std::vector<WildState4> normalMethodJ(WildState4 state, u32 seed) const;
    std::vector<WildState4> synchMethodJ(WildState4 state, u32 seed) const;
    std::vector<WildState4> cuteCharmMethodJ(WildState4 state, u32 seed) const;
    bool encounterMethodJ(WildState4 &state, u32 seed) const;
    std::vector<WildState4> normalMethodK(WildState4 state, u32 seed) const;
    std::vector<WildState4> synchMethodK(WildState4 state, u32 seed) const;
    std::vector<WildState4> cuteCharmMethodK(WildState4 state, u32 seed) const;
    bool encounterMethodK(WildState4 &state, u32 seed) const;
};

#endif // WILDSEARCHER4_HPP
