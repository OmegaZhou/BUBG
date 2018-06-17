#ifndef BUBG_CLASSES_BALL_CONTROLED_BALL_H_
#define BUBG_CLASSES_BALL_CONTROLED_BALL_H_

#include"BaseBall.h"
#include<string>
#include<list>

class FoodBall;
class ControledBallManager;

class ControledBall : public BaseBall
{
public:
	CREATE_FUNC(ControledBall);
	ControledBall() = default;
	~ControledBall();
	static ControledBall* createControledBall();
	static ControledBall* createControledBall(int score,std::string color_directory);
	static ControledBall* createControledBall(std::string color_directory);

	virtual bool init();
	void initControledBall(int score,std::string color_directory);
	double getSpeed() const;
	//the function return the list of the food which would be swallowed
	//but it does not operate on the food;
	void checkSwallowBall(const std::list<FoodBall*> &food_ball_list);
	//the function return the list of the controled ball which would be swallowed
	//but it does not operate on these ball;
	void checkSwallowBall(const std::list<ControledBall*> &controled_ball_list);
	ControledBallManager* getManager() const;
	void setManager(ControledBallManager* manager);
	void divide();
	void updateState();
	bool isDelete() const;
	std::string getColorDirectory() const;
	void changeDividedState();
	bool isDivided() const;
	void countTime();
	int getTimeCount() const;
	void resetTimeCount();
	//the function is used to get the direction of the ball which is divided;
	cocos2d::Vec2 getDivideDirection() const;
	void setDivideDirection(cocos2d::Vec2 direction);
protected:
	ControledBallManager * manager_;
	double speed_;
	//the list is store the ball will be swallowed;
	std::list<BaseBall*> temp_ball_storage_;
	bool is_delete_;
	std::string color_directory_;
	bool is_divided_;
	int time_count_;
	cocos2d::Vec2 divide_direction_;
};
#endif // !BUBG_CLASSES_BALL_CONTROLED_BALL_H_

