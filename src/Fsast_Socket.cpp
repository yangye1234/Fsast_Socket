/*
 * =====================================================================================
 *
 *       Filename:  Fsast_Socket.cpp
 *
 *    Description: 跨平台的客服端和服务端的封装
 *
 *        Version:  1.0
 *        Created:  2025年03月25日 21时20分26秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  YANGYE, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "Fsast_Socket.h"

namespace FS{
	Fsast_Socket* Fsast_Socket::SocketIpv4 = nullptr;
	Fsast_Socket* Fsast_Socket::SocketIpv6 = nullptr;
	//服务端和客户端获取单例函数
	Fsast_Socket* Server_Socket::GetServerSocketIpv4(int port){
		if(Fsast_Socket::SocketIpv4 == nullptr && (system == 0 || system == SERVER)){
			system = SERVER;
			return new Server_Socket(port,IPV4);	
		}
		return Fsast_Socket::SocketIpv4;	
	}
	Fsast_Socket* Server_Socket::GetServerSocketIpv6(int port) {
		if (Fsast_Socket::SocketIpv6 == nullptr && (system == 0 || system == SERVER)) {
			system = SERVER;
			return new Server_Socket(port, IPV6);
		}
		return Fsast_Socket::SocketIpv6;
	}
	Fsast_Socket* Client_Socket::GetClientSocketIpv4(std::string address, int port) {
		if (Fsast_Socket::SocketIpv4 == nullptr && (system == 0 || system == CLIENT)) {
			return new Client_Socket(address, port);
		}
		return Fsast_Socket::SocketIpv4;
	}
	Fsast_Socket* Client_Socket::GetClientSocketIpv6(std::string address, int port) {
		if (Fsast_Socket::SocketIpv6 == nullptr && (system == 0 || system == CLIENT)) {
			return new Client_Socket(address, port);
		}
		return Fsast_Socket::SocketIpv6;
	}
	//构造函数
	Server_Socket::Server_Socket(int& port,IP_MODEL& ipv) {
		Initialize(port,ipv);
	}
	Client_Socket::Client_Socket(std::string& address, int& port, IP_MODEL& ipv) {
		Initialize(address, port, ipv);
	}
	//初始化函数
	bool Server_Socket::Initialize(int& port, IP_MODEL& ipv) {

	}
	bool Client_Socket::Initialize(std::string& address, int& port, IP_MODEL& ipv) {

	}
	//析构函数

	//发送函数

	//接收函数
}
