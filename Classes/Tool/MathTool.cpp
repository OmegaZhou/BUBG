#include "MathTool.h"
#include <cmath>
USING_NS_CC;

double ScoreToSize(unsigned int score)
{
	return Director::getInstance()->getVisibleSize().width / 300 * std::sqrt(score);
}

double calDistence(const cocos2d::Vec2 & i, const cocos2d::Vec2 & j)
{
	return (i.x - j.x)*(i.x - j.x) + (i.y - j.y)*(i.y - j.y);
}

double ScoreToSpeed(int score)
{
	return 2000 / std::pow(score, 0.3);
}

double getDoubleRand(int range)
{
	double x = rand() / static_cast<double>(RAND_MAX);
	double y = rand() % range;
	return x + y;
}
void delay(int seconds)

{

	clock_t start = clock();

	clock_t lay = (clock_t)seconds * CLOCKS_PER_SEC;

	while ((clock() - start) < lay)
	{
		;
	}
}