#include "DateTime.hpp"

constexpr int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(int year, int month, int day)
{
    int a = month < 3 ? 1 : 0;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    jd = day + ((153 * m + 2) / 5) - 32045 + 365 * y + (y / 4) - (y / 100) + (y / 400);
}

Date Date::addDays(int days)
{
    return Date(jd + days);
}

int Date::daysTo(const Date &other) const
{
    return other.jd - jd;
}

int Date::year() const
{
    return getParts()[0];
}

int Date::month() const
{
    return getParts()[1];
}

int Date::day() const
{
    return getParts()[2];
}

int Date::dayOfWeek() const
{
    return jd % 7;
}

std::array<int, 3> Date::getParts() const
{
    int a = jd + 32044;
    int b = (4 * a + 3) / 146097;
    int c = a - (146097 * b) / 4;

    int d = (4 * c + 3) / 1461;
    int e = c - (1461 * d) / 4;
    int m = (5 * e + 2) / 153;

    int y = 100 * b + d - 4800 + (m / 10);

    int year = y > 0 ? y : y - 1;
    int month = m + 3 - 12 * (m / 10);
    int day = e - ((153 * m + 2) / 5) + 1;

    return { year, month, day };
}

int Date::daysInMonth(int month, int year)
{
    if (month == 2 && isLeapYear(year))
    {
        return 29;
    }
    return monthDays[month];
}

bool Date::isLeapYear(int year)
{
    // Since we know the years are bound between 2000 and 2099, we can simplify this check
    // return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    return (year % 4) == 0;
}

int Date::weekDay() const
{
    return jd % 7;
}

std::string Date::toString() const
{
    auto parts = getParts();

    std::string y = std::to_string(parts[0]);

    std::string m = std::to_string(parts[1]);
    m.insert(m.begin(), 2 - m.size(), '0');

    std::string d = std::to_string(parts[2]);
    d.insert(d.begin(), 2 - d.size(), '0');

    return m + "/" + d + "/" + y;
}

bool Time::addSeconds(int seconds)
{
    md += seconds;
    if (md >= 86400)
    {
        md -= 86400;
        return true;
    }
    return false;
}

int Time::hour() const
{
    return md / 3600;
}

int Time::minute() const
{
    return (md % 3600) / 60;
}

int Time::second() const
{
    return md % 60;
}

std::string Time::toString() const
{
    std::string h = std::to_string(hour());
    h.insert(h.begin(), 2 - h.size(), '0');

    std::string m = std::to_string(minute());
    m.insert(m.begin(), 2 - m.size(), '0');

    std::string s = std::to_string(second());
    s.insert(s.begin(), 2 - s.size(), '0');

    return h + ":" + m + ":" + s;
}

DateTime::DateTime(int year, int month, int day, int hour, int minute, int second) :
    date(Date(year, month, day)), time(Time(hour, minute, second))
{
}

void DateTime::addSeconds(int seconds)
{
    if (time.addSeconds(seconds))
    {
        date.addDays(1);
    }
}

DateTime DateTime::addSecs(int seconds)
{
    DateTime dt(*this);
    dt.addSeconds(seconds);
    return dt;
}

Date DateTime::getDate() const
{
    return date;
}

Time DateTime::getTime() const
{
    return time;
}

std::string DateTime::toString() const
{
    return date.toString() + " " + time.toString();
}
