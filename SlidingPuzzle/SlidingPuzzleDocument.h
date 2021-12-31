#pragma once

#include "Tile.h"
class CChildView;

enum SlideDirection 
{
	Down,
	Left,
	Right,
	Up
};

class CSlidingPuzzleDocument 
{
	public:
		void Attach(CChildView *pview);
		CTile& GetTile(int row, int col);
		void GetTileFromPoint(const CPoint &point, int *row, int *col);
		void Randomize();
		void Slide(SlideDirection slideDirection);
	private:
		CTile m_tiles[4][4];
		CChildView *m_pview;
		int m_currEmptyTileRowNo;
		int m_currEmptyTileColNo;
};

