#pragma once
#include "Cell.h"
#include "../GameManager/Singleton.h"

#define MC MatrixCells::getInstance()

class MatrixCells : public Singleton<MatrixCells> {
private:
	std::vector<Cell*> cells;
public:
	MatrixCells();

	void init();
	void update(float deltaTime);
	void render(sf::RenderWindow* window);

	void setPosition(sf::Vector2f position);
	sf::Vector2f getPositionAtCell(int cellNum);

	void setPriceAtCell(int cellNum, int price);
	int getPriceAtCell(int cellNum);

	void setOwnerAtCell(int cellNum, OWNER owner, int property);
	OWNER getOwnerAtCell(int cellNum);

	Cell* getCell(int cellNum);
};