#include "BuildDefines.h"

#ifndef __EDITOR_ALL_H
#define __EDITOR_ALL_H

#ifdef JA2EDITOR

#pragma message("GENERATED PCH FOR EDITOR PROJECT.")

//external
#include "types.h"
#include <stdio.h>
#include <windows.h>
#include "Action Items.h"
#include "Button System.h"
#include "debug.h"
#include "english.h"
#include "environment.h"
#include "Exit Grids.h"
#include "font.h"
#include "Font Control.h"
#include "Keys.h"
#include "input.h"
#include "interface.h"
#include "Interface Items.h"
#include "Isometric Utils.h"
#include "interface panels.h"
#include "lighting.h"
#include "Map Information.h"
#include "mousesystem.h"
#include "Overhead.h"
#include "Overhead map.h"
#include "overhead types.h"
#include "pits.h"
#include "random.h"
#include "Render Fun.h"
#include "Render Dirty.h"
#include "renderworld.h"
#include "Simple Render Utils.h"
#include "Soldier Create.h"
#include "Soldier Find.h"
#include "sysutil.h"
#include "Text.h"
#include "Text Input.h"
#include "tiledef.h"
#include "utilities.h"
#include "video.h"
#include "vobject.h"
#include "vobject_blitters.h"
#include "vsurface.h"
#include "wcheck.h"
#include "weapons.h"
#include "wordwrap.h"
#include "WorldDat.h"
#include "worlddef.h"
#include "World Items.h"
#include "worldman.h"
#include "line.h"
#include "Animation Data.h"
#include "Animation Control.h"
#include "Soldier Init List.h"
#include "strategicmap.h"
#include "Soldier Add.h"
#include "Soldier Control.h"
#include "Soldier Profile Type.h"
#include "Soldier Profile.h"
#include "Inventory Choosing.h"
#include "Scheduling.h"
#include "Timer Control.h"
#include "sgp.h"
#include "screenids.h"
#include "sys globals.h"
#include "Interactive Tiles.h"
#include "Handle UI.h"
#include "Event Pump.h"
#include "message.h"
#include "Game Clock.h"
#include "Game Init.h"
#include "Map Edgepoints.h"
#include "Music Control.h"
#include <memory.h>
#include "Item types.h"
#include "Items.h"
#include "Handle Items.h"
#include "Animated ProgressBar.h"
#include "gameloop.h"
#include <stdlib.h>
#include "Structure Internals.h"
#include "cursors.h"
#include "Fileman.h"
#include "Summary Info.h"
#include "time.h"
#include "structure wrap.h"
#include "MessageBoxScreen.h"
#include "GameSettings.h"


//internal
#include "Cursor Modes.h"
#include "edit_sys.h"
#include "Editor Callback Prototypes.h"
#include "Editor Modes.h"
#include "Editor Taskbar Creation.h"
#include "Editor Taskbar Utils.h"
#include "Editor Undo.h"
#include "EditorBuildings.h"
#include "EditorDefines.h"
#include "EditorItems.h"
#include "EditorMapInfo.h"
#include "EditorMercs.h"
#include "EditorTerrain.h"
#include "editscreen.h"
#include "Item Statistics.h"
#include "Loadscreen.h"
#include "messagebox.h"
#include "newsmooth.h"
#include "popupmenu.h"
#include "Road Smoothing.h"
#include "Sector Summary.h"
#include "selectwin.h"
#include "SmartMethod.h"
#include "smooth.h"
#include "Smoothing Utils.h"

#endif

#endif
