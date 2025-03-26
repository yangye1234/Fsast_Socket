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
	Fsast_Socket* Server_Socket::GetServerSocketIpv4(int port){
		if(Fsast_Socket::SocketIpv4 == nullptr){
			return new Server_Socket(port,IPV4);	
		}
		return Fsast_Socket::SocketIpv4;	
	}
	Fsast_Socket* Server_Socket::GetServerSocketIpv6(int port) {
		if (Fsast_Socket::SocketIpv6 == nullptr) {
			return new Server_Socket(port, IPV6);
		}
		return Fsast_Socket::SocketIpv6;
	}
}
