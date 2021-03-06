#include "DisconnectBox.h"
#include "Net/Net.h"
#include "HelloWorldScene.h"
USING_NS_CC;

DisconnectBox::~DisconnectBox()
{

}

DisconnectBox * DisconnectBox::createBox(std::string text)
{
	auto box = new DisconnectBox();
	if (box && box->init())
	{
		box->initBox(text);
		box->autorelease();
		return box;
	}
	CC_SAFE_DELETE(box);
	return nullptr;
}

void DisconnectBox::initBox(std::string text)
{
	auto visible_size = Director::getInstance()->getVisibleSize();
	auto label = Label::create(text, "Arial", visible_size.height / 18);
	label->setColor(Color3B(255, 140, 0));
	this->addChild(label);
	label->setPosition(0, visible_size.height / 5);
	auto button = MenuItemImage::create("menu/ok-up.png", "menu/ok-down.png", CC_CALLBACK_1(DisconnectBox::quitGame, this));
	auto menu = Menu::create(button, NULL);
	this->addChild(menu);
	menu->setPosition(0, 0);
}

bool DisconnectBox::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}

void DisconnectBox::quitGame(cocos2d::Object * pSender)
{
	Client::getInstance()->clear();
	auto scene = HelloWorld::create();
	Director::getInstance()->replaceScene(scene);
}
