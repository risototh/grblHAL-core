/*
  pin_bits_masks.h - for adding bit definitions and masks

  NOTE: This file is not used by the core, it may be used by drivers

  Part of grblHAL

  Copyright (c) 2021 Terje Io

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifdef CONTROL_PORT
#ifndef RESET_PORT
#define RESET_PORT CONTROL_PORT
#endif
#ifndef FEED_HOLD_PORT
#define FEED_HOLD_PORT CONTROL_PORT
#endif
#ifndef CYCLE_START_PORT
#define CYCLE_START_PORT CONTROL_PORT
#endif
#if SAFETY_DOOR_ENABLE && !defined(SAFETY_DOOR_PORT)
#define SAFETY_DOOR_PORT CONTROL_PORT
#endif
#endif

#ifndef RESET_BIT
#ifdef RESET_PIN
#define RESET_BIT       (1<<RESET_PIN)
#else
#define RESET_BIT       0
#endif
#endif

#ifndef FEED_HOLD_BIT
#ifdef FEED_HOLD_PIN
#define FEED_HOLD_BIT   (1<<FEED_HOLD_PIN)
#else
#define FEED_HOLD_BIT   0
#endif
#endif

#ifndef CYCLE_START_BIT
#ifdef CYCLE_START_PIN
#define CYCLE_START_BIT (1<<CYCLE_START_PIN)
#else
#define CYCLE_START_BIT 0
#endif
#endif

#if SAFETY_DOOR_ENABLE && !defined(SAFETY_DOOR_BIT)
#ifdef SAFETY_DOOR_PIN
#define SAFETY_DOOR_BIT (1<<SAFETY_DOOR_PIN)
#else
#define SAFETY_DOOR_BIT 0
#endif
#endif

#ifndef CONTROL_MASK
#if SAFETY_DOOR_ENABLE
#define CONTROL_MASK    (RESET_BIT|FEED_HOLD_BIT|CYCLE_START_BIT|SAFETY_DOOR_BIT)
#else
#define CONTROL_MASK    (RESET_BIT|FEED_HOLD_BIT|CYCLE_START_BIT)
#endif
#endif

#if defined(SPINDLE_ENABLE_PIN) && !defined(SPINDLE_ENABLE_BIT)
#define SPINDLE_ENABLE_BIT      (1<<SPINDLE_ENABLE_PIN)
#endif
#if defined(SPINDLE_DIRECTION_PIN) && !defined(SPINDLE_DIRECTION_BIT)
#define SPINDLE_DIRECTION_BIT   (1<<SPINDLE_DIRECTION_PIN)
#endif

#if defined(COOLANT_FLOOD_PIN) && !defined(COOLANT_FLOOD_BIT)
#define COOLANT_FLOOD_BIT       (1<<COOLANT_FLOOD_PIN)
#endif
#if defined(COOLANT_MIST_PIN) && !defined(COOLANT_MIST_BIT)
#define COOLANT_MIST_BIT        (1<<COOLANT_MIST_PIN)
#endif

#if defined(PROBE_PIN) && !defined(PROBE_BIT)
#define PROBE_BIT               (1<<PROBE_PIN)
#endif

#if defined(I2C_STROBE_PIN) && !defined(I2C_STROBE_BIT)
#define I2C_STROBE_BIT          (1<<I2C_STROBE_PIN)
#endif

#ifndef AUXINPUT_MASK
#define AUXINPUT_MASK 0
#endif

/*EOF*/
