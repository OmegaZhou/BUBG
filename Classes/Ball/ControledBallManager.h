#ifndef BUBG_CLASSES_BALL_CONTROLED_BALL_MANAGER_H_
#define BUBG_CLASSES_BALL_CONTROLED_BALL_MANAGER_H_

#include "cocos2d.h"
#include <list>

class ControledBall;

class ControledBallManager : public cocos2d::Node
{
protected:
	std::list<ControledBall*> controled_ball_list_;
	double speed_;
	cocos2d::Node* father_;
public:
	//please use it to add child to the scene;
	//Notice: the function only can be used once;
	void addFatherScene(cocos2d::Node* father);
	//the function is used to remove and delete the ball which is uselee;
	void removeBall(ControledBall* ball);
	void updateState();
	//the function is used to make the controled balls run toward target;
	void moveTo(cocos2d::Vec2 target);
	void divideBall();
	static ControledBallManager* createManager();
	CREATE_FUNC(ControledBallManager);
	virtual bool init();
	~ControledBallManager();
	ControledBallManager() = default;
};
#endif // !BUBG_CLASSES_BALL_CONTROLED_BALL_MANAGER_H_
