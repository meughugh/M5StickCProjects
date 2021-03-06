#ifndef _RTC_H
#define _RTC_H

#include "src/RTCLib/RTClib.h"

PCF8563 rtc;

DateTime now;

// adjust 1970 -> 2078
// adjust 1980 -> 2088
// adjust 1990 -> 2098
// adjust 1991 -> 2099
// adjust 1992 -> 2000 年整
// adjust 1993 -> 2001
// adjust 1999 -> 2007
// adjust 2078 -> 2078
// adjust 2100 -> 2000 年整
void init_rtc() {
  rtc.begin();
  DateTime now = rtc.now();
  // following line sets the RTC to the date & time this sketch was compiled
  DateTime compileTime = DateTime(__DATE__, __TIME__);
  Serial.print("compile time in this firmware: ");
  Serial.print(__DATE__);
  Serial.print(" ");
  Serial.println(__TIME__);
  Serial.print("now.unixtime() = ");
  Serial.println(now.unixtime());
  Serial.print("compileTime.unixtime() = ");
  Serial.println(compileTime.unixtime());
  if (now.unixtime() < compileTime.unixtime()) {
    Serial.println("now < compileTime, RTC need factory reset!");
    rtc.adjust(compileTime);
  } else {
    Serial.println("now >= compileTime, RTC already ok, ignore time adjustment.");
  }
}

#endif // _RTC_H
