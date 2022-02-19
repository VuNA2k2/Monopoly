#include "MatrixCells.h"
#include "PropertyCell.h"
#include "StartCell.h"
#include "TaxCell.h"
#include "BusCell.h"
#include "BonusCell.h"
#include "JailCell.h"
MatrixCells::MatrixCells()
{
}

void MatrixCells::init()
{
	Cell* cell = nullptr;
	cell = new StartCell();
	cell->init();
	cell->setPosition(sf::Vector2f(960, 900));
	cells.push_back(cell);
	for (int i = 1; i < 40; i++) {
		cell = new PropertyCell();
		if (i % 5 == 0 && i % 10 != 0) cell = new TaxCell();
		cell->init();
		if (i == 10) cell = new JailCell();
		if (i == 30) cell = new BusCell();
		cell->init();
		if (i == 20) cell = new BonusCell();
		cell->init();
		if (i < 11) {
			cell->init();
			cell->setPosition(sf::Vector2f(cells.back()->getPosition().x - cells.back()->getSize().x / 2 + 1, cells.back()->getPosition().y - cells.back()->getSize().y / 2 + 1));
		}
		else if (i < 21) {
			cell->init();
			cell->setPosition(sf::Vector2f(cells.back()->getPosition().x + cells.back()->getSize().x / 2 - 1, cells.back()->getPosition().y - cells.back()->getSize().y / 2 + 1));
		}
		else if (i < 31) {
			cell->init();
			cell->setPosition(sf::Vector2f(cells.back()->getPosition().x + cells.back()->getSize().x / 2 - 1, cells.back()->getPosition().y + cells.back()->getSize().y / 2 - 1));
		}
		else {
			cell->init();
			cell->setPosition(sf::Vector2f(cells.back()->getPosition().x - cells.back()->getSize().x / 2 + 1, cells.back()->getPosition().y + cells.back()->getSize().y / 2 - 1));
		}
		if (cell->getCellType() == PROPERTY) {
			if (i % 4 == 0) cell->setColor(red);
			if (i % 4 == 1) cell->setColor(blue);
			if (i % 4 == 2) cell->setColor(yellow);
			if (i % 4 == 3) cell->setColor(green);
		}
		cells.push_back(cell);
	}
}

void MatrixCells::update(float deltaTime)
{
	for (auto it : cells) {
		it->update(deltaTime);
	}
}

void MatrixCells::render(sf::RenderWindow* window)
{
	for (int i = 20; i >= 0; i--) cells[i]->render(window);
	for (int i = 21; i < cells.size(); i++) cells[i]->render(window);
}

void MatrixCells::setPosition(sf::Vector2f position)
{

}

sf::Vector2f MatrixCells::getPositionAtCell(int cellNum)
{
	if (cellNum == -1) cellNum = 39;
	return sf::Vector2f(cells[cellNum]->getPosition());
}

void MatrixCells::setPriceAtCell(int cellNum, int price)
{
	if (cellNum == -1) cellNum = 39;
	cells[cellNum]->setOwner(ONULL, 3);
	cells[cellNum]->setPrice(price);
}

int MatrixCells::getPriceAtCell(int cellNum)
{
	if (cellNum == -1) cellNum = 39;
	return cells[cellNum]->getPrice();
}

void MatrixCells::setOwnerAtCell(int cellNum, OWNER owner,int property)
{
	if (cellNum == -1) cellNum = 39;
	cells[cellNum]->setOwner(owner,property);
}

OWNER MatrixCells::getOwnerAtCell(int cellNum)
{
	if (cellNum == -1) cellNum = 39;
	return cells[cellNum]->getOwner();
}

Cell* MatrixCells::getCell(int cellNum)
{
	if (cellNum == -1) cellNum = 39;
	return cells[cellNum];
}



