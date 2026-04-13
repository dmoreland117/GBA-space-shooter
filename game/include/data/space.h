
//{{BLOCK(space)

//======================================================================
//
//	space, 256x256@4, 
//	Transparent color : FF,00,FF
//	+ palette 256 entries, not compressed
//	+ 187 tiles (t|f reduced) not compressed
//	+ regular map (flat), not compressed, 32x32 
//	Total size: 512 + 5984 + 2048 = 8544
//
//	Time-stamp: 2026-04-13, 13:48:52
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SPACE_H
#define GRIT_SPACE_H

#define spaceTilesLen 5984
extern const unsigned short spaceTiles[2992];

#define spaceMapLen 2048
extern const unsigned short spaceMap[1024];

#define spacePalLen 512
extern const unsigned short spacePal[256];

#endif // GRIT_SPACE_H

//}}BLOCK(space)
