#include "pch.h"
#include <algorithm>
#include "SlidingPuzzleDocument.h"

void CSlidingPuzzleDocument::Attach(CChildView * pview) 
{
	ASSERT(pview != NULL);
	m_pview = pview;
}

CTile & CSlidingPuzzleDocument::GetTile(int row, int col) 
{
	ASSERT(row < 4 && col < 4);
	return m_tiles[row][col];
}

void CSlidingPuzzleDocument::GetTileFromPoint(const CPoint & point, int * rowNo, int * colNo) 
{
	ASSERT(rowNo != NULL);
	ASSERT(colNo != NULL);
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			CRect rect(m_tiles[i][j].tilePos, CSize(CTile::width, CTile::height));
			if (rect.PtInRect(point)) 
			{
				*rowNo = i;
				*colNo = j;
			}
		}
	}
}

void CSlidingPuzzleDocument::Randomize() 
{
	/* Initialize all numbers with 0 */
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			m_tiles[i][j].number = 0;
		}
	}

	int colNo = 0, rowNo = 0;
	for (int i = 1; i <= 15; i++) 
	{
		do 
		{
			rowNo = rand() % 4;
			colNo = rand() % 4;
		} while (m_tiles[rowNo][colNo].number != 0);
		m_tiles[rowNo][colNo].number = i;
	}

	for (rowNo = 0; rowNo < 4; rowNo++) 
	{
		for (colNo = 0; colNo < 4; colNo++) 
		{
			if (m_tiles[rowNo][colNo].number == 0) 
			{
				m_currEmptyTileRowNo = rowNo;
				m_currEmptyTileColNo = colNo;
			}
		}
	}
}

void CSlidingPuzzleDocument::Slide(SlideDirection slideDirection) 
{
	if (m_currEmptyTileRowNo == 0 && slideDirection == Up ||
		m_currEmptyTileRowNo == 3 && slideDirection == Down ||
		m_currEmptyTileColNo == 0 && slideDirection == Left ||
		m_currEmptyTileColNo == 3 && slideDirection == Right)
		return;

	switch (slideDirection) 
	{
		case Down:
			std::swap(m_tiles[m_currEmptyTileRowNo][m_currEmptyTileColNo].number,
				m_tiles[m_currEmptyTileRowNo + 1][m_currEmptyTileColNo].number);
			m_currEmptyTileRowNo = m_currEmptyTileRowNo + 1;
			break;
		case Left:
			std::swap(m_tiles[m_currEmptyTileRowNo][m_currEmptyTileColNo].number,
				m_tiles[m_currEmptyTileRowNo][m_currEmptyTileColNo-1].number);
			m_currEmptyTileColNo = m_currEmptyTileColNo - 1;
			break;
		case Right:
			std::swap(m_tiles[m_currEmptyTileRowNo][m_currEmptyTileColNo].number,
				m_tiles[m_currEmptyTileRowNo][m_currEmptyTileColNo + 1].number);
			m_currEmptyTileColNo = m_currEmptyTileColNo + 1;
			break;
		case Up:
			std::swap(m_tiles[m_currEmptyTileRowNo][m_currEmptyTileColNo].number,
				m_tiles[m_currEmptyTileRowNo - 1][m_currEmptyTileColNo].number);
			m_currEmptyTileRowNo = m_currEmptyTileRowNo - 1;
			break;
	}
}