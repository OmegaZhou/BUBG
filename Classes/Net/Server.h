#ifndef BUBG_CLASSES_NET_SERVER_H_
#define BUBG_CLASSES_NET_SERVER_H_

#include <vector>
#include <string>
#include <thread>
#include "NetData.h"
#include <Boost/asio.hpp>
class Server
{
	typedef boost::asio::io_service io_service;
	typedef boost::asio::ip::tcp::endpoint endpoint;
public:
	static Server* getInstance();
	//clear the data when game end;
	void clear();
	//get connect with the clients and add to players_data;
	void connect();
	//get the command from other client;
	void getCommand();
	//send command to client;
	//this function send te command by,command buffer,which is influenced by mutex;
	//should be instead of sendCommand;
	void replayCommand();
	std::vector<std::string> getMessage();
	void sendMessage(std::string);
	void beginWait();
	void endWait();
	void startGame();
	void endGame();
	bool excuteCommand(CommandImformation command);
	std::vector<CommandImformation> getLocalCommand();
	void addNetCommand(CommandImformation coammand);
	//this function send the command directly
	void sendCommand(CommandImformation command);
	void addNetCommand(std::vector<CommandImformation> command);
	const std::vector<Player>& getPlayer() const;
protected:
	Server();
	~Server();
	Server& operator=(const Server& )=delete;
	static int new_id;
	bool is_wait_;
	bool is_in_game_;
	std::vector<Player> players_data_;
	std::vector<CommandImformation> net_command_buffer_;
	std::vector<CommandImformation> local_command_buffer_;
	std::string log_;
	std::mutex net_command_lock_;
	std::mutex local_command_lock_;
	io_service service_;
	endpoint endpoint_;
	endpoint message_endpoint_;
};

#endif // !BUBG_CLASSES_NET_SERVER_H_