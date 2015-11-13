// IPv4 address lookup
#include <netdb.h>
#include <arpa/inet.h>
#include <iostream>
int main() {
  const char* const host = "www.toolbar.google.com" ;
  const hostent* host_info = 0 ;
  for( int attempt=0 ; (host_info==0) && (attempt<3) ; ++attempt )
    host_info = gethostbyname(host) ;
  if(host_info) {
    std::cout << "host: " << host_info->h_name << '\n' ;
    for( int i=0 ; host_info->h_aliases[i] ; ++i )
      std::cout << " aka: " << host_info->h_aliases[i] << '\n' ;
    for( int i=0 ; host_info->h_addr_list[i] ; ++i )
    {
      const in_addr* address = (in_addr*)host_info->h_addr_list[i] ;
      std::cout << " address: " << inet_ntoa( *address ) << '\n' ;
    }
  }
  else {
  	herror("error");
  }
}