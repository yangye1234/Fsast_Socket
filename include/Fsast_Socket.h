/*
 * =====================================================================================
 *
 *       Filename:  Fsast_Socket.h
 *
 *    Description: 跨平台的客服端和服务端的封装
 *
 *        Version:  1.0
 *        Created:  2025年03月18日 09时40分38秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  YANGYE
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef FSAST_SOCKET
#define FSAST_SOCKET
#include <iostream>
#ifdef __linux__
	#include <sys/socket.h>
	#include <netinet/in.h>
#elif WIN32
	#include <Windows.h>
	#include <Winsock2.h>
	#include <ws2def.h>
	#include <ws2tcpip.h>
	#include <wsipv6ok.h>
#endif
namespace FS{
	enum IP_MODEL{
		IPV6,
		IPV4
	};
	enum SYSTEM{
		SERVER = 2,
		CLIENT
	};
#ifdef __linux__
	using socket_int = int;
#elif WIN32
	using socket_int = SOCKET;
#endif
	class Fsast_Socket {
	protected:
		Fsast_Socket();
		Fsast_Socket(const Fsast_Socket&) = delete;
		Fsast_Socket& operator=(const Fsast_Socket&) = delete;
		~Fsast_Socket();
		virtual bool Initialize() = 0;//派生类的初始化
	public:
		//派生类的ipv4发送数据
		virtual bool SendIpv4(std::string) = 0;
		//派生类的ipv6发送数据
		virtual bool SendIpv6(std::string) = 0;
		virtual std::string& RecvIpv4() = 0;//派生类ipv4的接收数据
		virtual std::string& RecvIpv6() = 0;//派生类ipv6的接收数据
	public:
		static Fsast_Socket* SocketIpv4;//唯一实例化对象
		static Fsast_Socket* SocketIpv6;//唯一实例化对象
		void deletable();
	protected:
		socket_int server_socketIpv4, client_socketIpv4;//Ipv4套接字
		socket_int server_socketIpv6, client_SocketIpv6;//Ipv6套接字
		int port;
		SYSTEM system = 0;
	};
	class Server_Socket : public Fsast_Socket {
	private:
		Server_Socket(int&, IP_MODEL&);//端口+模式
	protected:
		bool Initialize(int&,IP_MODEL&) final;//服务端的初始化
	public:
		//获取服务端ipv4套接字对象
		static Fsast_Socket* GetServerSocketIpv4(int);
		//获取服务端ipv6套接字对象
		static Fsast_Socket* GetServerSocketIpv6(int);
		//以ipv4进行发送数据
		virtual bool SendIpv4(std::string) override;
		//以ipv6进行发送数据
		virtual bool SendIpv6(std::string) override;
		//以ipv4接收数据
		virtual std::string& RecvIpv4() override;
		//以ipv4接收数据
		virtual std::string& RecvIpv6() override;
	};
	class Client_Socket : public Fsast_Socket {
	private:
		Client_Socket(std::string&, int&, IP_MODEL&);//地址+端口+模式
	protected:
		bool Initialize(std::string&,int&,IP_MODEL&) final;
	public:
		//获取客户端ipv4套接字对象
		static Fsast_Socket* GetClientSocketIpv4(std::string, int);
		//获取客户端ipv6套接字对象
		static Fsast_Socket* GetClientSocketIpv6(std::string, int);
		//以ipv4进行发送数据
		virtual bool SendIpv4(std::string) override;
		//以ipv6进行发送数据
		virtual bool SendIpv6(std::string) override;
		//以ipv4接收数据
		virtual std::string& RecvIpv4() override;
		//以ipv4接收数据
		virtual std::string& RecvIpv6() override;
	};

}

#endif //FSAST_SOCKET
